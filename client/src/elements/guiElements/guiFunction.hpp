/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiFunction
*/

#pragma once

#include "../../include.hpp"

class MenuManager;

class guiFunction {
public:
    #define custom_func(name, body) \
    { \
        auto fn = [this]() { body; }; \
        _FunctionList[#name] = fn; \
    }

    guiFunction() = default;
    ~guiFunction() = default;

    void setMenuManager(std::shared_ptr<MenuManager> menumanager);

    void mapFunctions();
    void clearCache();

    std::unordered_map<std::string, std::function<void()>> getFunctionMap();
    std::function<void()> getFunction(const std::string functionName);

private:
    std::unordered_map<std::string, std::function<void()>> _FunctionList;
    std::shared_ptr<MenuManager> _MenuManager;
};
