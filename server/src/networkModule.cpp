/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "networkModule.hpp"

NetworkModule::NetworkModule(std::string name) : AbstractModule(name) {
    try {
        _udpServer = std::make_unique<UDPServer>(_io_context, PORT);
    } catch (std::exception& e) {
        std::throw_with_nested(
            std::runtime_error("Error while creating the UDP server"));
    }
    _Running = true;
}

NetworkModule::~NetworkModule() {
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    if (_Running) {
        stop();
    }
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
    // kill udp server
}

void NetworkModule::start() {
    _Running = true;
    _thread = std::thread(
        [this](void* _) -> void* {
            std::cout << "Starting module: " << _ModuleName << std::endl;
            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(
                PORT); // Utilisez le même port que celui défini dans le serveur
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
        int ret = select(_socket + 1, &readfds, &writefds, NULL, &tv);
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
                std::string message = data.getIp() + ":" +
                                      std::to_string(data.getPort()) + "/" +
                                      data.getData() + THREAD_END_MESSAGE;
                send(_socket, message.c_str(), message.size(), 0);
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
        for (int valread = recv(_socket, buffer, 1024, 0);
             valread != -1 && valread != 0;
             valread = recv(_socket, buffer, 1024, 0)) {
            messages += buffer;
        }
        _udpServer->getSendMutex().lock();
        for (std::string message = "";
             messages.find(THREAD_END_MESSAGE) != std::string::npos;
             message = messages.substr(0, messages.find(THREAD_END_MESSAGE)),
                         messages = messages.substr(
                             messages.find(THREAD_END_MESSAGE) + 2)) {
            // encode message and send to the clients
            std::string ip = message.substr(0, message.find(":"));
            message = message.substr(message.find(":") + 1);
            short port = std::stoi(message.substr(0, message.find("/")));
            message = message.substr(message.find("/") + 1);
            packageData data = packageData(message, ip, port);
            _sentData.push_back(data);
        }
        _udpServer->getSendMutex().unlock();
    }
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

void NetworkModule::stop() {
    if (!_Running)
        return;
    _Running = false;
#ifdef _WIN32
    closesocket(_socket);
    WSACleanup();
#else
    close(_socket);
#endif
    // stop udp server
    std::cout << "Stopping module: " << _ModuleName << std::endl;
    std::cout << "Module: " << _ModuleName << " is stopping the UDP server"
              << std::endl;
    _udpServer->getSendMutex().unlock();
    _udpServer->getReceiveMutex().unlock();
    _udpServer->stop();
    _io_context.stop();
    _udpThread.join();
    std::cout << "Module: " << _ModuleName << " has stopped the UDP server"
              << std::endl;
    _thread.join();
    std::cout << "Module: " << _ModuleName << " is stopped" << std::endl;
}

std::string NetworkModule::decodeInterCommunication(std::string message) {
    return message;
}

std::string NetworkModule::encodeInterCommunication(std::string message) {
    return message;
}
