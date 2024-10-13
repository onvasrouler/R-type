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

void guiFunction::mapFunctions()
{
    custom_func(printMessage, std::cout << "Hello from a dynamically created function!" << std::endl);
    custom_func(showGoodbye, std::cout << "Goodbye from a custom function!" << std::endl);
    custom_func(defaultFunct, std::cout << "Default function" << std::endl);
    custom_func(ExitButton, std::cout << "Exiting ..." << std::endl);
}

void guiFunction::clearCache()
{
    _FunctionList.clear();
}

std::unordered_map<std::string, std::function<void()>> guiFunction::getFunctionMap()
{
    return _FunctionList;
}

std::function<void()> guiFunction::getFunction(const std::string functionName)
{
    std::cout << "functionName : " << functionName << std::endl;
    if (_FunctionList.find(functionName) != _FunctionList.end()) {
        return _FunctionList[functionName];
    } else {
        return nullptr;
    }
}
