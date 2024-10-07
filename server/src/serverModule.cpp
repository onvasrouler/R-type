/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "serverModule.hpp"

#ifdef _WIN32
serverModule::serverModule(AbstractModule* module,
                           const SOCKET serverInterSocket) {
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
}
#else
serverModule::serverModule(AbstractModule* module,
                           const int serverInterSocket) {
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
}
#endif

serverModule::serverModule(const serverModule& module) {
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
}

serverModule& serverModule::operator=(const serverModule& module) {
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
    return *this;
}

void serverModule::stop() { _module->stop(); }

std::shared_ptr<AbstractModule> serverModule::getModule() { return _module; }

#ifdef _WIN32
SOCKET serverModule::getSocket() { return _serverInterSocket; }
#else
int serverModule::getSocket() { return _serverInterSocket; }
#endif
