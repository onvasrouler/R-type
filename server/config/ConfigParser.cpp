/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ConfigParser.hpp"
#include <fstream>
#include <iostream>

ConfigParseModule::ConfigParseModule(const nlohmann::json module) {
    _module = module;
    try {
        _moduleName = module["name"];
    } catch (const std::exception& e) {
        _moduleName = "unknown";
    }
    try {
        _modulePath = module["path"];
    } catch (const std::exception& e) {
        _modulePath = "unknown";
    }
    try {
        std::vector<nlohmann::json> listen = module["listen_modules"];
        for (auto &module : listen) {
            _modulesListen.push_back(module["id"]);
        }
    } catch (const std::exception& e) {
        _modulesListen = {};
    }
}

const std::string ConfigParseModule::GetModule() const
{
    return _module.dump(4);
}

const std::string ConfigParseModule::GetModuleName() const
{
    return _moduleName;
}

const std::string ConfigParseModule::GetModulePath() const
{
    return _modulePath;
}

const std::vector<std::string> ConfigParseModule::GetModuleListen() const
{
    return _modulesListen;
}

void ConfigParser::ParseConfig(std::string path)
{
    std::cout << "path: " << path << std::endl;
    std::ifstream file(path);

    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    file >> _config;
    std::vector<nlohmann::json> modules = _config["modules"];
    for (auto &module : modules) {
        ConfigParseModule configModule(module);
        _modules.push_back(configModule);
    }
}

const nlohmann::json ConfigParser::GetConfig() const
{
    return _config;
}

const std::string ConfigParser::GetServerName() const
{
    return _config["name"];
}

const std::vector<ConfigParseModule> ConfigParser::GetModules() const
{
    return _modules;
}
