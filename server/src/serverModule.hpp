/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "AbstractModule.hpp"

/** @class serverModule
 * @brief The serverModule class is a class that store a module and a socket.
 * It will be used by the server to store the modules.
 * And to store know which socket to use to communicate with the module.
 */
class serverModule {
    public:
        /*
        * @brief Constructor of serverModule.
        * @param module The module to store.
        * @param serverInterSocket The socket to communicate with the module.
        */
        #ifdef _WIN32
            serverModule(AbstractModule* module, const SOCKET serverInterSocket, HMODULE file);
        #else
            serverModule(AbstractModule *module, const int serverInterSocket, void *file);
        #endif
        /*
        * @brief Copy constructor of serverModule.
        * @param module The module to store.
        *
        * Copy the module and the socket.
        */
        serverModule(const serverModule &module);
        /*
        * @brief Destructor of serverModule.
        */
        ~serverModule() = default;
        /*
        * @brief Copy operator of serverModule.
        * @param module The module to store.
        * @return The new serverModule.
        */
        serverModule &operator=(const serverModule &module);
        /*
        * @brief Stop the module.
        */
        void stop();

        /**
         * @brief Get the module.
         *
         * @return The module.
         */
        std::shared_ptr<AbstractModule> getModule();

        /**
         * @brief Get the socket.
         *
         * @return The socket.
         */
        #ifdef _WIN32
            SOCKET getSocket();
        #else
            int getSocket();
        #endif

        /**
         * @brief This function add a message to the list of message that need to be send to other modules
         *
         * @param The message that need to be sent
         */
        void addMessage(const std::string message);

        /**
         * @brief This function return the list of message that need to be sent to other modules
         *
         * @return The list of message that need to be sent to other modules
         */
        std::vector<std::string> getMessages();

        /**
         * @brief This function clear the list of message that need to be sent to other modules
         */
        void clearMessages();

        /**
         * @brief This function return the module name
         *
         * @return The module name
         */
        std::string getModuleName() { return _module->getName(); }

        /**
         * @brief This function return the module dynamic library
         *
         * @return The module dynamic library
         */
        #ifdef _WIN32
            HMODULE getDynamicLibrary() { return _dynamicLibrary; }
        #else
            void *getDynamicLibrary() { return _dynamicLibrary; }
        #endif
    private:
        std::shared_ptr<AbstractModule> _module; // The module to store.
        #ifdef _WIN32
            SOCKET _serverInterSocket; // The socket to communicate with the module.
        #else
            int _serverInterSocket; // The socket to communicate with the module.
        #endif
        std::vector<std::string> _messages; // The messages to send to the module.
        #ifdef _WIN32
            HMODULE _dynamicLibrary; // The dynamic library of the module.
        #else
            void *_dynamicLibrary; // The dynamic library of the module.
        #endif
};
