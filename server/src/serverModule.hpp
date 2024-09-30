/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"

class serverModule {
    public:
        serverModule(AbstractModule *module, const int serverInterSocket);
        serverModule(const serverModule &module);
        ~serverModule() = default;
        serverModule &operator=(const serverModule &module);
        void stop();
    private:
        std::shared_ptr<AbstractModule> _module;
        #ifdef _WIN32
            SOCKET _serverInterSocket;
        #else
            int _serverInterSocket;
        #endif
};
