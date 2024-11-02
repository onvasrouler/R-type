/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AbstractModule.hpp"

AbstractModule::AbstractModule() : MultiThreadElement()
{
    _Running = false;
}

AbstractModule::AbstractModule(const std::string name) : MultiThreadElement()
{
    _ModuleName = name;
    _Running = false;
}

AbstractModule::~AbstractModule()
{
    try {
        _thread.join();
    } catch (const std::exception &e) {
        std::cerr << "Failed to join thread: " << e.what() << std::endl;
    }
    if (_Running)
        stop();
}

void AbstractModule::start()
{
    std::cout << "test" << std::endl;
    _Running = true;
    _thread = std::thread([this](void *_) -> void * {
        std::cout << "ok" << std::endl;
        std::cout << "Starting module: " << _ModuleName << std::endl;
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(MODULE_PORT);  // Utilisez le même port que celui défini dans le serveur
        server_addr.sin_addr.s_addr = INADDR_ANY;  // Adresse IP locale
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
        std::cout << "Module: " << _ModuleName << " connecting to server" << std::endl;
        int serverSocket = connect(_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (serverSocket == -1) {
            std::throw_with_nested(std::runtime_error("Error: connection failed to server"));
        }
        std::cout << "Module: " << _ModuleName << " connected to server" << std::endl;
        _otherModules.push_back(serverSocket);
        char buffer[1024] = {0};
        int valread = recv(_socket, buffer, 1024, 0);
        if (valread == -1) {
            std::throw_with_nested(std::runtime_error("Error: reading failed"));
        }
        std::cout << "Module: " << _ModuleName << " received message: " << buffer << std::endl;
        std::string message = buffer;
        if (message != "200\n\t") {
            std::throw_with_nested(std::runtime_error("Error: connection failed wrong message: " + message));
        }
        #ifdef _WIN32
            Sleep(2000);
        #else
            sleep(2);
        #endif
        send(_socket, "200\n\t", 5, 0);
        std::cout << "Module: " << _ModuleName << " started" << std::endl;
        #ifdef _WIN32
            u_long mode = 1; // 1 to enable non-blocking mode
            ioctlsocket(_socket, FIONBIO, &mode);
        #endif
        _Running = true;
        run();
        return nullptr;
    }, nullptr);
}

void AbstractModule::run()
{
    std::cout << "Module: " << _ModuleName << " is running" << std::endl;
    while (_Running) {
    }
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

void AbstractModule::stop()
{
    if (!_Running)
        return;
    _Running = false;
    #ifdef _WIN32
        closesocket(_socket);
        WSACleanup();
    #else
        close(_socket);
    #endif
    std::cout << "Stopping module: " << _ModuleName << std::endl;
    _thread.join();
    std::cout << "Module: " << _ModuleName << " is stopped" << std::endl;
}

std::string AbstractModule::getName() const
{
    return _ModuleName;
}

std::string AbstractModule::decodeInterCommunication(const std::string message)
{
    std::cout << "Decoding message: " << message << std::endl;
    return message;
}

std::string AbstractModule::encodeInterCommunication(const std::string message)
{
    std::cout << "Encoding message: " << message << std::endl;
    return message;
}
