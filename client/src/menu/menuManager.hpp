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

    void setWindowHeight(int windowHeight);
    void setWindowWidth(int windowWidth);
    void setWindowSize(int windowWidth, int windowHeight);

    int getWindowHeight() const;
    int getWindowWidth() const;

    void setGuiFunction(std::shared_ptr<guiFunction> guiFunction);

    void loadMenu();
    void reloadMenu();

    void reloadOnChanges();

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void drawMenu() const;

    std::shared_ptr<MenuManager> getThis();

    Vector2 getRelativePos(const nlohmann::json_abi_v3_11_3::json &x, const nlohmann::json_abi_v3_11_3::json &y);

    int convertToRelativePosX(std::string pos, int windowWidth);
    int convertToRelativePosY(std::string pos, int windowHeight);

    std::shared_ptr<RGui> getCurrentGui() const;

    bool jsonToBool(const nlohmann::json &json) const;

    private:

    void createMenu(const nlohmann::json &menu, int menuID = 0);
    void integrateTemplate(const nlohmann::json &menu, int menuID = 0);
    void eraseMenu();

    std::shared_ptr<RaylibText> createTexts(const nlohmann::json &text, menuType type);
    std::shared_ptr<GButton> createButtons(const nlohmann::json &button, menuType type); 
    std::shared_ptr<GWindBox> createWindBox(const nlohmann::json &windBox, menuType type);
    std::shared_ptr<GCheckBox> createCheckBoxes(const nlohmann::json &checkBox, menuType type);
    std::shared_ptr<GSlider> createSliders(const nlohmann::json &slider, menuType type);
    std::shared_ptr<GList> createLists(const nlohmann::json &list, menuType type);
    std::shared_ptr<GListEx> createListExs(const nlohmann::json &listEx, menuType type);
    std::shared_ptr<GTextInput> createInputTexts(const nlohmann::json &inputText, menuType type);
    std::shared_ptr<GTextInputBox> createInputTextsBoxs(const nlohmann::json &inputTextBox, menuType type);
    std::shared_ptr<GSpinner> createSpinners(const nlohmann::json &spinner, menuType type);
    std::shared_ptr<GValueBox> createValueBoxes(const nlohmann::json &valueBox, menuType type);
    std::shared_ptr<GGroup> createGroups(const nlohmann::json &group, menuType type);
    std::shared_ptr<GToggleGroup> createToggleGroups(const nlohmann::json &toggleGroup, menuType type);
    std::shared_ptr<GToggleSlider> createToggleSliders(const nlohmann::json &toggleSlider, menuType type);
    std::shared_ptr<GPannel> createPannels(const nlohmann::json &pannel, menuType type);
    std::shared_ptr<GColorPicker> createColorPickers(const nlohmann::json &colorPicker, menuType type);
    std::shared_ptr<GProgressBar> createProgressBars(const nlohmann::json &progressBar, menuType type);
    std::shared_ptr<GDropDown> createDropDowns(const nlohmann::json &dropDown, menuType type);

    std::vector<std::shared_ptr<GButton>> loadsButtons(const nlohmann::json &buttons, menuType type);
    std::vector<std::shared_ptr<GWindBox>> loadsWindBoxes(const nlohmann::json &windBoxes, menuType type);
    std::vector<std::shared_ptr<RaylibText>> loadsTexts(const nlohmann::json &texts, menuType type);
    std::vector<std::shared_ptr<GCheckBox>> loadsCheckBoxes(const nlohmann::json &checkBoxes, menuType type);
    std::vector<std::shared_ptr<GSlider>> loadsSliders(const nlohmann::json &sliders, menuType type);
    std::vector<std::shared_ptr<GList>> loadsLists(const nlohmann::json &lists, menuType type);
    std::vector<std::shared_ptr<GListEx>> loadsListExs(const nlohmann::json &listExs, menuType type);
    std::vector<std::shared_ptr<GTextInput>> loadsInputTexts(const nlohmann::json &inputTexts, menuType type);
    std::vector<std::shared_ptr<GTextInputBox>> loadsInputTextsBoxs(const nlohmann::json &inputTextsBoxs, menuType type);
    std::vector<std::shared_ptr<GSpinner>> loadsSpinners(const nlohmann::json &spinners, menuType type);
    std::vector<std::shared_ptr<GValueBox>> loadsValueBoxes(const nlohmann::json &valueBoxes, menuType type);
    std::vector<std::shared_ptr<GGroup>> loadsGroups(const nlohmann::json &groups, menuType type);
    std::vector<std::shared_ptr<GToggleGroup>> loadsToggleGroups(const nlohmann::json &toggleGroups, menuType type);
    std::vector<std::shared_ptr<GToggleSlider>> loadsToggleSliders(const nlohmann::json &toggleSliders, menuType type);
    std::vector<std::shared_ptr<GPannel>> loadsPannels(const nlohmann::json &pannels, menuType type);
    std::vector<std::shared_ptr<GColorPicker>> loadsColorPickers(const nlohmann::json &colorPickers, menuType type);
    std::vector<std::shared_ptr<GProgressBar>> loadsProgressBars(const nlohmann::json &progressBars, menuType type);
    std::vector<std::shared_ptr<GDropDown>> loadsDropDowns(const nlohmann::json &dropDowns, menuType type);

    void newMenuItems(const nlohmann::json_abi_v3_11_3::json &x, const nlohmann::json_abi_v3_11_3::json &y, const nlohmann::json_abi_v3_11_3::json &width, const nlohmann::json_abi_v3_11_3::json &length, std::string functionName, menuType type);

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

    int _WindowWidth;
    int _WindowHeight;
};
