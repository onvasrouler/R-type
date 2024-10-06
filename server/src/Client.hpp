/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#ifdef _WIN32
     #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib") // Lien avec la bibliothèque WS2_32.lib
#else
    #include "sys/socket.h"
#endif
#include <string>
#include "../lib/UUID.hpp"

class Client {
    public:
        Client() : _ip(""), _port(0) {};
        Client(const std::string ip, const short port) : _ip(ip), _port(port), _uuid() {};
        Client(const Client& client) : _ip(client.getIp()), _port(client.getPort()), _uuid(client.getUuid()) {};
        ~Client() = default;
        const std::string getIp() const { return _ip; }
        const short getPort() const { return _port; }
        const uuid getUuid() const { return _uuid; }
        bool operator==(const Client& client) const {
            return _uuid == client.getUuid();
        }
        bool operator!=(const Client& client) const {
            return _uuid != client.getUuid();
        }
        //operator equal
        Client operator=(const Client& client) {
            return Client(client);
        }
    protected:
        const std::string _ip;
        const short _port;
        const uuid _uuid;
};
