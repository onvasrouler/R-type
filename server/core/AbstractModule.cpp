/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AbstractModule.hpp"
#include "sys/socket.h"
#include "netinet/in.h"
#include <arpa/inet.h>
#include <unistd.h>

AbstractModule::AbstractModule() : MultiThreadElement()
{
    _Running = false;
}

AbstractModule::AbstractModule(const int serverInterSocket) : MultiThreadElement(serverInterSocket)
{
    _Running = false;
}

AbstractModule::~AbstractModule()
{
    if (_Running)
        stop();
}

void AbstractModule::start()
{
    _Running = true;
    // _thread.start([this](void *_) -> void * {
    _thread = std::thread([this](void *_) -> void * {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8080);  // Utilisez le même port que celui défini dans le serveur
        server_addr.sin_addr.s_addr = INADDR_ANY;  // Adresse IP locale
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
        int connectVal = connect(_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (connectVal == -1) {
            std::throw_with_nested(std::runtime_error("Error: connection failed"));
        }
        char buffer[1024] = {0};
        int valread = recv(_socket, buffer, 1024, 0);
        if (valread == -1) {
            std::throw_with_nested(std::runtime_error("Error: reading failed"));
        }
        std::string message = buffer;
        if (message != "200\n\t") {
            std::throw_with_nested(std::runtime_error("Error: connection failed"));
        }
        sleep(2);
        send(_socket, "200\n\t", 5, 0);
        std::cout << "Connection established" << std::endl;
        run();
        return nullptr;
    }, nullptr);
}

void AbstractModule::run()
{
    std::cout << "running" << std::endl;
    while (_Running) {
    }
    std::cout << "stopped" << std::endl;
}

void AbstractModule::stop()
{
    _Running = false;
    close(_socket);
    _thread.join();
}

void AbstractModule::decodeInterCommunication(std::string message)
{
    std::cout << "Decoding message: " << message << std::endl;
}

void AbstractModule::encodeInterCommunication(std::string message)
{
    std::cout << "Encoding message: " << message << std::endl;
}
