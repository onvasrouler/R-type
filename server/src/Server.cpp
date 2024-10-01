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
#include <cassert>                 // For assert
#include <stdexcept>               // For exception handling
#include <winsock2.h>              // For Windows socket functions
#pragma comment(lib, "Ws2_32.lib") // Link with Ws2_32.lib for Winsock
#else
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
    GameModule* gameModule = new GameModule("GameModule");
    NetworkModule* networkModule = new NetworkModule("NetworkModule");
    createModule(gameModule);
    createModule(networkModule);
    std::cout << "Modules created" << std::endl;
}

void Server::run() {
    _Running = true;
    std::cout << "Server is running" << std::endl;
    while (_Running) {
        //check the messages from other modules
        // send the messages to the correct modules
    }
}

void Server::stop() {
    if (!_Running)
        return;
    std::cout << "Stopping the server" << std::endl;
    for (auto& module : _modules) {
        module->stop();
    }
    _Running = false;
    std::cout << "Server stopped" << std::endl;
}

std::string Server::decodeInterCommunication(std::string message) {
    // decode the message
}

std::string Server::encodeInterCommunication(std::string message) {
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
