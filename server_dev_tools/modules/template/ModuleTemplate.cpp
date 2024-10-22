/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ModuleTemplate.hpp"

ModuleTemplate::ModuleTemplate(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
    std::cout << "Module: " << _ModuleName << " is created" << std::endl;
    // add what you want for your module
    std::cout << "Module: " << _ModuleName << " created" << std::endl;
}

ModuleTemplate::~ModuleTemplate()
{
    std::cout << "Module: " << _ModuleName << " is destroyed" << std::endl;
    if (_Running) {
        stop();
    }
    std::cout << "Module: " << _ModuleName << " destroyed" << std::endl;
}

// void ModuleTemplate::start()

void ModuleTemplate::run()
{
    // add what you want for your module
    std::cout << "Module: " << _ModuleName << " is running" << std::endl;
    while (_Running) {
        std::cout << "Module: " << _ModuleName << " is trolling you" << std::endl;
        // add what you want for your module
    }
    std::cout << "Module: " << _ModuleName << " stop running" << std::endl;
}

// void ModuleTemplate::stop()

std::string ModuleTemplate::decodeInterCommunication(const std::string message) {
    // add what you want for your module
    return message;
}

std::string ModuleTemplate::encodeInterCommunication(const std::string message) {
    // add what you want for your module
    return message;
}

#ifdef _WIN32 // If you are on windows
    extern "C" { // You need to use extern "C" to avoid name mangling
        __declspec(dllexport) AbstractModule* create_module(const std::string name, const std::string id) { // You need to use __declspec(dllexport) to export the function
            return new ModuleTemplate(name, id); // Return the module
        }
    }
#else // If you are on linux
    extern "C" { // You need to use extern "C" to avoid name mangling
        AbstractModule* create_module(const std::string name, const std::string id) { // The function to create the module that you will dlload
            return new ModuleTemplate(name, id); // Return the module
        }
    }
#endif // End the ifdef
