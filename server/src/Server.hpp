/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "../lib/MultiThread.hpp"
#include "serverModule.hpp"
#include "UDPServer.hpp"
#include "Client.hpp"

#define SHUTDOWN_MESSAGE "500"
#define NEW_CONNECTION_MESSAGE "201"

/**
 * @brief The Server class is the main class of the server.
 * It inherits from MultiThreadElement.
 * It contains the start, run and stop methods.
 * It also contains the decodeInterCommunication and encodeInterCommunication methods.
 * It contains a boolean _Running.
 * It contains a vector of AbstractModule _modules.
 * The constructor takes no parameter.
 */
class Server : MultiThreadElement {
    public:
        /*
        * @brief Constructor of Server.
        */
        Server();
        /*
        * @brief Destructor of Server.
        */
        ~Server();
        /*
        * @brief Start the server.
        * It will start all the modules.
        * It will also check if all the module are connected
        * And if they are not, it will stop the server.
        * And it will throw an exception.
        * Otherwise it will start the main loop.
        */
        void start();
        /*
        * @brief The main loop of the server.
        */
        void run() override;
        /*
        * @brief Stop the server.
        * It will stop all the modules.
        * And make sure all of them are stopped
        */
        void stop();
    protected:
        /*
        * @brief Decode the message received from the server.
        * @param message The message to decode.
        */
        std::string decodeInterCommunication(const std::string message) override;
        /*
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        std::string encodeInterCommunication(const std::string message) override;
        /*
        * @brief The function that create a new module
        * This function will create a new module and add it to the vector _modules
        * It will also check if the module is connected
        * And throw an exception if it is not
        * @param module The module to create
        */
        void createModule(AbstractModule *module);
        /**
        * @brief This function check if the client is already connected
        *
        * @param ip The ip of the client
        * @param port The port of the client
        * @return true if the client is already connected
        * @return false if the client is not connected
        */
        bool isClient(const std::string ip, const short port);
        /**
         * @brief This function create a message to send to the client
         *
         * @param ip The ip of the client
         * @param port The port of the client
         * @param message The message to send
         * @return std::string The message to send
         */
        std::string createMessage(const std::string ip, const short port, const std::string message);
        /**
         * @brief This function find a client by its ip and port
         *
         * @param ip The ip of the client
         * @param port The port of the client
         * @return Client The client found
         */
        Client findClient(const std::string ip, const short port);
        /**
         * @brief This function find a client by its uuid
         *
         * @param uuid The uuid of the client
         * @return Client The client found
         */
        Client findClient(const uuid uuid);
        bool _Running; /*!< The state of the server. */
        std::vector<std::unique_ptr<serverModule>> _modules; /*!< The modules of the server. */
        std::vector<Client> _clients; /*!< The clients of the server. */
};
