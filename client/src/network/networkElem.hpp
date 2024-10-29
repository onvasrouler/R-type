/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** networkElem
*/

#pragma once

#include <boost/asio.hpp>
#include <thread>
#include <iostream>
#include <atomic>


class NetworkElem {
public:
    enum class Status {
        DISCONNECTED,
        CONNECTED,
        CONNECTING,
        CONNECTION_FAILED
    };
    NetworkElem(const std::string ip = "1.1.1.1", const std::string port = "1234");
    ~NetworkElem();

    void setIp(const std::string ip);
    void setPort(const std::string port);
    void setServerInfos(const std::string ip, const std::string port);

    std::string getIp() const;
    std::string getPort() const;
    bool isConnected() const;
    Status getStatus() const;

    void connect();

    void send(const std::string message);

    void asyncReceive();

    void disconnect();

    private:
    std::string _Ip;
    std::string _Port;
    bool _Connected;
    std::atomic<Status> _Status;


    boost::asio::io_service _Io_service;
    boost::asio::ip::udp::socket _Socket;
    boost::asio::ip::udp::endpoint _Endpoint;
    boost::asio::ip::udp::endpoint _Sender_endpoint;
    std::thread _Network_thread;
    std::string _Response;
    boost::asio::steady_timer _Timer;
    std::array<char, 1024> _Buffer;



};
