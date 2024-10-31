/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include <boost/asio.hpp>
#include <mutex>
#include <system_error>
#include "UUID.hpp"

class AdminClient {
    public:
        AdminClient() = default;
        AdminClient(const std::shared_ptr<boost::asio::ip::tcp::socket> socket);
        ~AdminClient();
        void WriteTo(const std::string &message);
        void addMessage(const std::string &message);
        bool hasMessage();
        std::vector<std::string> getMessages();
        bool IsConnected();
        bool IsLogged();
        bool CompareSocket(const std::shared_ptr<boost::asio::ip::tcp::socket> socket);
        std::string GetUUID();

    private:
        std::shared_ptr<boost::asio::ip::tcp::socket> _socket;
        std::mutex _mutex;
        std::vector<std::string> _messages;
        std::string _uuid;
        bool _Logged;
};
