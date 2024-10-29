/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "HeadServerServerModule.hpp"

HeadServerServerModule::HeadServerServerModule(AbstractModule* module, const int serverInterSocket) {
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
}

HeadServerServerModule::HeadServerServerModule(const HeadServerServerModule& module) {
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
}

HeadServerServerModule& HeadServerServerModule::operator=(const HeadServerServerModule& module) {
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
    return *this;
}

void HeadServerServerModule::stop() { _module->stop(); }

std::shared_ptr<AbstractModule> HeadServerServerModule::getModule() { return _module; }

#ifdef _WIN32
SOCKET HeadServerServerModule::getSocket() { return _serverInterSocket; }
#else
int HeadServerServerModule::getSocket() { return _serverInterSocket; }
#endif

void HeadServerServerModule::addMessage(const std::string message) {
    _messages.push_back(message);
}

std::vector<std::string> HeadServerServerModule::getMessages() { return _messages; }

void HeadServerServerModule::clearMessages() { _messages.clear(); }
