/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"

/** @class ReadModule
 *  @brief The ReadModule class is the class for the read module.
 * It inherits from AbstractModule.
 * It will handle the communication with the network.
 * It will also handle the reading of the network.
*/
class ReadModule : public AbstractModule {
    public:
        /*
        * @brief Constructor of ReadModule.
        */
        ReadModule() = default;
        /*
        * @brief Constructor of ReadModule.
        * @param name The name of the module.
        */
        ReadModule(std::string name);
        /*
        * @brief Destructor of ReadModule.
        * if the module is running, it will stop it.
        */
        ~ReadModule();
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
