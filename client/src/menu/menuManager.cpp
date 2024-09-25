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
        if (!menu.is_null())
            this->createMenu(menu);
        
    }
}

void MenuManager::createMenu(const nlohmann::json &menu)
{
    try {
        menuType type = static_cast<menuType>(menu["id"]);
        std::vector<RaylibText> texts;
        std::vector<RaylibButton> buttons;
        if (menu.contains("texts"))
            for (auto &text : menu["texts"])
                texts.push_back(this->createTexts(text));
        if (menu.contains("buttons"))
            for (auto &button : menu["buttons"])
                buttons.push_back(this->createButton(button));
        _menuList[type] = std::make_shared<Menu>();
        _menuList[type]->setTexts(texts);
        _menuList[type]->setButtons(buttons);
    } catch (std::exception &e) {
        std::cerr << "invalid json : " << e.what() << std::endl;
    }
}


void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _jsonParser = jsonParser;
}

void MenuManager::drawMenu() const
{
    if (_menuList.find(_type) != _menuList.end())
        _menuList.at(_type)->drawMenu();
}

RaylibText MenuManager::createTexts(const nlohmann::json &text)
{
    try {
    return RaylibText(
        std::string(text["text"]),
        Vector2{text["position"]["x"], text["position"]["y"]},
        text["fontSize"],
        Color{text["color"]["r"], text["color"]["g"], text["color"]["b"], text["color"]["a"]}
    );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return RaylibText("error occured", Vector2{0, 0}, 0, Color{255, 0, 0, 255});
    }
}

RaylibButton MenuManager::createButton(const nlohmann::json &button)
{
    try {
    return RaylibButton(
        std::string(button["text"]),
        Vector2{button["position"]["x"], button["position"]["y"]},
        Vector2{button["size"]["width"], button["size"]["height"]},
        Color{button["color"]["r"], button["color"]["g"], button["color"]["b"], button["color"]["a"]},
        static_cast<ButtonType>(button["type"])
    );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return RaylibButton("error occured", Vector2{0, 0}, Vector2{0, 0}, Color{255, 0, 0, 255}, ButtonType::ERROR);
    }
}