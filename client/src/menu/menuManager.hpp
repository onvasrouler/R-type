/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#pragma once

#include "../jsonParser/jsonParser.hpp"
#include "../raylibText/raylibText.hpp"
#include <iostream>

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

    RaylibText createTtile(const nlohmann::json &text);

    nlohmann::json _menuJson;

    menuType _type;
    std::shared_ptr<JsonParser> _jsonParser;

    std::map<menuType, std::vector<RaylibText>> _menu;
};