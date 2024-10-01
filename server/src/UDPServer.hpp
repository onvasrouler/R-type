/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** UDPServer.hpp
*/

#pragma once

#include <array>
#include <bitset>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

/**
 * @class UDPServer
 * @brief A simple UDP server that asynchronously receives and responds to messages.
 *
 * This class represents a UDP server using Boost.Asio for asynchronous
 * communication. The server listens on a specified port, receives binary-encoded
 * messages, decodes them, and sends a response back to the client.
 */
class UDPServer {
  public:
    /**
     * @brief Constructs the UDPServer and starts listening on the given port.
     *
     * @param io_context The I/O context used for asynchronous operations.
     * @param port The port number on which the server will listen for incoming messages.
     */
    UDPServer(boost::asio::io_context& io_context, short port);

  private:
    /**
     * @brief Starts an asynchronous receive operation.
     *
     * This method initiates an asynchronous receive operation that waits for data
     * from a remote endpoint. When data is received, it calls the handle_receive() method.
     */
    void start_receive();

    /**
     * @brief Handles the reception of data.
     *
     * This method is called when data is received from the remote endpoint. It processes
     * the received data, decodes the binary-encoded message, and sends a response back.
     *
     * @param length The length of the received message in bytes.
     */
    void handle_receive(std::size_t length);

    /// The socket used to communicate over UDP.
    udp::socket _socket;

    /// The remote endpoint from which data is received.
    udp::endpoint _remote_endpoint;

    /// A buffer to store the received data.
    std::array<char, 1024> _recv_buffer;
};