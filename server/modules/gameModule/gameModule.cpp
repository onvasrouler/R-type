/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "gameModule.hpp"

GameModule::GameModule(const std::string name, const std::string id)
    : AbstractModule(name, id), _game(Game()) {
    _Running = false;
    std::cout << "Module: " << _ModuleName << " created" << std::endl;
}

GameModule::~GameModule() {
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    if (_Running) {
        stop();
    }
    // destroy game engine
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
}

std::string GameModule::encodeInterCommunication(const std::string message) {
    std::string encodedMessage = message;
    return message;
    // Encode message
    // Send message
    // send(serverInterSocket, encodedMessage.c_str(), encodedMessage.size(),
    // 0);
}

std::string GameModule::decodeInterCommunication(const std::string message) {
    std::string decodedMessage = message;
    return message;
    // Decode message
    // Do something with the message
}

void GameModule::run() {
    _game.start();
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
            _game.getSendMutex().lock();
            for (auto& data : _game.getSendMessages()) {
                std::string message =
                    data.getId() + ":" + data.getMessage() + THREAD_END_MESSAGE;
                std::cout << "Module: " << _ModuleName << " send to core: " << message << std::endl;
                send(_socket, message.c_str(), message.size(), 0);
            }
            _game.getSendMessages().clear();
            _game.getSendMutex().unlock();
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
        std::cout << "Module: " << _ModuleName << " message received: " << messages << " from core" << std::endl;
        _game.getReadMutex().lock();
        for (std::string message = messages.substr(0, messages.find(THREAD_END_MESSAGE));
            messages.find(THREAD_END_MESSAGE) != std::string::npos;
            messages = messages.substr(messages.find(THREAD_END_MESSAGE) + 2),
            message = messages.substr(0, messages.find(THREAD_END_MESSAGE))) {
            // encode message and send to the clients
            std::string id = message.substr(0, message.find(":"));
            uuid uuid(id);
            message = message.substr(
                message.find(":") + 1,
                message.size() - std::string(THREAD_END_MESSAGE).size());
            gameMessage gameMessage(id, message);
            // std::cout << "Message received: " << gameMessage.getMessage()
            //           << std::endl;
            // std::cout << "From: " << gameMessage.getId() << std::endl;
            _game.getReadMessages().push_back(gameMessage);
        }
        _game.getReadMutex().unlock();
    }
}

void GameModule::stop() {
    if (!_Running) {
        return;
    }
    std::cout << "Module: " << _ModuleName << " is stopping" << std::endl;
    if (_game.getReadMutex().try_lock()) {
        _game.getReadMutex().unlock();
    }
    if (_game.getSendMutex().try_lock()) {
        _game.getSendMutex().unlock();
    }
    _Running = false;
    _thread.join();
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

#ifdef _WIN32
    extern "C" {
        __declspec(dllexport) AbstractModule* create_module(const std::string name, const std::string id) {
            return new GameModule(name, id);
        }
    }
#else
    extern "C" {
        AbstractModule* create_module(const std::string name, const std::string id) {
            return new GameModule(name, id);
        }
    }
#endif
