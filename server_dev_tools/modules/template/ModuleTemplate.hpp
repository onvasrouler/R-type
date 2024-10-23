/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once // Include guard, you can use #ifndef and #endif instead if you want
#include "AbstractModule.hpp"

class ModuleTemplate : public AbstractModule {
    public:
        ModuleTemplate() = default; // Implement it if you want
        ModuleTemplate(const std::string name, const std::string id); // Implement it
        ~ModuleTemplate(); // Implement it
        // void start() override; Uncomment it if you want to re implement it (optional)
        void run() override; //Implement it
        // void stop() override; Uncomment it if you want to re implement it (optional)
    protected:
        /**
         * @brief Decode the message received from the server.
         * @param message The message to decode.
         */
        std::string decodeInterCommunication(const std::string message) override;
        /**
         * @brief Encode the message to send to the server.
         * @param message The message to encode.
         */
        std::string encodeInterCommunication(const std::string message) override;
        // add what you want for your module
    private:
        // add what you want for your module
};
