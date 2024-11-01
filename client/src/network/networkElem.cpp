/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** networkElem
*/

#include "networkElem.hpp"

NetworkElem::NetworkElem(const std::shared_ptr<DebugLogger> debuglogger, const std::string ip, const std::string port) :
_Io_service(),
_Socket(_Io_service),
_Endpoint(boost::asio::ip::address::from_string(ip), std::stoi(port)),
_Timer(_Io_service),
_Timer2(_Io_service)
{
    _DebugLogger = debuglogger;
    _Ip = ip;
    _Port = port;
    _Connected = false;
    _Username = "default";
    _Status = Status::DISCONNECTED;
    _DownPressed = false;
    _UpPressed = false;
    _LeftPressed = false;
    _RightPressed = false;
    _SpacePressed = false;
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

void NetworkElem::setServerInfos(const std::string ip, const std::string port) // ajouter std::string username
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
    _Game->start();
    _Status = Status::CONNECTING;

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
        this->send("00\r\n");
        asyncReceive();
    } catch (const std::exception &e) {
        _Status = Status::CONNECTION_FAILED;
        std::cerr << "Exception: " << e.what() << std::endl;
    }
     if (!_Network_thread.joinable())
        _Network_thread = std::thread([this]() { _Io_service.run(); });
}

void NetworkElem::initConnection()
{
    _Timer2.expires_after(std::chrono::seconds(2));
    _Timer2.async_wait([this](boost::system::error_code ec) {
        if (!ec && _Status == Status::CONNECTING) {
            this->send("00\r\n");
            asyncReceive();
            initConnection();
            
        }
    });
}


void NetworkElem::send(const std::string& message)
{
    auto binary_message = std::make_shared<std::vector<char>>(message.begin(), message.end());
    
    _Socket.async_send_to(boost::asio::buffer(*binary_message), _Endpoint,
        [binary_message](boost::system::error_code ec, std::size_t /*length*/) {
            if (ec) {
                std::cerr << "Send error: " << ec.message() << std::endl;
            }
        });
}

void NetworkElem::asyncReceive()
{
    if (_Game->getShutDown())
        return;
    _Buffer.fill(0);
    _Socket.async_receive_from(boost::asio::buffer(_Buffer), _Sender_endpoint,
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string data(_Buffer.data(), length);
                if (_Status == Status::CONNECTING) {
                    _Status = Status::CONNECTED;
                    _Connected = true;
                    this->_Game->start();
                }
                if (_Status != Status::CONNECTED)
                    _Status = Status::CONNECTED;
                _Game->update(data);
                asyncReceive();
            } else if (ec) {
                std::cerr << "Receive error: " << ec.message() << std::endl;
                _Status = Status::CONNECTION_FAILED;
            }
        });
}

void NetworkElem::disconnect()
{
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
    if (_Game)
        _Game->stop();
}

void NetworkElem::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    _DebugLogger = debugLogger;
    if (_Game)
        _Game->setDebugLogger(debugLogger);
}

void NetworkElem::setGame(std::shared_ptr<Game> game)
{
    _Game = game;
}

void NetworkElem::update()
{
    if (_Game->getShutDown()) {
        disconnect();
        return;
    }
    if (_Status == Status::CONNECTED) {

        if (_UpPressed == 1)
            send("0/up\r\n");
        if (_DownPressed == 1)
            send("1/down\r\n");
        if (_LeftPressed == 1)
            send("2/left\r\n");
        if (_RightPressed == 1)
            send("3/right\r\n");
        if (_SpacePressed == 1)
            send("1/shoot\r\n");
        _Game->draw();
    }
}

void NetworkElem::handleInput(int key, int pressedOrReleased)
{
    if (_DebugLogger)
        _DebugLogger->Log("network elem is handling input", 4);
    if (key == 73 || key == 25 || key == 265 || key == 87)
        _UpPressed = (pressedOrReleased == 1);
    if (key == 74 || key == 18 || key == 264 || key == 83)
        _DownPressed = (pressedOrReleased == 1);
    if (key == 72 || key == 3 || key == 263 || key == 65)
        _LeftPressed = (pressedOrReleased == 1);
    if (key == 71 || key == 16 || key == 262 || key == 68)
        _RightPressed = (pressedOrReleased == 1);
    if (key == 32 || key == 57)
        _SpacePressed = (pressedOrReleased == 1);
}