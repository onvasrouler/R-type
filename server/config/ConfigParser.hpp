/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <nlohmann/json.hpp>

class ConfigParseModule {
    public:
        ConfigParseModule(const nlohmann::json module);
        ~ConfigParseModule() = default;
        const std::string GetModule() const;
        const std::string GetModuleName() const;
        const std::string GetModulePath() const;
        const std::vector<std::string> GetModuleListen() const;
    private:
        nlohmann::json _module;
        std::string _moduleName;
        std::string _modulePath;
        std::vector<std::string> _modulesListen;
};

class ConfigParser {
    public:
        ConfigParser() = default;
        ~ConfigParser() = default;
        void ParseConfig(const std::string path);
        const nlohmann::json GetConfig() const;
        const std::string GetServerName() const;
        const std::vector<ConfigParseModule> GetModules() const;
    private:
        nlohmann::json _config;
        std::string _serverName;
        std::vector<ConfigParseModule> _modules;
};
