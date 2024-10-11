/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#pragma once
#include "../include.hpp"


#include "../jsonParser/jsonParser.hpp"
#include "../elements/raylibText/raylibText.hpp"
#include "../elements/guiElements/gui.hpp"
#include "../elements/guiElements/guiElem.hpp"
#include "../elements/guiElements/guiFunction.hpp"

enum menuType {
    MAIN_MENU,
    START_MENU,
    SETTINGS_GENERAL,
    SETTINGS_VIDEO,
    SETTINGS_AUDIO,
    SETTINGS_CONTROLS,
    GAME_MENU,
    PAUSE_MENU,
    GAME_OVER_MENU
};

class MenuManager : public std::enable_shared_from_this<MenuManager> {
public:
    MenuManager();
    MenuManager(std::shared_ptr<JsonParser> jsonParser);
    ~MenuManager() = default;

    void setMenuType(menuType type);
    void setMenuType(int typeId);
    menuType getMenuType() const;

    void setGuiFunction(std::shared_ptr<guiFunction> guiFunction);

    void loadMenu();
    void reloadMenu();

    void reloadOnChanges();

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void drawMenu() const;

    std::shared_ptr<MenuManager> getThis();

    private:

    void createMenu(const nlohmann::json &menu, int menuID = 0);
    void integrateTemplate(const nlohmann::json &menu, int menuID = 0);
    void eraseMenu();

    RaylibText createTexts(const nlohmann::json &text, menuType type);
    GButton createButton(const nlohmann::json &button, menuType type);
    GWindBox createWindBox(const nlohmann::json &windBox, menuType type);
    GCheckBox createCheckBox(const nlohmann::json &checkBox, menuType type);
    GSlider createSlider(const nlohmann::json &slider, menuType type);
    GList createList(const nlohmann::json &list, menuType type);
    GListEx createListEx(const nlohmann::json &listEx, menuType type);
    GTextInput createInputText(const nlohmann::json &inputText, menuType type);
    GTextInputBox createInputTextBox(const nlohmann::json &inputTextBox, menuType type);
    GSpinner createSpinner(const nlohmann::json &spinner, menuType type);
    GValueBox createValueBox(const nlohmann::json &valueBox, menuType type);
    GGroup createGroup(const nlohmann::json &group, menuType type);
    GToggleGroup createToggleGroup(const nlohmann::json &toggleGroup, menuType type);
    GToggleSlider createToggleSlider(const nlohmann::json &toggleSlider, menuType type);
    GPannel createPannel(const nlohmann::json &pannel, menuType type);
    GColorPicker createColorPicker(const nlohmann::json &colorPicker, menuType type);
    GProgressBar createProgressBar(const nlohmann::json &progressBar, menuType type);
    GDropDown createDropDown(const nlohmann::json &dropDown, menuType type);

    std::vector<GButton> loadsButtons(const nlohmann::json &buttons, menuType type);
    std::vector<GWindBox> loadsWindBoxes(const nlohmann::json &windBoxes, menuType type);
    std::vector<RaylibText> loadsTexts(const nlohmann::json &texts, menuType type);
    std::vector<GCheckBox> loadsCheckBoxes(const nlohmann::json &checkBoxes, menuType type);
    std::vector<GSlider> loadsSliders(const nlohmann::json &sliders, menuType type);
    std::vector<GList> loadsLists(const nlohmann::json &lists, menuType type);
    std::vector<GListEx> loadsListExs(const nlohmann::json &listExs, menuType type);
    std::vector<GTextInput> loadsInputTexts(const nlohmann::json &inputTexts, menuType type);
    std::vector<GTextInputBox> loadsInputTextsBoxs(const nlohmann::json &inputTextsBoxs, menuType type);
    std::vector<GSpinner> loadsSpinners(const nlohmann::json &spinners, menuType type);
    std::vector<GValueBox> loadsValueBoxes(const nlohmann::json &valueBoxes, menuType type);
    std::vector<GGroup> loadsGroups(const nlohmann::json &groups, menuType type);
    std::vector<GToggleGroup> loadsToggleGroups(const nlohmann::json &toggleGroups, menuType type);
    std::vector<GToggleSlider> loadsToggleSliders(const nlohmann::json &toggleSliders, menuType type);
    std::vector<GPannel> loadsPannels(const nlohmann::json &pannels, menuType type);
    std::vector<GColorPicker> loadsColorPickers(const nlohmann::json &colorPickers, menuType type);
    std::vector<GProgressBar> loadsProgressBars(const nlohmann::json &progressBars, menuType type);
    std::vector<GDropDown> loadsDropDowns(const nlohmann::json &dropDowns, menuType type);

    void newMenuItems(int x, int y, int width, int length, std::string functionName, menuType type);

    nlohmann::json _menuJson;

    nlohmann::json _menuTemplate;

    menuType _type;
    std::shared_ptr<JsonParser> _jsonParser;

    std::map<menuType, std::shared_ptr<RGui>> _menuList;
    std::map<std::string, std::function<void(std::string)>> functionRegistry;

    std::shared_ptr<guiFunction> _guiFunction;

    struct MenuItem {
        int x;
        int y;
        int width;
        int length;
        std::string functionName;
    };

    std::map<menuType, std::vector<MenuItem>> _MenuItems;
};
