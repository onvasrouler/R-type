/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "MultiThread.hpp"
#include "HeadServerServerModule.hpp"
#include "logModule.hpp"
#include "MainToSub.hpp"
#include "MainToClients.hpp"

#define NEW_CONNECTION_MESSAGE "201"
#define BAD_CONNECTION_MESSAGE "500"

/**
 * @brief The Server class is the main class of the server.
 * It inherits from MultiThreadElement.
 * It contains the start, run and stop methods.
 * It also contains the decodeInterCommunication and encodeInterCommunication methods.
 * It contains a boolean _Running.
 * It contains a vector of AbstractModule _modules.
 * The constructor takes no parameter.
 */
class HeadServer : MultiThreadElement {
    public:
        /*
        * @brief Constructor of Server.
        */
        HeadServer();
        /*
        * @brief Destructor of Server.
        */
        ~HeadServer();
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
        /**
        * @brief The function that create a new module
        * This function will create a new module and add it to the vector _modules
        * It will also check if the module is connected
        * And throw an exception if it is not
        * @param module The module to create
        */
        #ifdef _WIN32
            void createModule(AbstractModule *module);
        #else
            void createModule(AbstractModule *module);
        #endif
        bool canCommunicateWith(std::string moduleId, std::string communicateModuleId);
        bool _Running; /*!< The state of the server. */
        std::vector<std::unique_ptr<HeadServerServerModule>> _modules; /*!< The modules of the server. */
        #ifdef _WIN32
            SOCKET _maxSocket; /*!< The max socket of the server. */
        #else
            int _maxSocket; /*!< The max socket of the server. */
        #endif
};
