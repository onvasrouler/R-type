/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"
#include "UDPServer.hpp"
#include "Client.hpp"

#define SHUTDOWN_MESSAGE "500"
#define END_MESSAGE_CODE "\r\n"

/** @class NetworkModule
 * @brief the class that interface with the network lib (asio)
*/
class NetworkModule : public AbstractModule {
    public:
        /**
         * @brief The constructor of the NetworkModule class
         *
         * @param the name of the module
         */
        NetworkModule(const std::string name);
        /**
         * @brief The destructor of the NetworkModule class
         *
         * It will stop the module if it is running
         */
        ~NetworkModule();
        /**
         * @brief Start the module
         */
        void start() override;
        /**
         * @brief The main loop of the module
         */
        void run() override;
        /**
         * @brief Stop the module
         */
        void stop() override;
    private:
        /**
         * @brief Decode the message received from the server.
         * @param message The message to decode.
         */
        std::string decodeInterCommunication(const std::string message) override;
        /**
         * @brief Encode the message to send to the server.
         * @param message The message to encode.
         */
        std::string encodeInterCommunication(const std::string message) override;
        /**
         * @brief Find if an ip and a port is already used by a client
         *
         * @param ip The ip to find
         * @param port The port to find
         * @return true if the client is already connected false otherwise
         */
        bool isClient(const std::string ip, const std::size_t port);
        /**
         * @brief This function create a message to send to the client
         *
         * @param ip The ip of the client
         * @param port The port of the client
         * @param message The message to send
         * @return std::string The message to send
         */
        std::string createMessage(const std::string ip, const std::size_t port, const std::string message);
        /**
         * @brief This function create the package to send to the client
         *
         * @param uuid The unique id of the client
         * @param message The message to send
         *
         * @return The package to send
         */
        packageData createPackageData(const std::string uuid, const std::string message);
        /**
         * @brief This function find a client by its ip and port
         *
         * @param ip The ip of the client
         * @param port The port of the client
         * @return Client The client found
         */
        Client findClient(const std::string ip, const std::size_t port);
        /**
         * @brief This function find a client by its uuid
         *
         * @param uuid The uuid of the client
         * @return Client The client found
         */
        Client findClient(const std::string uuid);
        std::vector<packageData> _sentData; /*!< The data sent by the clients */
        std::unique_ptr<UDPServer> _udpServer; /*!< The UDP server */
        boost::asio::io_context _io_context; /*!< The io context */
        std::thread _udpThread; /*!< The thread of the UDP server */
        std::vector<Client> _clients; /*!< The clients of the server. */
};

//lire socket
// lire core messages
// send to clients
// envoie au serveur