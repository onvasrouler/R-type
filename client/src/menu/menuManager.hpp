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
    void reloadMenu();

    void reloadOnChanges();

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void drawMenu() const;

    private:

    void createMenu(const nlohmann::json &menu);
    void eraseMenu();

    RaylibText createTexts(const nlohmann::json &text);
    GButton createButton(const nlohmann::json &button);
    GWindBox createWindBox(const nlohmann::json &windBox);
    GCheckBox createCheckBox(const nlohmann::json &checkBox);
    GSlider createSlider(const nlohmann::json &slider);
    GList createList(const nlohmann::json &list);
    GListEx createListEx(const nlohmann::json &listEx);
    GTextInput createInputText(const nlohmann::json &inputText);
    GTextInputBox createInputTextBox(const nlohmann::json &inputTextBox);
    GSpinner createSpinner(const nlohmann::json &spinner);
    GValueBox createValueBox(const nlohmann::json &valueBox);
    GGroup createGroup(const nlohmann::json &group);
    GToggleGroup createToggleGroup(const nlohmann::json &toggleGroup);
    GToggleSlider createToggleSlider(const nlohmann::json &toggleSlider);
    GPannel createPannel(const nlohmann::json &pannel);
    GColorPicker createColorPicker(const nlohmann::json &colorPicker);
    GProgressBar createProgressBar(const nlohmann::json &progressBar);
    GDropDown createDropDown(const nlohmann::json &dropDown);

    nlohmann::json _menuJson;

    menuType _type;
    std::shared_ptr<JsonParser> _jsonParser;

    std::map<menuType, std::shared_ptr<RGui>> _menuList;
};