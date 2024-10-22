/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
// #include "gameModule.hpp"
// #include "networkModule.hpp"
#include "ConfigParser.hpp"
#include <boost/asio.hpp>
#include <signal.h>
#ifdef _WIN32
#include <stdexcept>               // For exception handling
#include <winsock2.h>              // For Windows socket functions
#pragma comment(lib, "Ws2_32.lib") // Link with Ws2_32.lib for Winsock
#else
#include "UUID.hpp"
#include "sys/socket.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/resource.h>
#endif

Server::Server() : MultiThreadElement() {
    _Running = false;
    ConfigParser parser;
    parser.ParseConfig(std::filesystem::current_path().string() + "/server/config/modules.json");
    std::cout << "server name: " << parser.GetServerName() << std::endl;
    for (auto &module : parser.GetModules()) {
        std::cout << "module name: " << module.GetModuleName() << std::endl;
        std::cout << "module path: " << module.GetModulePath() << std::endl;
        for (auto &listen : module.GetModuleListen()) {
            std::cout << "module listen: " << listen << std::endl;
        }
    }
}

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
    serv_addr.sin_port = htons(MODULE_PORT);
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
    ConfigParser parser;
    parser.ParseConfig(std::filesystem::current_path().string() + "/server/config/modules.json");
    std::cout << "server name: " << parser.GetServerName() << std::endl;
    for (auto &module : parser.GetModules()) {
        std::cout << "module name: " << module.GetModuleName() << std::endl;
        std::cout << "module path: " << module.GetModulePath() << std::endl;
        for (auto &listen : module.GetModuleListen()) {
            std::cout << "module listen: " << listen << std::endl;
        }
    }
    /*NetworkModule* networkModule = new NetworkModule("Network Module", "a5dbbeb3-1435-473c-ba3b-36388bb64e8a");
    GameModule* gameModule = new GameModule("Game Module", "f1b4b73f-a9d1-44bc-91c8-bd4d71828fe2");
    networkModule->addCommunicateModule(gameModule->getId());
    gameModule->addCommunicateModule(networkModule->getId());
    createModule(networkModule);
    createModule(gameModule);*/
#ifdef _WIN32
    u_long mode = 1; // 1 to enable non-blocking mode
    ioctlsocket(_modules[0]->getSocket(), FIONBIO, &mode);
    ioctlsocket(_modules[1]->getSocket(), FIONBIO, &mode);
#endif
    std::cout << "Modules created" << std::endl;
}

void Server::run() {
    exit(0);
    std::cout << "Server is running" << std::endl;
    _Running = true;
    fd_set readfds;
    fd_set writefds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    while (_Running) {
        FD_ZERO(&readfds);
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
        for (auto& module: _modules) {
            messages.clear();
            if (!FD_ISSET(module->getSocket(), &readfds))
                continue;
#ifdef _WIN32
            for (int valread = recv(module->getSocket(), buffer, 1024, 0);
                 valread != -1 && valread != 0;
                 valread = recv(module->getSocket(), buffer, 1024, 0)) {
                std::cout << "Read: " << buffer << " from game module"
                          << std::endl;
                messages += buffer;
            }
#else
            for (int valread =
                     recv(module->getSocket(), buffer, 1024, MSG_DONTWAIT);
                 valread != -1 && valread != 0;
                 valread = recv(module->getSocket(), buffer, 1024,
                                MSG_DONTWAIT)) {
                messages += buffer;
            }
            // std::cout << "Message received: " << messages << " from: " << module->getModuleName() << std::endl;
            for (std::string message = messages.substr(0, messages.find(THREAD_END_MESSAGE));
                    messages.find(THREAD_END_MESSAGE) != std::string::npos;
                    messages = messages.substr(messages.find(THREAD_END_MESSAGE) + 2),
                    message = messages.substr(0, messages.find(THREAD_END_MESSAGE))) {
                    message += THREAD_END_MESSAGE;
                for (auto &writeToModule : _modules) {
                    if (FD_ISSET(module->getSocket(), &writefds) && canCommunicateWith(writeToModule->getModule()->getId(), module->getModule()->getId())) {
                        writeToModule->addMessage(message);
                    }
                }
            }
#endif
        }
        for (auto& module : _modules) {
            if (module->getMessages().empty() ||
                !FD_ISSET(module->getSocket(), &writefds))
                continue;
            for (auto& message : module->getMessages()) {
                // std::cout << "Sending message: " << message
                //           << "to module: " << module->getModuleName()
                //           << std::endl;
                send(module->getSocket(), message.c_str(), message.size(), 0);
            }
            module->clearMessages();
        }
    }
}

void Server::stop() {
    if (!_Running)
        return;
    std::cout << "Stopping the server" << std::endl;
    std::cout << "Send shutdown server message to all clients" << std::endl;
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
        if (moduleSocket == INVALID_SOCKET) {
            throw std::runtime_error(
                "Error while creating a module: accept failed");
        }
#else
        int moduleSocket = accept(_socket, (struct sockaddr*)NULL, NULL);
        if (moduleSocket < 0) {
            throw std::runtime_error(
                "Error while creating a module: accept failed");
        }
        if (moduleSocket > _maxSocket) {
            _maxSocket = moduleSocket;
        }
#endif
        if (send(moduleSocket, "200\n\t", 5, 0) < 0) {
            throw std::runtime_error(
                "Error while creating a module: send failed");
        }
        char buffer[1024] = {0};
        int valread = recv(moduleSocket, buffer, 1024, 0);
        if (valread < 0 || valread != 5) {
            throw std::runtime_error(
                "Error while creating a module: recv failed");
        }
        std::string message = buffer;
        if (message != "200\n\t") {
            throw std::runtime_error(
                "Error while creating a module: wrong message received");
        }
        _modules.push_back(
            std::make_unique<serverModule>(module, moduleSocket));
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw std::runtime_error(
            "Error while creating a module: module not connected");
    }
}

bool Server::canCommunicateWith(std::string moduleId,
                                std::string communicateModuleId) {
    if (moduleId == communicateModuleId) {
        return false;
    }
    for (auto& module : _modules) {
        if (module->getModule()->getId() == moduleId) {
            for (auto& communicateModule : module->getModule()->getCommunicatesModules()) {
                if (communicateModule == communicateModuleId)
                    return true;
            }
        }
    }
    return false;
}
