/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"

Server::Server() : MultiThreadElement()
{
    _Running = false;
}

Server::~Server()
{
    if (_Running)
        stop();
}

void Server::start()
{
    _Running = true;
    //create all the modules
}

void Server::run()
{
    while (_Running) {
        //first check the new connections
        //if there is a new connection, sending the informations to the concerned modules
        //then check the messages from the modules
        //if there is a message, sending the informations to the concerned modules
    }
}

void Server::stop()
{
    //stop all the modules
    _Running = false;
    //quit the function only if all the modules are stopped
}

void Server::decodeInterCommunication(std::string message)
{
    //decode the message
}

void Server::encodeInterCommunication(std::string message)
{
    //encode the message
}
