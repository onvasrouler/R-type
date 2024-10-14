/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiFunction
*/

#include "guiFunction.hpp"
#include "../../menu/menuManager.hpp"

void guiFunction::mapFunctions()
{
    custom_func(printMessage, std::cout << "Hello from a dynamically created function!" << std::endl);
    custom_func(showGoodbye, std::cout << "Goodbye from a custom function!" << std::endl);
    custom_func(defaultFunct, std::cout << "Default function" << std::endl);
    custom_func(ExitButton, std::cout << "Exiting ..." << std::endl);
    custom_func(GeneralSettingsButton, this->_MenuManager->setMenuType(2));
    custom_func(VideoSettingsButton, this->_MenuManager->setMenuType(3));
    custom_func(AudioSettingsButton, this->_MenuManager->setMenuType(4));
    custom_func(ControlsSettingsButton, this->_MenuManager->setMenuType(5));
    custom_func(StartFunct, {
        std::string ip = this->_MenuManager->getCurrentGui()->GetValueById("adressInput");
        std::string port = this->_MenuManager->getCurrentGui()->GetValueById("portInput");
        if (!isIpValid(ip))
            this->_MenuManager->getCurrentGui()->GetTextsById("InvalidAdressText")->setDisplay(true);
        if (!isPortValid(port))
            this->_MenuManager->getCurrentGui()->GetTextsById("InvalidPortText")->setDisplay(true);
        if (isIpValid(ip) && isPortValid(port))
            std::cout << "Connecting to " << ip << ":" << port << std::endl;
    });
}

void guiFunction::clearCache()
{
    _FunctionList.clear();
}

void guiFunction::setMenuManager(std::shared_ptr<MenuManager> menumanager)
{
    this->_MenuManager = menumanager;
}

std::unordered_map<std::string, std::function<void()>> guiFunction::getFunctionMap()
{
    return _FunctionList;
}

std::function<void()> guiFunction::getFunction(const std::string functionName)
{
    if (_FunctionList.find(functionName) != _FunctionList.end()) {
        return _FunctionList[functionName];
    } else {
        return nullptr;
    }
}
