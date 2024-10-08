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

class NetworkModule : public AbstractModule {
    public:
        NetworkModule(std::string name);
        ~NetworkModule();
        void start() override;
        void run() override;
        void stop() override;
    private:
        /**
         * @brief Decode the message received from the server.
         * @param message The message to decode.
         */
        std::string decodeInterCommunication(std::string message) override;
        /**
         * @brief Encode the message to send to the server.
         * @param message The message to encode.
         */
        std::string encodeInterCommunication(std::string message) override;
        std::vector<packageData> _sentData;
        std::unique_ptr<UDPServer> _udpServer;
        boost::asio::io_context _io_context;
        std::thread _udpThread;
};

//lire socket
// lire core messages
// send to clients
// envoie au serveur