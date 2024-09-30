/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** UDPServer.cpp
*/

#include "UDPServer.hpp"
#include "UDPError.hpp"

UDPServer::UDPServer(boost::asio::io_context& io_context, short port)
    : _socket(io_context, udp::endpoint(udp::v4(), port)) {
    start_receive();
}

void UDPServer::start_receive() {
    _socket.async_receive_from(
        boost::asio::buffer(_recv_buffer), _remote_endpoint,
        [this](std::error_code ec, std::size_t bytes_recvd) {
            if (!ec && bytes_recvd > 0) {
                handle_receive(bytes_recvd);
            } else {
                if (ec) {
                    throw UDPError("Error during receiving data: " +
                                   ec.message());
                }
                start_receive();
            }
        });
}

void UDPServer::handle_receive(std::size_t length) {
    try {
        std::cout << "Received binary data: ";
        for (std::size_t i = 0; i < length; ++i) {
            std::cout << std::bitset<8>(_recv_buffer[i]) << " ";
        }
        std::cout << std::endl;

        std::string decoded_message(_recv_buffer.data(), length);
        std::cout << "Decoded message: " << decoded_message << std::endl;

        std::string response = "Message received!";
        _socket.async_send_to(
            boost::asio::buffer(response), _remote_endpoint,
            [this](std::error_code ec, std::size_t) {
                if (ec) {
                    throw UDPError("Error sending response: " + ec.message());
                }
                start_receive();
            });
    } catch (const UDPError& e) {
        std::cerr << "UDP Server Error: " << e.what() << std::endl;
    }
}
