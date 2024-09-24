/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#include "menuManager.hpp"

MenuManager::MenuManager()
{
    this->_type = MAIN_MENU;
}

MenuManager::MenuManager(std::shared_ptr<JsonParser> jsonParser)
{
    this->_type = MAIN_MENU;
    this->_jsonParser = jsonParser;
    this->loadMenu();
}

void MenuManager::setMenuType(menuType type)
{
    _type = type;
}

enum menuType MenuManager::getMenuType() const
{
    return _type;
}

void MenuManager::loadMenu()
{
    _menuJson = _jsonParser->parseFile("./config/menu_settings.json");

    for (auto &menu : _menuJson["menus"]) {
        if (menu["isSimple"] == false)
            continue;
        menuType type = static_cast<menuType>(menu["id"]);
        std::vector<RaylibText> texts;
        texts.push_back(this->createTtile(menu));
        _menu[type] = texts;
    }
}

void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _jsonParser = jsonParser;
}

void MenuManager::drawMenu() const
{
    for (auto &text : _menu.at(_type)) {
        text.DrawRlibText();
    }
}

RaylibText MenuManager::createTtile(const nlohmann::json &text)
{
    return RaylibText(
        text["title"],
        10,
        10,
        40,
        BLACK
    );
}