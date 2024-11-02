/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../AbstractModule.hpp"
#include "UDPServer.hpp"

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
        std::vector<packageData> _sentData; /*!< The data sent by the clients */
        std::unique_ptr<UDPServer> _udpServer; /*!< The UDP server */
        boost::asio::io_context _io_context; /*!< The io context */
        std::thread _udpThread; /*!< The thread of the UDP server */
};

//lire socket
// lire core messages
// send to clients
// envoie au serveur