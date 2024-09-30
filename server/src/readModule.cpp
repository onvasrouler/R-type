/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "readModule.hpp"

ReadModule::ReadModule(std::string name) : AbstractModule(name)
{
    // need to be implemented with the network lib
}

ReadModule::~ReadModule()
{
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    if (_Running) {
        _Running = false;
        stop();
    }
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
}

void ReadModule::encodeInterCommunication(std::string message)
{
    std::string encodedMessage = message;
    //Encode message
    //Send message
    //send(serverInterSocket, encodedMessage.c_str(), encodedMessage.size(), 0);
}

void ReadModule::decodeInterCommunication(std::string message)
{
    std::string decodedMessage = message;
    //Decode message
    //Do something with the message
}

void ReadModule::run()
{
    std::cout << "Module: " << _ModuleName << " is running" << std::endl;
    while (_Running) {
    }
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}
