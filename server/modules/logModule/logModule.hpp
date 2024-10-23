/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../AbstractModule.hpp"
#include <sstream>
#include <mutex>

class LogModule : public AbstractModule {
    public:
        /**
        * @brief Constructor of LogModule.
        */
        LogModule() = default;
        /**
        * @brief Constructor of LogModule.
        * @param name The name of the module.
        * @param id The id of the module.
        */
        LogModule(const std::string name, const std::string id);
        /**
        * @brief Destructor of LogModule.
        * if the module is running, it will stop it.
        */
        ~LogModule();
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
         * @brief Cheeck if their is the directories needed by the log module
         * if not it will create them
         */
        void checkLogDir();
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
        // std::ostringstream _buffer; /*The buffer to store the logs */
        std::mutex _destroyMutex; /*The mutex to protect the destruction of the module */
        std::string _date; /*The date of the day*/
};
