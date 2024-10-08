/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiFunction
*/

#pragma once

#include "../../include.hpp"
#include "../../menu/menuManager.hpp"

class guiFunction {
public:
    guiFunction();
    guiFunction(std::shared_ptr<MenuManager> menu);
    ~guiFunction() = default;

    void setMenu(std::shared_ptr<MenuManager> menu);

    void helloFunction();

    void mapFunctions();
    void clearCache();

    std::unordered_map<std::string, std::function<void(const std::string&)>> getFunctionMap();
    std::function<void(const std::string&)> getFunction(const std::string functionName);

private:
    std::shared_ptr<MenuManager> _Menu;
    std::unordered_map<std::string, std::function<void(const std::string&)>> functionMap;

};