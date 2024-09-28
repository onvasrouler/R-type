/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AbstractModule.hpp"
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib") // Lien avec la bibliothèque WS2_32.lib
#else
    #include "sys/socket.h"
    #include "netinet/in.h"
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

AbstractModule::AbstractModule() : MultiThreadElement()
{
    _Running = false;
}

#ifdef _WIN32
    AbstractModule::AbstractModule(const SOCKET serverInterSocket) : MultiThreadElement(serverInterSocket) {
        _Running = false;
    }
#else
    AbstractModule::AbstractModule(const int serverInterSocket) : MultiThreadElement(serverInterSocket) {
        _Running = false;
    }
#endif

AbstractModule::~AbstractModule()
{
    if (_Running)
        stop();
}

void AbstractModule::start()
{
    _Running = true;
    _thread = std::thread([this](void *_) -> void * {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);  // Utilisez le même port que celui défini dans le serveur
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
        #ifdef _WIN32
            Sleep(2000);
        #else
            sleep(2);
        #endif
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
    #ifdef _WIN32
        closesocket(_socket);
        WSACleanup();
    #else
        close(_socket);
    #endif
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
