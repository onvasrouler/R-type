/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "gameModule.hpp"

GameModule::GameModule(std::string name) : AbstractModule(name) {
    // Need to be implemented with the game engine
}

GameModule::~GameModule() {
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    if (_Running) {
        stop();
    }
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
}

std::string GameModule::encodeInterCommunication(std::string message) {
    std::string encodedMessage = message;
    return message;
    // Encode message
    // Send message
    // send(serverInterSocket, encodedMessage.c_str(), encodedMessage.size(),
    // 0);
}

std::string GameModule::decodeInterCommunication(std::string message) {
    std::string decodedMessage = message;
    return message;
    // Decode message
    // Do something with the message
}

void GameModule::run() {
    std::cout << "Module: " << _ModuleName << " is running" << std::endl;
    while (_Running) {
    }
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}
