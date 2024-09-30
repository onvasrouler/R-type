/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include "gameModule.hpp"
#include "sendModule.hpp"
#include "readModule.hpp"
#include <unistd.h>
#include <signal.h>
#ifdef _WIN32
    #include <winsock2.h>  // For Windows socket functions
    #include <stdexcept>   // For exception handling
    #include <cassert>     // For assert
    #pragma comment(lib, "Ws2_32.lib")  // Link with Ws2_32.lib for Winsock
#else
    #include <sys/resource.h>
    #include <netinet/in.h>
    #include "sys/socket.h"
    #include <arpa/inet.h>
#endif

Server::Server() : MultiThreadElement()
{
    _Running = false;
}

Server::~Server()
{
    std::cout << "Deleting server" << std::endl;
    if (_Running)
        stop();
    std::cout << "Deleting the modules" << std::endl;
    for (auto &module : _modules) {
        module->~serverModule();
    }
    std::cout << "Modules deleted" << std::endl;
    std::cout << "Server deleted" << std::endl;
}

void Server::start()
{
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    int binded = bind(_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
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
    //create all the modules
    std::cout << "Creating modules" << std::endl;
    GameModule *gameModule = new GameModule("GameModule");
    SendModule *sendModule = new SendModule("SendModule");
    ReadModule *readModule = new ReadModule("ReadModule");
    createModule(gameModule);
    createModule(sendModule);
    createModule(readModule);
    std::cout << "Modules created" << std::endl;
}

void Server::run()
{
    _Running = true;
    std::cout << "Server is running" << std::endl;
    while (_Running) {
        //first check the new connections
        //if there is a new connection, sending the informations to the concerned modules
        //then check the messages from the modules
        //if there is a message, sending the informations to the concerned modules
    }
}

void Server::stop()
{
    if (!_Running)
        return;
    std::cout << "Stopping the server" << std::endl;
    for (auto &module : _modules) {
        module->stop();
    }
    _Running = false;
    std::cout << "Server stopped" << std::endl;
}

void Server::decodeInterCommunication(std::string message)
{
    //decode the message
}

void Server::encodeInterCommunication(std::string message)
{
    //encode the message
}

void Server::createModule(AbstractModule *module)
{
    try {
        module->start();
        int moduleSocket = accept(_socket, (struct sockaddr *)NULL, NULL);
        if (moduleSocket < 0)
            throw std::runtime_error("Error while creating a module: accept failed");
        if (send(moduleSocket, "200\n\t", 5, 0) < 0)
            throw std::runtime_error("Error while creating a module: send failed");
        char buffer[1024] = {0};
        int valread = recv(moduleSocket, buffer, 1024, 0);
        if (valread < 0 || valread != 5)
            throw std::runtime_error("Error while creating a module: recv failed");
        std::string message = buffer;
        if (message != "200\n\t")
            throw std::runtime_error("Error while creating a module: wrong message received");
        _modules.push_back(std::make_unique<serverModule>(module, moduleSocket));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::runtime_error("Error while creating a module: module not connected");
    }
}
