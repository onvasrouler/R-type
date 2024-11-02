/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "networkModule.hpp"

NetworkModule::NetworkModule(const std::string name, const std::string id) : AbstractModule(name, id) {
    try {
        _udpServer = std::make_unique<UDPServer>(_io_context, PORT);
    } catch (std::exception& e) {
        std::throw_with_nested(
            std::runtime_error("Error while creating the UDP server"));
    }
    _Running = true;
    std::cout << "Module: " << _ModuleName << " created" << std::endl;
}

NetworkModule::~NetworkModule() {
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    if (_Running) {
        stop();
    }
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
    _udpServer.reset();
}

#ifdef _WIN32
#else
static std::string exec(const char* cmd) {
    // Open a pipe to the command
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output from the command
    char buffer[128];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result += buffer;
    }

    return result;
}
#endif

void NetworkModule::start() {
    // open port 8081
    #ifndef _WIN32
        std::string firewallOpen =
            exec("sudo firewall-cmd --zone=public --add-port=8081/udp --permanent");
        std::string firewallReload = exec("sudo firewall-cmd --reload");
        std::cout << "Firewall open: " << firewallOpen << std::endl;
        std::cout << "Firewall reload: " << firewallReload << std::endl;
        // if find succes in the 2 strings
        if (firewallOpen.find("success") == std::string::npos ||
            firewallReload.find("success") == std::string::npos) {
            std::throw_with_nested(
                std::runtime_error("Error: firewall open failed"));
        }
    #endif
    _Running = true;
    _thread = std::thread(
        [this](void* _) -> void* {
            std::cout << "Starting module: " << _ModuleName << std::endl;
            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port =
                htons(MODULE_PORT); // Utilisez le même port que celui défini
                                    // dans le serveur
            server_addr.sin_addr.s_addr = INADDR_ANY; // Adresse IP locale
            inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
            int serverSocket = connect(_socket, (struct sockaddr*)&server_addr,
                                       sizeof(server_addr));

            if (serverSocket == -1) {
                std::throw_with_nested(
                    std::runtime_error("Error: connection failed"));
            }
            _otherModules.push_back(serverSocket);
            char buffer[1024] = {0};
            int valread = recv(_socket, buffer, 1024, 0);
            if (valread == -1) {
                std::throw_with_nested(
                    std::runtime_error("Error: reading failed"));
            }
            std::string message = buffer;
            if (message != "200\n\t") {
                std::throw_with_nested(
                    std::runtime_error("Error: connection failed"));
            }
#ifdef _WIN32
            Sleep(2000);
#else
            sleep(2);
#endif
            send(_socket, "200\n\t", 5, 0);
            std::cout << "Module: " << _ModuleName << " started" << std::endl;
            _Running = true;
            _udpThread = std::thread([this]() -> void* {
                _io_context.run();
                return nullptr;
            });
#ifdef _WIN32
            u_long mode = 1; // 1 to enable non-blocking mode
            ioctlsocket(_socket, FIONBIO, &mode);
#endif
            run();
            return nullptr;
        },
        nullptr);
}

