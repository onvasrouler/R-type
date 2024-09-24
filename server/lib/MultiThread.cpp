/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "MultiThread.hpp"
#include "sys/socket.h"

MultiThreadElement::MultiThreadElement()
{
    _thread = Thread();
    _datas = std::vector<MultiThreadData>();
    _otherModules = std::vector<int>();
    _sendingIntern = std::vector<std::string>();
    _receivedIntern = std::vector<std::string>();
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
    }
}

MultiThreadElement::MultiThreadElement(const int serverInterSocket)
{
    _thread = Thread();
    _datas = std::vector<MultiThreadData>();
    _otherModules = std::vector<int>();
    _otherModules.push_back(serverInterSocket);
    _sendingIntern = std::vector<std::string>();
    _receivedIntern = std::vector<std::string>();
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
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
