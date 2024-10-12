/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include "gameModule.hpp"
#include "networkModule.hpp"
#include <boost/asio.hpp>
#include <signal.h>
#ifdef _WIN32
#include <stdexcept>               // For exception handling
#include <winsock2.h>              // For Windows socket functions
#pragma comment(lib, "Ws2_32.lib") // Link with Ws2_32.lib for Winsock
#else
#include "../lib/UUID.hpp"
#include "sys/socket.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/resource.h>
#endif

Server::Server() : MultiThreadElement() { _Running = false; }

Server::~Server() {
    std::cout << "Deleting server" << std::endl;
    if (_Running)
        stop();
    std::cout << "Deleting the modules" << std::endl;
    for (auto& module : _modules) {
        module->~serverModule();
    }
    std::cout << "Modules deleted" << std::endl;
    std::cout << "Server deleted" << std::endl;
}

void Server::start() {
    std::cout << "Starting the server" << std::endl;
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    int binded = bind(_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    _maxSocket = _socket;
#ifdef _WIN32
    if (binded < 0) {
        std::cout << WSAGetLastError() << std::endl;
        throw std::runtime_error("Error while binding the socket");
    }
#else
    if (binded < 0) {
        std::cout << "Error while binding the socket" << std::endl;
        throw std::runtime_error("Error while binding the socket");
    }
#endif
    int listenSock = listen(_socket, 3);
    if (listenSock < 0) {
        std::cout << "Error while listening the socket" << std::endl;
        throw std::runtime_error("Error while listening the socket");
    }
    // create all the modules
    std::cout << "Creating modules" << std::endl;
    // NetworkModule* networkModule = new NetworkModule("NetworkModule");
    // createModule(networkModule);
    GameModule* gameModule = new GameModule("GameModule");
    createModule(gameModule);
#ifdef _WIN32
    u_long mode = 1; // 1 to enable non-blocking mode
    ioctlsocket(_modules[0]->getSocket(), FIONBIO, &mode);
    ioctlsocket(_modules[1]->getSocket(), FIONBIO, &mode);
#endif
    std::cout << "Modules created" << std::endl;
}

void Server::run() {
    std::cout << "Server is running" << std::endl;
    _Running = true;
    fd_set readfds;
    fd_set writefds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    while (_Running) {
        /*FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        for (auto& module : _modules) {
            FD_SET(module->getSocket(), &readfds);
            FD_SET(module->getSocket(), &writefds);
        }
#ifdef _WIN32
        int ret = select(0, &readfds, &writefds, NULL, &tv);
#else
        int ret = select(_maxSocket + 1, &readfds, &writefds, NULL, &tv);
#endif
        if (ret == -1) {
            std::throw_with_nested(std::runtime_error("Error: select failed"));
        }
        if (ret == 0) {
            continue;
        }
        char buffer[1024] = {0};
        std::string messages = "";
        if (FD_ISSET(_modules[0]->getSocket(), &readfds)) {
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
        }
        for (auto& module : _modules) {
            if (!module->getMessages().empty() &&
                FD_ISSET(module->getSocket(), &writefds)) {
                for (auto& message : module->getMessages()) {
                    std::cout << "Sending message: " << message << std::endl;
                    send(module->getSocket(), message.c_str(), message.size(),
                         0);
                }
                module->clearMessages();
            }
        }
        std::string message =
            messages.substr(0, messages.find(THREAD_END_MESSAGE));
        for (; messages.find(THREAD_END_MESSAGE) != std::string::npos;
             message = messages.substr(0, messages.find(THREAD_END_MESSAGE)),
             messages =
                 messages.substr(messages.find(THREAD_END_MESSAGE) + 2)) {
            // get ip and port
            std::cout << "message: " << message << std::endl;
            std::string ip = message.substr(0, message.find(":"));
            message = message.substr(message.find(":") + 1);
            std::size_t port = std::stoi(message.substr(0, message.find("/")));
            message = message.substr(message.find("/") + 1);
            if (isClient(ip, port)) {
                std::string messageToSend = createMessage(ip, port, message);
                _modules[1]->addMessage(messageToSend);
            } else {
                uuid userUUID;
                std::string userID = userUUID.toString();
                Client newClient(ip, port, userUUID);
                _clients.push_back(newClient);
                std::string messageToSend = createMessage(ip, port, message);
                _modules[1]->addMessage(messageToSend);
            }
        }
        continue;
        messages.clear();
        if (FD_ISSET(_modules[1]->getSocket(), &readfds)) {
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
            message = messages.substr(0, messages.find(THREAD_END_MESSAGE));
            for (; messages.find(THREAD_END_MESSAGE) != std::string::npos;
                 message =
                     messages.substr(0, messages.find(THREAD_END_MESSAGE)),
                 messages =
                     messages.substr(messages.find(THREAD_END_MESSAGE) + 2)) {
                // get uuid and message
                std::string uuidString = message.substr(0, message.find("/"));
                message = message.substr(message.find("/") + 1);
                // send the message to the client
                uuid uuid(uuidString);
                // Client client = findClient(uuid);
                std::string messageToSend =
                    findClient(uuid).getIp() + ":" +
                    std::to_string(findClient(uuid).getPort()) + "/" + message +
                    THREAD_END_MESSAGE;
                _modules[0]->addMessage(messageToSend);
            }
            for (auto& module : _modules) {
                if (module->getMessages().empty() ||
                    !FD_ISSET(module->getSocket(), &writefds))
                    continue;
                for (auto& message : module->getMessages()) {
                    send(module->getSocket(), message.c_str(), message.size(),
                         0);
                }
                module->clearMessages();
            }
        }*/
    }
}

void Server::stop() {
    if (!_Running)
        return;
    std::cout << "Stopping the server" << std::endl;
    std::cout << "Send shutdown server message to all clients" << std::endl;
    for (auto& client : _clients) {
        std::string message = client.getIp() + ":" +
                              std::to_string(client.getPort()) + "/" +
                              SHUTDOWN_MESSAGE + THREAD_END_MESSAGE;
        send(_modules[0]->getSocket(), message.c_str(), message.size(), 0);
    }
    for (auto& module : _modules) {
        module->stop();
    }
    _Running = false;
    std::cout << "Server stopped" << std::endl;
}

std::string Server::decodeInterCommunication(const std::string message) {
    return "";
    // decode the message
}

std::string Server::encodeInterCommunication(const std::string message) {
    return "";
    // encode the message
}

void Server::createModule(AbstractModule* module) {
    try {
        module->start();
#ifdef _WIN32
        SOCKET moduleSocket = accept(_socket, (struct sockaddr*)NULL, NULL);
        if (moduleSocket == INVALID_SOCKET)
            throw std::runtime_error(
                "Error while creating a module: accept failed");
#else
        int moduleSocket = accept(_socket, (struct sockaddr*)NULL, NULL);
        if (moduleSocket < 0)
            throw std::runtime_error(
                "Error while creating a module: accept failed");
        if (moduleSocket > _maxSocket)
            _maxSocket = moduleSocket;
#endif
        if (send(moduleSocket, "200\n\t", 5, 0) < 0)
            throw std::runtime_error(
                "Error while creating a module: send failed");
        char buffer[1024] = {0};
        int valread = recv(moduleSocket, buffer, 1024, 0);
        if (valread < 0 || valread != 5)
            throw std::runtime_error(
                "Error while creating a module: recv failed");
        std::string message = buffer;
        if (message != "200\n\t")
            throw std::runtime_error(
                "Error while creating a module: wrong message received");
        _modules.push_back(
            std::make_unique<serverModule>(module, moduleSocket));
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw std::runtime_error(
            "Error while creating a module: module not connected");
    }
}

bool Server::isClient(const std::string ip, const std::size_t port) {
    for (auto& client : _clients) {
        if (client.getIp() == ip && client.getPort() == port)
            return true;
    }
    return false;
}

std::string Server::createMessage(const std::string ip, const std::size_t port,
                                  const std::string message) {
    Client client = findClient(ip, port);
    std::string messageToSend =
        client.getUuid().toString() + ":" + message + THREAD_END_MESSAGE;
    return messageToSend;
}

Client Server::findClient(const std::string ip, const std::size_t port) {
    Client client;
    for (auto& c : _clients) {
        if (c.getIp() == ip && c.getPort() == port)
            client = c;
    }
    return client;
}

Client Server::findClient(const uuid uuid) {
    Client client;
    for (auto& c : _clients) {
        if (c.getUuid() == uuid)
            client = c;
    }
    return client;
}
