/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "AbstractModule.hpp"
#include "Game.hpp"

/** @class GameModule
 *  @brief The GameModule class is the class for the game module.
 * It inherits from AbstractModule.
 * It will handle the communication with the game engine.
 * It will also handle the game logic.
*/
class GameModule : public AbstractModule {
    public:
        /**
        * @brief Constructor of GameModule.
        */
        GameModule() = default;
        /**
        * @brief Constructor of GameModule.
        * @param name The name of the module.
        */
        GameModule(const std::string name);
        /**
        * @brief Destructor of GameModule.
        * if the module is running, it will stop it.
        */
        ~GameModule();
        /**
        * @brief The main loop of the module
        */
        void run() override;
    private:
        /**
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        std::string encodeInterCommunication(const std::string message) override;
        /**
        * @brief Decode the message received from the server.
        * @param message The message to decode.
        */
        std::string decodeInterCommunication(const std::string message) override;
        //Need to be implemented with the game engine
        Game _game;
};