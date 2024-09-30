/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"

/** @class SendModule
 * @brief The SendModule class is the class for the send module.
 * It inherits from AbstractModule.
 * It will handle the communication with the network.
 * It will also handle the sending of the network.
 */
class SendModule : public AbstractModule {
    public:
        /*
        * @brief Constructor of SendModule.
        */
        SendModule() = default;
        /*
        * @brief Constructor of SendModule.
        * @param name The name of the module.
        */
        SendModule(std::string name);
        /*
        * @brief Destructor of SendModule.
        * if the module is running, it will stop it.
        */
        ~SendModule();
        /*
        * @brief The main loop of the module
        */
        void run() override;
    private:
        /*
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        void encodeInterCommunication(std::string message) override;
        /*
        * @brief Decode the message received from the server.
        * @param message The message to decode.
        */
        void decodeInterCommunication(std::string message) override;
        //Need to be implemented with the network lib
};
