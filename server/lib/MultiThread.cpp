/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "MultiThread.hpp"
#include "sys/socket.h"

MultiThreadElement::MultiThreadElement(const int serverInterSocket)
{
    _thread = Thread();
    _datas = std::vector<MultiThreadData>();
    _otherElements = std::vector<int>();
    _otherElements.push_back(serverInterSocket);
    _sendingMessages = std::vector<std::string>();
    _receivedMessages = std::vector<std::string>();
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
    }
    if (connect(_socket, (struct sockaddr *)&serverInterSocket, sizeof(serverInterSocket)) == -1) {
        std::throw_with_nested(std::runtime_error("Error: connection failed"));
    }
    send(_socket, "100", 5, 0);
    char buffer[1024] = {0};
    recv(_socket, buffer, 1024, 0);
    std::string message = buffer;
    if (message != "100") {
        std::throw_with_nested(std::runtime_error("Error: connection failed"));
    }
}

Thread MultiThreadElement::getThread() const
{
    return _thread;
}

MultiThreadData::MultiThreadData()
{
    _data = std::any();
}

MultiThreadData::MultiThreadData(const std::any data)
{
    _data = data;
}
std::any MultiThreadData::getData() const
{
    return _data;
}

void MultiThreadData::setData(const std::any data)
{
    _data = data;
}

void MultiThreadData::setData(std::any &data)
{
    _data = data;
}
