/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "MultiThread.hpp"
#include "AbstractModule.hpp"

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
        void decodeInterCommunication(std::string message) override;
        /*
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        void encodeInterCommunication(std::string message) override;
        bool _Running; /*!< The state of the server. */
        std::vector<AbstractModule> _modules; /*!< The modules of the server. */
};
