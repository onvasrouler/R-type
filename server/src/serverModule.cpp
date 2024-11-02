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
                           const SOCKET serverInterSocket, HMODULE file) {
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
    _dynamicLibrary = file;
}
#else
serverModule::serverModule(AbstractModule* module,
                           const int serverInterSocket, void *file) {
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
    _dynamicLibrary = file;
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

void serverModule::addMessage(const std::string message) {
    _messages.push_back(message);
}

std::vector<std::string> serverModule::getMessages() { return _messages; }

void serverModule::clearMessages() { _messages.clear(); }

std::vector<std::string> serverModule::getCommunicatesModules() {
    return _communicatesModulesID;
}

#ifdef _WIN32
    std::vector<SOCKET> serverModule::getCommunicatesSockets() {
        return _communicatesModules;
    }

    void serverModule::addCommunicatesModule(const SOCKET moduleSocket) {
        _communicatesModules.push_back(moduleSocket);
    }
#else
    std::vector<int> serverModule::getCommunicatesSockets() {
        return _communicatesModules;
    }

    void serverModule::addCommunicatesModule(const int moduleSocket) {
        _communicatesModules.push_back(moduleSocket);
    }
#endif
