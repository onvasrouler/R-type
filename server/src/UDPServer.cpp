/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** UDPServer.cpp
*/

#include "UDPServer.hpp"
#include "UDPError.hpp"

packageData::packageData(const std::string data, const std::string ip,
                         const std::size_t port)
    : _data(data), _ip(ip), _port(port) {};

std::string packageData::getData() { return _data; }

std::string packageData::getIp() { return _ip; }

std::size_t packageData::getPort() { return _port; }

UDPServer::UDPServer(boost::asio::io_context& io_context, const short port)
    : _socket(io_context, udp::endpoint(udp::v4(), port)) {
    _running = true;
    start_receive();
}

void UDPServer::stop() {
    _running = false;
    if (_sendMutex.try_lock()) {
        _sendMutex.unlock();
    }
    if (_receiveMutex.try_lock()) {
        _receiveMutex.unlock();
    }
}

void UDPServer::start_receive() {
    if (!_running) {
        return;
    }
    _socket.async_receive_from(
        boost::asio::buffer(_recv_buffer), _remote_endpoint,
        [this](std::error_code ec, std::size_t bytes_recvd) {
            if (!ec) {
                handle_receive(bytes_recvd);
            } else {
                _stopMutex.lock();
                if (ec && _running) {
#ifdef _WIN32
                    std::cerr << "Error during receiving data: " << ec.message()
                              << std::endl;
#endif
                    throw UDPError("Error during receiving data: " +
                                   ec.message());
                }
                _stopMutex.unlock();
                start_receive();
            }
        });
}

void UDPServer::handle_receive(std::size_t length) {
    if (!_running) {
        return;
    }
    try {
        if (length > 0) {
            std::string decoded_message(_recv_buffer.data(), length);
            std::cout << "Decoded message: " << decoded_message << std::endl;

            packageData data = packageData(
                decoded_message, _remote_endpoint.address().to_string(),
                _remote_endpoint.port());

            std::string confirmation = "Message received: " + decoded_message;
            _socket.async_send_to(
                boost::asio::buffer(confirmation), _remote_endpoint,
                [this](std::error_code ec, std::size_t) {
                    if (!ec) {
                        std::cout << "Confirmation sent to client."
                                  << std::endl;
                    } else {
                        std::cerr
                            << "Error sending confirmation: " << ec.message()
                            << std::endl;
                    }
                });
            _receiveMutex.lock();
            _receivedData.push_back(data);
            _receiveMutex.unlock();
        }
        start_receive();
    } catch (const UDPError& e) {
        std::cerr << "UDP Server Error: " << e.what() << std::endl;
    }
}

std::mutex& UDPServer::getSendMutex() { return _sendMutex; }

std::mutex& UDPServer::getReceiveMutex() { return _receiveMutex; }

std::mutex& UDPServer::getStopMutex() { return _stopMutex; }

std::vector<packageData>& UDPServer::getReceivedData() { return _receivedData; }

std::vector<packageData>& UDPServer::getSentData() { return _sentData; }
