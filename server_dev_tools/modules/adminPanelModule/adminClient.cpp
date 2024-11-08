/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "adminClient.hpp"
#include <iostream>

AdminClient::AdminClient(const std::shared_ptr<boost::asio::ip::tcp::socket> socket)
    : _socket(socket)
{
    _uuid = uuid().toString();
}

AdminClient::~AdminClient()
{
    _socket->close();
}

void AdminClient::WriteTo(const std::string &message)
{
    boost::asio::write(*_socket, boost::asio::buffer(message));
}

void AdminClient::addMessage(const std::string &message)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _messages.push_back(message);
}

bool AdminClient::hasMessage()
{
    std::lock_guard<std::mutex> lock(_mutex);
    return !_messages.empty();
}

std::vector<std::string> AdminClient::getMessages()
{
    std::lock_guard<std::mutex> lock(_mutex);
    return _messages;
}

void AdminClient::clearMessages()
{
    std::lock_guard<std::mutex> lock(_mutex);
    std::cout << "clear messages" << std::endl;
    _messages.clear();
}

bool AdminClient::IsConnected()
{
    return _socket->is_open();
}

bool AdminClient::IsLogged()
{
    return _Logged;
}

bool AdminClient::CompareSocket(const std::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
    return _socket == socket;
}

std::string AdminClient::GetUUID()
{
    return _uuid;
}

void AdminClient::setName(const std::string &name)
{
    this->name = name;
}

void AdminClient::setLogged(const bool logged)
{
    _Logged = logged;
}
