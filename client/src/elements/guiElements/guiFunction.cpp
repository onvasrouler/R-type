/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiFunction
*/

#include "guiFunction.hpp"

guiFunction::guiFunction()
{
}

guiFunction::guiFunction(std::shared_ptr<MenuManager> menu)
{
    this->_Menu = menu;
}

void guiFunction::setMenu(std::shared_ptr<MenuManager> menu)
{
    this->_Menu = menu;
}

void guiFunction::helloFunction()
{
    std::cout << "Hello from guiFunction" << std::endl;
}

void guiFunction::mapFunctions()
{
    functionMap["hello"] = std::bind(&guiFunction::helloFunction, this);
}

void guiFunction::clearCache()
{
    functionMap.clear();
}

std::unordered_map<std::string, std::function<void(const std::string&)>> guiFunction::getFunctionMap()
{
    return functionMap;
}

std::function<void(const std::string&)> guiFunction::getFunction(const std::string functionName)
{
    if (functionMap.find(functionName) != functionMap.end()) {
        return functionMap[functionName];
    } else {
        return nullptr;
    }
}