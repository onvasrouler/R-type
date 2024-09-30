/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../lib/MultiThread.hpp"

/** @class AbstractModule
 *  @brief The AbstractModule class is the base class for all modules.
 * It inherits from MultiThreadElement.
 * It is an abstract class.
 * It contains the start, run and stop methods.
 * It also contains the decodeInterCommunication and encodeInterCommunication methods.
 * It contains a boolean _Running.
 * The constructor takes a SOCKET or an int as parameter depend of the OS.
 * The decode method must be overrided.
 * The run method must be overrided.
 */
class AbstractModule : public MultiThreadElement {
    public:
        /** @brief Constructor of AbstractModule.
         */
        AbstractModule();
        #ifdef _WIN32
            /** @brief Constructor of AbstractModule.
             *  @param serverInterSocket The socket of the server.
             */
            AbstractModule(const SOCKET serverInterSocket);
        #else
            /** @brief Constructor of AbstractModule.
             *  @param serverInterSocket The socket of the server.
             */
            AbstractModule(const int serverInterSocket);
        #endif
        /** @brief Destructor of AbstractModule.
         */
        ~AbstractModule();
        /**
         * @brief Start the module.
         */
        void start();
        /**
         * @brief The main loop of the module
         */
        void run() override;
        /**
         * @brief Stop the module.
         */
        void stop();
    protected:
        /**
         * @brief Decode the message received from the server.
         * @param message The message to decode.
         */
        virtual void decodeInterCommunication(std::string message) override;
        /**
         * @brief Encode the message to send to the server.
         * @param message The message to encode.
         */
        virtual void encodeInterCommunication(std::string message) override;
        bool _Running; /*!< The state of the module. */
};
