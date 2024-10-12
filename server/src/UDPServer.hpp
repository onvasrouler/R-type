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
#include <mutex>

using boost::asio::ip::udp;

class packageData {
    public:
      packageData(const std::string data, const std::string ip, const std::size_t port);
      std::string getData();
      std::string getIp();
      std::size_t getPort();
    private:
      const std::string _data;
      const std::string _ip;
      const std::size_t _port;
};

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
    UDPServer(boost::asio::io_context& io_context, const short port);

    void stop();

    /**
     * @brief Returns the mutex use for the send message vector.
     *
     * @return The mutex used for the send message vector.
     */
    std::mutex& getSendMutex();

    /**
     * @brief Returns the mutex use for the receive message vector.
     *
     * @return The mutex used for the receive message vector.
     */
    std::mutex& getReceiveMutex();

    /**
     * @brief Returns the mutex use for stop the server when stopping the server.
     *
     * @return The mutex used for stop.
     */
    std::mutex& getStopMutex();

    /**
     * @brief Returns the vector of received messages.
     *
     * @return The vector of received messages.
     */
    std::vector<packageData>& getReceivedData();

    /**
     * @brief Returns the vector of messages to sent.
     *
     * @return The vector of messages to sent.
     */
    std::vector<packageData>& getSentData();

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
    std::array<char, 1024> _recv_buffer; // The buffer to store the received data
    std::vector<packageData> _receivedData; // The messages received
    std::vector<packageData> _sentData; // The messages to send
    std::mutex _sendMutex; // The mutex for the send message vector
    std::mutex _receiveMutex; // The mutex for the receive message vector
    std::mutex _stopMutex; // The mutex for stop the server
    bool _running; // The server is running
};