void NetworkModule::run() {
    std::cout << "Module: " << _ModuleName << " is running" << std::endl;
    fd_set readfds;
    fd_set writefds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    while (_Running) {
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_SET(_socket, &readfds);
        FD_SET(_socket, &writefds);
#ifdef _WIN32
        int ret = select(0, &readfds, &writefds, NULL, &tv);
#else
        int ret = select(_socket + 1, &readfds, &writefds, NULL, &tv);
#endif
        if (ret == -1) {
            std::throw_with_nested(std::runtime_error("Error: select failed"));
        }
        if (ret == 0) {
            continue;
        }
        // check received messages
        if (FD_ISSET(_socket, &writefds)) {
            _udpServer->getReceiveMutex().lock();
            for (auto& data : _udpServer->getReceivedData()) {
                std::string message = data.getData() + THREAD_END_MESSAGE;
                if (isClient(data.getIp(), data.getPort())) {
                } else {
                    uuid userUUID;
                    std::string userID = userUUID.toString();
                    Client newClient(data.getIp(), data.getPort(), userID);
                    _clients.push_back(newClient);
                }
                std::string messageToSend = createMessage(data.getIp(), data.getPort(), message);
                std::cout << "Module: " << _ModuleName << " send to core: " << messageToSend << std::endl;
                send(_socket, messageToSend.c_str(), messageToSend.size(), 0);
            }
            _udpServer->getReceivedData().clear();
            _udpServer->getReceiveMutex().unlock();
        }

        if (!FD_ISSET(_socket, &readfds)) {
            continue;
        }
        // read core messages while their is nothing
        char buffer[1024] = {0};
        std::string messages = "";
#ifdef _WIN32
        for (int valread = recv(_socket, buffer, 1024, 0);
             valread != -1 && valread != 0;
             valread = recv(_socket, buffer, 1024, 0)) {
            messages += buffer;
        }
#else
        for (int valread = recv(_socket, buffer, 1024, MSG_DONTWAIT);
             valread != -1 && valread != 0;
             valread = recv(_socket, buffer, 1024, MSG_DONTWAIT)) {
            messages += buffer;
        }
#endif
        _udpServer->getSendMutex().lock();
        for (std::string message =
                 messages.substr(0, messages.find(THREAD_END_MESSAGE));
             messages.find(THREAD_END_MESSAGE) != std::string::npos;
             message = messages.substr(0, messages.find(THREAD_END_MESSAGE)),
                         messages = messages.substr(
                             messages.find(THREAD_END_MESSAGE) + 2)) {
            try {
                std::cout << "Module: " << _ModuleName << " received: " << message << " from core"
                          << std::endl;
                // encode message and send to the clients
                std::string uuid = message.substr(0, message.find(":"));
                std::cout << uuid << std::endl;
                std::string messageData = message.substr(message.find(":") + 1);
                std::cout << messageData << std::endl;
                packageData data = createPackageData(uuid, messageData);
                _udpServer->getSentData().push_back(data);
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                continue;
            }
        }
        _udpServer->getSendMutex().unlock();
        _udpServer->sendMessages();
    }
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

void NetworkModule::stop() {
    if (!_Running)
        return;
    _Running = false;
        _udpServer->getSendMutex().lock();
    for (auto& client : _clients) {
        std::string message = std::string(SHUTDOWN_MESSAGE) + std::string(END_MESSAGE_CODE);
        _udpServer->getSentData().push_back(packageData(message, client.getIp(), client.getPort()));
    }
    _udpServer->getSendMutex().unlock();
    _udpServer->sendMessages();
    _udpServer->getStopMutex().lock();
#ifdef _WIN32
    closesocket(_socket);
    WSACleanup();
#else
    std::cout << "close socket" << std::endl;
    close(_socket);
#endif
    std::cout << "Stopping module: " << _ModuleName << std::endl;
    std::cout << "Module: " << _ModuleName << " is stopping the UDP server"
              << std::endl;
    // if the mutex is lock
    if (_udpServer->getSendMutex().try_lock()) {
        _udpServer->getSendMutex().unlock();
    }
    if (_udpServer->getReceiveMutex().try_lock()) {
        _udpServer->getReceiveMutex().unlock();
    }
    _udpServer->stop();
    _udpServer->getStopMutex().unlock();
    _io_context.stop();
    _udpThread.join();
    std::cout << "Module: " << _ModuleName << " has stopped the UDP server"
              << std::endl;
    _thread.join();
    std::cout << "Module: " << _ModuleName << " is stopped" << std::endl;
}

std::string NetworkModule::decodeInterCommunication(const std::string message) {
    return message;
}

std::string NetworkModule::encodeInterCommunication(const std::string message) {
    return message;
}

bool NetworkModule::isClient(const std::string ip, const std::size_t port) {
    for (auto& client : _clients) {
        if (client.getIp() == ip && client.getPort() == port)
            return true;
    }
    return false;
}

std::string NetworkModule::createMessage(const std::string ip, const std::size_t port,
                                  const std::string message) {
    Client client = findClient(ip, port);
    std::string messageToSend =
        client.getUuid() + ":" + message + THREAD_END_MESSAGE;
    return messageToSend;
}

packageData NetworkModule::createPackageData(const std::string uuid, const std::string message) {
    packageData data("", "", 0);
    for (auto& c : _clients) {
        if (c.getUuid() == uuid) {
            return packageData(message, c.getIp(), c.getPort());
        }
    }
    return data;
}

Client NetworkModule::findClient(const std::string ip, const std::size_t port) {
    Client client;
    for (auto& c : _clients) {
        if (c.getIp() == ip && c.getPort() == port) {
            return c;
        }
    }
    return client;
}

Client NetworkModule::findClient(const std::string uuid) {
    Client client;
    for (auto& c : _clients) {
        if (c.getUuid() == uuid) {
            return c;
        }
    }
    return client;
}

#ifdef _WIN32
    extern "C" {
        __declspec(dllexport) AbstractModule* create_module(const std::string name, const std::string id) {
            return new NetworkModule(name, id);
        }
    }
#else
    extern "C" {
        AbstractModule* create_module(const std::string name, const std::string id) {
            return new NetworkModule(name, id);
        }
    }
#endif
