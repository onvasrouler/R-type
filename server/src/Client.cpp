/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "Client.hpp"

Client::Client() : _ip(""), _port(0) {}

Client::Client(const std::string ip, const std::size_t port, const uuid userId)
    : _ip(ip), _port(port), _uuid(userId) {}

Client::Client(const Client& client)
    : _ip(client.getIp()), _port(client.getPort()), _uuid(client.getUuid()) {}

const std::string Client::getIp() const { return _ip; }

const std::size_t Client::getPort() const { return _port; }

const uuid Client::getUuid() const { return _uuid; }

bool Client::operator==(const Client& client) const {
    return _uuid == client.getUuid();
}

bool Client::operator!=(const Client& client) const {
    return _uuid != client.getUuid();
}

Client Client::operator=(const Client& client) { return Client(client); }
