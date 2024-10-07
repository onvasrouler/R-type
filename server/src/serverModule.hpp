/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"

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
            serverModule(AbstractModule* module, const SOCKET serverInterSocket);
        #else
            serverModule(AbstractModule *module, const int serverInterSocket);
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

        std::shared_ptr<AbstractModule> getModule();

        #ifdef _WIN32
            SOCKET getSocket();
        #else
            int getSocket();
        #endif
    private:
        std::shared_ptr<AbstractModule> _module; // The module to store.
        #ifdef _WIN32
            SOCKET _serverInterSocket; // The socket to communicate with the module.
        #else
            int _serverInterSocket; // The socket to communicate with the module.
        #endif
};
