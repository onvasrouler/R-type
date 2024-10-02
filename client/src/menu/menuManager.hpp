/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#pragma once

#include "../jsonParser/jsonParser.hpp"
#include "../elements/raylibText/raylibText.hpp"
#include "../elements/guiElements/gui.hpp"
#include "../elements/guiElements/guiElem.hpp"

#include "../include.hpp"


enum menuType {
    MAIN_MENU,
    SETTINGS_MENU,
    GAME_MENU,
    PAUSE_MENU,
    GAME_OVER_MENU
};

class MenuManager {
public:
    MenuManager();
    MenuManager(std::shared_ptr<JsonParser> jsonParser);
    ~MenuManager() = default;

    void setMenuType(menuType type);
    menuType getMenuType() const;

    void loadMenu();

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void drawMenu() const;

    private:

    void createMenu(const nlohmann::json &menu);
    RaylibText createTexts(const nlohmann::json &text);
    GButton createButton(const nlohmann::json &button);

    nlohmann::json _menuJson;

    menuType _type;
    std::shared_ptr<JsonParser> _jsonParser;

    std::map<menuType, std::shared_ptr<RGui>> _menuList;
};