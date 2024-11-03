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
    if (_Socket.is_open())
        _Socket.close();
    _Socket.close();
    _Status = Status::CONNECTING;
    if (_DebugLogger)
        _DebugLogger->Log("Connecting to server", 2);
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
    _LastSendTime = std::chrono::steady_clock::now();
    if (_DebugLogger)
        _DebugLogger->Log("end of connecting to server", 2);
}

void NetworkElem::initConnection()
{
    _Timer2.expires_after(std::chrono::seconds(2));
    _Timer2.async_wait([this](boost::system::error_code ec) {
        if (!ec && _Status == Status::CONNECTING) {
            asyncReceive();
            initConnection();
        }
    });
}


void NetworkElem::send(const std::string& message)
{
    auto binary_message =std::vector<char>(message.begin(), message.end());

    
    _Socket.send_to(boost::asio::buffer(binary_message), _Endpoint);
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
                if (_DebugLogger)
                    _DebugLogger->Log("Received data: " + data, 5);
                _Game->_modifMutex.lock();
                _Game->_modif.push_back(data);
                _Game->_modifMutex.unlock();
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

        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - _LastSendTime);
        if (_DebugLogger)
            _DebugLogger->Log("duration: " + std::to_string(duration.count()), 5);
        if (duration.count() >= 20) {
            if (_DebugLogger)
                _DebugLogger->Log("sending data depending on input", 5);
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
            _LastSendTime = now;
        }
        if (_DebugLogger)
            _DebugLogger->Log("updating game", 5);
        _Game->update();
        if (_DebugLogger)
            _DebugLogger->Log("game updated", 5);
        if (_DaltonismFilter)
            BeginShaderMode(_DaltonismFilter->getShader());
        _Game->draw();
        if (_DebugLogger)
            _DebugLogger->Log("game drawn", 5);
        if (_DaltonismFilter)
            EndShaderMode();
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

std::shared_ptr<Game> NetworkElem::getGame() const
{
    return _Game;
}

void NetworkElem::setDaltonismFilter(std::shared_ptr<daltonismFilter> daltonismFilter)
{
    _DaltonismFilter = daltonismFilter;
}