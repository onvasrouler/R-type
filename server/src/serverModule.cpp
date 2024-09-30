/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "serverModule.hpp"

serverModule::serverModule(AbstractModule *module, const int serverInterSocket)
{
    _module = std::shared_ptr<AbstractModule>(module);
    _serverInterSocket = serverInterSocket;
}

serverModule::serverModule(const serverModule &module)
{
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
}

serverModule &serverModule::operator=(const serverModule &module)
{
    _module = module._module;
    _serverInterSocket = module._serverInterSocket;
    return *this;
}

void serverModule::stop()
{
    _module->stop();
}
