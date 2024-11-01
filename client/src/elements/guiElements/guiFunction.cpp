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
    custom_func(ExitButton, exit(0));
    custom_func(changeBgColor, {
        std::string color = this->_MenuManager->getCurrentGui()->GetValueById("backgroundColor");
        std::istringstream iss(color);
        int r;
        int g;
        int b;
        int a;

        iss >> r >> g >> b >> a;
        this->_MenuManager->setBackgroundColor(Color{static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), static_cast<unsigned char>(a)});
    });
    custom_func(GeneralSettingsButton, this->_MenuManager->setMenuType(2));
    custom_func(VideoSettingsButton, this->_MenuManager->setMenuType(3));
    custom_func(AudioSettingsButton, this->_MenuManager->setMenuType(4));
    custom_func(ControlsSettingsButton, this->_MenuManager->setMenuType(5));
    custom_func(StartFunct, {
        std::string ip = this->_MenuManager->getCurrentGui()->GetValueById("adressInput");
        std::string port = this->_MenuManager->getCurrentGui()->GetValueById("portInput");
        // // std::string username = this->_MenuManager->getCurrentGui()->GetValueById("usernameInput");

        this->_MenuManager->getCurrentGui()->GetElementById("InvalidAdressText")->setDisplay(false);
        this->_MenuManager->getCurrentGui()->GetElementById("InvalidPortText")->setDisplay(false);
        // // this->_MenuManager->getCurrentGui()->GetElementById("InvalidUsernameText")->setDisplay(false);
        // // if (username == "")
        // //     this->_MenuManager->getCurrentGui()->GetElementById("InvalidUsernameText")->setDisplay(true);
        if (!isIpValid(ip))
            this->_MenuManager->getCurrentGui()->GetElementById("InvalidAdressText")->setDisplay(true);
        if (!isPortValid(port))
            this->_MenuManager->getCurrentGui()->GetElementById("InvalidPortText")->setDisplay(true);
        if (isIpValid(ip) && isPortValid(port))
            this->_MenuManager->setGameInfo(ip, port); // mettre tout le haut en com et taper l'ip en statique ici pour pas avoir a la retaper a chaque fois
    });
}

void guiFunction::clearCache()
{
    _FunctionList.clear();
}

void guiFunction::setMenuManager(const std::shared_ptr<MenuManager> menumanager)
{
    this->_MenuManager = menumanager;
}

std::unordered_map<std::string, std::function<void()>> guiFunction::getFunctionMap()
{
    return _FunctionList;
}

std::function<void()> guiFunction::getFunction(const std::string functionName)
{
    if (_FunctionList.find(functionName) != _FunctionList.end())
        return _FunctionList[functionName];
    else
        return nullptr;
}
