/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../AbstractModule.hpp"

class MainToClients : public AbstractModule {
    public:
        /**
        * @brief Constructor of MainToClients.
        */
        MainToClients() = default;
        /**
        * @brief Constructor of MainToClients.
        * @param name The name of the module.
        * @param id The id of the module.
        */
        MainToClients(const std::string name, const std::string id);
        /**
        * @brief Destructor of MainToClients.
        * if the module is running, it will stop it.
        */
        ~MainToClients();
        /**
        * @brief The main loop of the module
        */
        void run() override;
        /**
        * @brief Stop the module.
        */
        void stop() override;
    private:
        /**
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        std::string encodeInterCommunication(const std::string message)override;
        /**
        * @brief Decode the message received from the server.
        * @param message The message to decode.
        */
        std::string decodeInterCommunication(const std::string message) override;
};
