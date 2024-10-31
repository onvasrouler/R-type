/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** networkElem
*/

#include "networkElem.hpp"

NetworkElem::NetworkElem(const std::string ip, const std::string port) :
_Io_service(),
_Socket(_Io_service),
_Endpoint(boost::asio::ip::address::from_string(ip), std::stoi(port)),
_Timer(_Io_service),
_Timer2(_Io_service)
{
    _Ip = ip;
    _Port = port;
    _Connected = false;
    _Status = Status::DISCONNECTED;
} 

NetworkElem::~NetworkElem()
{
     if (_Socket.is_open()) {
            _Socket.close();
    }
    _Io_service.stop();
    if (_Network_thread.joinable()) {
        _Network_thread.join();
    }
}

void NetworkElem::setPort(const std::string port)
{
    _Endpoint.port(std::stoi(port));
    _Port = port;
}

void NetworkElem::setIp(const std::string ip)
{
    _Endpoint.address(boost::asio::ip::address::from_string(ip));
    _Ip = ip;
}

void NetworkElem::setServerInfos(const std::string ip, const std::string port)
{
    this->setIp(ip);
    this->setPort(port);
}

std::string NetworkElem::getIp() const
{
    return _Ip;
}

std::string NetworkElem::getPort() const
{
    return _Port;
}

bool NetworkElem::isConnected() const
{
    return _Connected;
}

NetworkElem::Status NetworkElem::getStatus() const
{
    return _Status;
}

void NetworkElem::connect()
{
    this->disconnect();

    _Status = Status::CONNECTING;
    std::cout << "Connecting to " << _Ip << ":" << _Port << std::endl;
    try {
        _Socket.open(boost::asio::ip::udp::v4());
        _Timer.expires_after(std::chrono::seconds(10));
        _Timer.async_wait([this](boost::system::error_code ec) {
            if (!ec && _Status == Status::CONNECTING) {
                _Status = Status::CONNECTION_FAILED;
                _Socket.close();
            }
        });
        initConnection();
    } catch (const std::exception &e) {
        _Status = Status::CONNECTION_FAILED;
        std::cerr << "Exception: " << e.what() << std::endl;
    }
     if (!_Network_thread.joinable())
        _Network_thread = std::thread([this]() { _Io_service.run(); });
}

void NetworkElem::initConnection()
{
    std::cout << "Init connection" << std::endl;
    _Timer2.expires_after(std::chrono::seconds(2));
    _Timer2.async_wait([this](boost::system::error_code ec) {
        if (!ec && _Status == Status::CONNECTING) {
            std::cout << "Sending init message" << std::endl;
            this->send("00\r\n");
            initConnection();
        }
    });
}


void NetworkElem::send(const std::string message)
{
    std::cout << "Sending: " << message << std::endl;
    _Socket.async_send_to(boost::asio::buffer(message), _Endpoint,
        [](boost::system::error_code ec, std::size_t /*length*/) {
            if (ec) {
                std::cerr << "Send error: " << ec.message() << std::endl;
            }
        });
}

void NetworkElem::asyncReceive()
{
    _Socket.async_receive_from(boost::asio::buffer(_Buffer), _Sender_endpoint,
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string data(_Buffer.data(), length);
                std::cout << "Received: " << data << std::endl;
                _Status = Status::CONNECTED;
                asyncReceive();
            } else if (ec) {
                std::cerr << "Receive error: " << ec.message() << std::endl;
                _Status = Status::CONNECTION_FAILED;
            }
        });
}

void NetworkElem::disconnect()
{
    std::cout << "Disconnecting" << std::endl;
    _Connected = false;
    _Status = Status::DISCONNECTED;
    if (_Socket.is_open()) {
        _Socket.close();
    }
    _Timer.cancel();
    _Timer2.cancel();
    _Io_service.reset();
    if (_Network_thread.joinable()) {
        _Network_thread.join();
    }
    _Network_thread = std::thread();
}

void NetworkElem::setGame(std::shared_ptr<Game> game)
{
    _Game = game;
}