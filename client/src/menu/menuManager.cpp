/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#include "menuManager.hpp"
#include "../elements/guiElements/guiFunction.hpp"

MenuManager::MenuManager()
{
    this->_type = START_MENU;
    this->_WindowHeight = GetScreenHeight();
    this->_WindowWidth = GetScreenWidth();
}
MenuManager::MenuManager(std::shared_ptr<JsonParser> jsonParser)
{
    this->_type = START_MENU;
    this->_JsonParser = jsonParser;
}

void MenuManager::setMenuType(menuType type)
{
    this->_type = type;
}

void MenuManager::setMenuType(const int typeId)
{
    this->_type = static_cast<menuType>(typeId);
}


enum menuType MenuManager::getMenuType() const
{
    return this->_type;
}

void MenuManager::setWindowHeight(const int windowHeight)
{
    this->_WindowHeight = windowHeight;
}

void MenuManager::setWindowWidth(const int windowWidth)
{
    this->_WindowWidth = windowWidth;
}

void MenuManager::setWindowSize(const int windowWidth, const int windowHeight)
{
    this->_WindowWidth = windowWidth;
    this->_WindowHeight = windowHeight;
}

int MenuManager::getWindowHeight() const
{
    return this->_WindowHeight;
}

int MenuManager::getWindowWidth() const
{
    return this->_WindowWidth;
}

std::shared_ptr<MenuManager> MenuManager::getThis()
{
    return shared_from_this();
}

void MenuManager::setGuiFunction(std::shared_ptr<guiFunction> guifunction)
{
    this->_guiFunction = guifunction;
}

void MenuManager::loadMenu()
{
    this->_DebugLogger->Log("Loading Menu", 2);
    this->_menuJson = _JsonParser->parseFile("./config/menu_settings.json");
    this->_menuTemplate = _menuJson["templates"];

    this->_DebugLogger->Log("Menu Loaded creating every elements", 2);
    for (auto &menu : _menuJson["menus"]) {
        if (menu["isSimple"] == false)
            continue;
        if (!menu.is_null()) {
            menuType type = static_cast<menuType>(menu["id"]);
            this->_menuList[type] = std::make_shared<RGui>();
            this->integrateTemplate(menu, menu["id"]);
            this->createMenu(menu, menu["id"]);
        }
    }
}

void MenuManager::newMenuItems(const nlohmann::json_abi_v3_11_3::json &x, const nlohmann::json_abi_v3_11_3::json &y, const nlohmann::json_abi_v3_11_3::json &width, const nlohmann::json_abi_v3_11_3::json &length, std::string functionName, menuType type)
{
    this->_DebugLogger->Log("New menu item created : x = " + x.dump() + " y = " + y.dump() + " width = " + width.dump() + " length = " + length.dump() + " functionName = " + functionName, 5);
    MenuItem item;
    if (x.is_string())
        item.x = this->convertToRelativePosX(x.get<std::string>(), this->_WindowWidth);
    else if (x.is_number())
        item.x = x.get<int>();

    if (y.is_string())
        item.y = this->convertToRelativePosY(y.get<std::string>(), this->_WindowHeight);
    else if (y.is_number())
        item.y = y.get<int>();

    if (width.is_string())
        item.width = this->convertToRelativePosX(width.get<std::string>(), this->_WindowWidth);
    else if (width.is_number())
        item.width = width.get<int>();

    if (length.is_string())
        item.length = this->convertToRelativePosY(length.get<std::string>(), this->_WindowHeight);
    else if (length.is_number())
        item.length = length.get<int>();

    item.functionName = functionName;
    if (_MenuItems.find(type) == _MenuItems.end())
        _MenuItems[type] = std::vector<MenuItem>();
    this->_MenuItems[type].push_back(item);
}

std::shared_ptr<RGui> MenuManager::getCurrentGui() const
{
    return this->_menuList.at(this->_type);
}

void MenuManager::reloadMenu()
{
    this->_DebugLogger->Log("Menu Reloaded", 2);
    this->eraseMenu();
    this->loadMenu();
}

void MenuManager::reloadOnChanges()
{
    if (_JsonParser->fileHasChanged("./config/menu_settings.json"))
        this->reloadMenu();
}

void MenuManager::createMenu(const nlohmann::json &menu, const int menuID)
{
    try {
        menuType type = static_cast<menuType>(menuID);
        
        this->_menuList[type]->addListText(loadsTexts(menu, type));
        this->_menuList[type]->addListButton(loadsButtons(menu, type));
        this->_DebugLogger->Log("Creating WindBoxes", 4);
        this->_menuList[type]->addListWindBox(loadsWindBoxes(menu, type));
        this->_DebugLogger->Log("Creating CheckBoxes", 4);
        this->_menuList[type]->addListCheckBox(loadsCheckBoxes(menu, type));
        this->_DebugLogger->Log("Creating Sliders", 4);
        this->_menuList[type]->addListSlider(loadsSliders(menu, type));
        this->_DebugLogger->Log("Creating Lists", 4);
        this->_menuList[type]->addListList(loadsLists(menu, type));
        this->_DebugLogger->Log("Creating ListExs", 4);
        this->_menuList[type]->addListListEx(loadsListExs(menu, type));
        this->_DebugLogger->Log("Creating InputTexts", 4);
        this->_menuList[type]->addListInputText(loadsInputTexts(menu, type));
        this->_DebugLogger->Log("Creating InputTextBoxs", 4);
        this->_menuList[type]->addListInputTextBox(loadsInputTextsBoxs(menu, type));
        this->_DebugLogger->Log("Creating Spinners", 4);
        this->_menuList[type]->addListSpinner(loadsSpinners(menu, type));
        this->_DebugLogger->Log("Creating ValueBoxes", 4);
        this->_menuList[type]->addListValueBox(loadsValueBoxes(menu, type));
        this->_DebugLogger->Log("Creating Groups", 4);
        this->_menuList[type]->addListGroup(loadsGroups(menu, type));
        this->_DebugLogger->Log("Creating ToggleGroups", 4);
        this->_menuList[type]->addListToggleGroup(loadsToggleGroups(menu, type));
        this->_DebugLogger->Log("Creating ToggleSliders", 4);
        this->_menuList[type]->addListToggleSlider(loadsToggleSliders(menu, type));
        this->_DebugLogger->Log("Creating Pannels", 4);
        this->_menuList[type]->addListPannel(loadsPannels(menu, type));
        this->_DebugLogger->Log("Creating ColorPickers", 4);
        this->_menuList[type]->addListColorPicker(loadsColorPickers(menu, type));
        this->_DebugLogger->Log("Creating ProgressBars", 4);
        this->_menuList[type]->addListProgressBar(loadsProgressBars(menu, type));
        this->_DebugLogger->Log("Creating DropDowns", 4);
        this->_menuList[type]->addListDropDown(loadsDropDowns(menu, type));
    } catch (std::exception &e) {
        this->_DebugLogger->Log("invalid json : " + std::string(e.what()), 0);
    }
}

int MenuManager::convertToRelativePosX(std::string pos, const int windowWidth) const
{
    this->_DebugLogger->Log("Converting to relative pos X", 3);
    if (pos == "center")
        return windowWidth / 2;
    else if (pos.back() == '%') {
        pos.pop_back();
        float percentage = std::stof(pos) / 100.0f;
        return static_cast<int>(percentage * windowWidth);
    }
    return std::stoi(pos);
}

int MenuManager::convertToRelativePosX(std::string pos, const int width, const int windowWidth) const
{
    this->_DebugLogger->Log("Converting to relative pos X and takin in account the width of the elem", 3);
    if (pos == "center")
        return static_cast<int>((windowWidth / 2) - (width / 2));
    else if (pos.back() == '%') {
        pos.pop_back();
        float percentage = std::stof(pos) / 100.0f;
        return static_cast<int>((percentage * windowWidth) - (percentage * width / 2));
    }
    return std::stoi(pos);
}

int MenuManager::convertToRelativePosY(std::string pos, const int windowHeight) const
{
    this->_DebugLogger->Log("Converting to relative pos Y", 3);
    if (pos == "center")
        return static_cast<int>(windowHeight / 2);
    else if (pos.back() == '%') {
        pos.pop_back();
        float percentage = std::stof(pos) / 100.0f;
        return static_cast<int>(percentage * windowHeight);
    }
    return std::stoi(pos);
}

int MenuManager::convertToRelativePosY(std::string pos, const int height, const int windowHeight) const
{
    this->_DebugLogger->Log("Converting to relative pos Y and taking in account the height of the eleme", 3);
    if (pos == "center")
        return static_cast<int>((windowHeight / 2) - (height / 2));
    else if (pos.back() == '%') {
        pos.pop_back();
        float percentage = std::stof(pos) / 100.0f;
        return static_cast<int>((percentage * windowHeight) - (percentage * height / 2));
    }
    return std::stoi(pos);
}

Vector2 MenuManager::getRelativePos(const nlohmann::json &x, const nlohmann::json &y) const
{
    this->_DebugLogger->Log("Converting to relative pos", 3);
    Vector2 pos;

    if (x.is_string())
        pos.x = this->convertToRelativePosX(x.get<std::string>(), this->_WindowWidth);
    else if (x.is_number())
        pos.x = x.get<int>();

    if (y.is_string())
        pos.y = this->convertToRelativePosY(y.get<std::string>(), this->_WindowHeight);
    else if (y.is_number())
        pos.y = y.get<int>();

    return pos;
}

Vector2 MenuManager::getRelativePos(const nlohmann::json &x, const int width, const nlohmann::json &y, const int height) const
{
    this->_DebugLogger->Log("Converting to relative pos and taking in account the size of the elem", 3);
    Vector2 pos;

    if (x.is_string())
        pos.x = this->convertToRelativePosX(x.get<std::string>(), width, this->_WindowWidth);
    else if (x.is_number())
        pos.x = x.get<int>();

    if (y.is_string())
        pos.y = this->convertToRelativePosY(y.get<std::string>(), height, this->_WindowHeight);
    else if (y.is_number())
        pos.y = y.get<int>();

    return pos;
}

std::vector<std::shared_ptr<GButton>> MenuManager::loadsButtons(const nlohmann::json &jsonbuttons, menuType type)
{
    std::vector<std::shared_ptr<GButton>> buttons;

    this->_DebugLogger->Log("Creating Buttons", 4);
    if (jsonbuttons.contains("buttons"))
        for (auto &button : jsonbuttons["buttons"])
            buttons.push_back(this->createButtons(button, type));
    return buttons;
}

std::vector<std::shared_ptr<GWindBox>> MenuManager::loadsWindBoxes(const nlohmann::json &jsonWindBoxes, menuType type)
{
    std::vector<std::shared_ptr<GWindBox>> windBoxes;

    this->_DebugLogger->Log("Creating WindBoxes", 4);
    if (jsonWindBoxes.contains("windBoxes"))
        for (auto &windBox : jsonWindBoxes["windBoxes"])
            windBoxes.push_back(this->createWindBox(windBox, type));
    return windBoxes;
}

std::vector<std::shared_ptr<RaylibText>> MenuManager::loadsTexts(const nlohmann::json &jsonTexts, menuType type)
{
    std::vector<std::shared_ptr<RaylibText>> texts;

    this->_DebugLogger->Log("Creating List Texts", 4);
    if (jsonTexts.contains("texts"))
        for (auto &text : jsonTexts["texts"])
            texts.push_back(this->createTexts(text, type));
    return texts;
}

std::vector<std::shared_ptr<GCheckBox>> MenuManager::loadsCheckBoxes(const nlohmann::json &jsonCheckBoxes, menuType type)
{
    std::vector<std::shared_ptr<GCheckBox>> checkBoxes;

    this->_DebugLogger->Log("Creating CheckBoxes", 4);
    if (jsonCheckBoxes.contains("checkBoxes"))
        for (auto &checkBox : jsonCheckBoxes["checkBoxes"])
            checkBoxes.push_back(this->createCheckBoxes(checkBox, type));
    return checkBoxes;
}

std::vector<std::shared_ptr<GSlider>> MenuManager::loadsSliders(const nlohmann::json &jsonSliders, menuType type)
{
    std::vector<std::shared_ptr<GSlider>> sliders;

    this->_DebugLogger->Log("Creating Sliders", 4);
    if (jsonSliders.contains("sliders"))
        for (auto &slider : jsonSliders["sliders"])
            sliders.push_back(this->createSliders(slider, type));
    return sliders;
}

std::vector<std::shared_ptr<GList>> MenuManager::loadsLists(const nlohmann::json &jsonLists, menuType type)
{
    std::vector<std::shared_ptr<GList>> lists;

    this->_DebugLogger->Log("Creating Lists", 4);
    if (jsonLists.contains("lists"))
        for (auto &list : jsonLists["lists"])
            lists.push_back(this->createLists(list, type));
    return lists;
}

std::vector<std::shared_ptr<GListEx>> MenuManager::loadsListExs(const nlohmann::json &jsonListExs, menuType type)
{
    std::vector<std::shared_ptr<GListEx>> listExs;

    this->_DebugLogger->Log("Creating ListExs", 4);
    if (jsonListExs.contains("listExs"))
        for (auto &listEx : jsonListExs["listExs"])
            listExs.push_back(this->createListExs(listEx, type));
    return listExs;
}

std::vector<std::shared_ptr<GTextInput>> MenuManager::loadsInputTexts(const nlohmann::json &jsonInputTexts, menuType type)
{
    std::vector<std::shared_ptr<GTextInput>> inputTexts;

    this->_DebugLogger->Log("Creating InputTexts", 4);
    if (jsonInputTexts.contains("inputTexts"))
        for (auto &inputText : jsonInputTexts["inputTexts"])
            inputTexts.push_back(this->createInputTexts(inputText, type));
    return inputTexts;
}

std::vector<std::shared_ptr<GTextInputBox>> MenuManager::loadsInputTextsBoxs(const nlohmann::json &jsonInputTextBoxs, menuType type)
{
    std::vector<std::shared_ptr<GTextInputBox>> inputTextBoxs;

    this->_DebugLogger->Log("Creating InputTextBoxs", 4);
    if (jsonInputTextBoxs.contains("inputTextBoxs"))
        for (auto &inputTextBox : jsonInputTextBoxs["inputTextBoxs"])
            inputTextBoxs.push_back(this->createInputTextsBoxs(inputTextBox, type));
    return inputTextBoxs;
}

std::vector<std::shared_ptr<GSpinner>> MenuManager::loadsSpinners(const nlohmann::json &jsonSpinners, menuType type)
{
    std::vector<std::shared_ptr<GSpinner>> spinners;

    this->_DebugLogger->Log("Creating Spinners", 4);
    if (jsonSpinners.contains("spinners"))
        for (auto &spinner : jsonSpinners["spinners"])
            spinners.push_back(this->createSpinners(spinner, type));
    return spinners;
}

std::vector<std::shared_ptr<GValueBox>> MenuManager::loadsValueBoxes(const nlohmann::json &jsonValueBoxes, menuType type)
{
    std::vector<std::shared_ptr<GValueBox>> valueBoxes;

    this->_DebugLogger->Log("Creating ValueBoxes", 4);
    if (jsonValueBoxes.contains("valueBoxes"))
        for (auto &valueBox : jsonValueBoxes["valueBoxes"])
            valueBoxes.push_back(this->createValueBoxes(valueBox, type));
    return valueBoxes;
}

std::vector<std::shared_ptr<GGroup>> MenuManager::loadsGroups(const nlohmann::json &jsonGroups, menuType type)
{
    std::vector<std::shared_ptr<GGroup>> groups;

    this->_DebugLogger->Log("Creating Groups", 4);
    if (jsonGroups.contains("groups"))
        for (auto &group : jsonGroups["groups"])
            groups.push_back(this->createGroups(group, type));
    return groups;
}

std::vector<std::shared_ptr<GToggleGroup>> MenuManager::loadsToggleGroups(const nlohmann::json &jsonToggleGroups, menuType type)
{
    std::vector<std::shared_ptr<GToggleGroup>> toggleGroups;

    this->_DebugLogger->Log("Creating ToggleGroups", 4);
    if (jsonToggleGroups.contains("toggleGroups"))
        for (auto &toggleGroup : jsonToggleGroups["toggleGroups"])
            toggleGroups.push_back(this->createToggleGroups(toggleGroup, type));
    return toggleGroups;
}

std::vector<std::shared_ptr<GToggleSlider>> MenuManager::loadsToggleSliders(const nlohmann::json &jsonToggleSliders, menuType type)
{
    std::vector<std::shared_ptr<GToggleSlider>> toggleSliders;

    this->_DebugLogger->Log("Creating ToggleSliders", 4);
    if (jsonToggleSliders.contains("toggleSliders"))
        for (auto &toggleSlider : jsonToggleSliders["toggleSliders"])
            toggleSliders.push_back(this->createToggleSliders(toggleSlider, type));
    return toggleSliders;
}

std::vector<std::shared_ptr<GPannel>> MenuManager::loadsPannels(const nlohmann::json &jsonPannels, menuType type)
{
    std::vector<std::shared_ptr<GPannel>> pannels;

    this->_DebugLogger->Log("Creating Pannels", 4);
    if (jsonPannels.contains("pannels"))
        for (auto &pannel : jsonPannels["pannels"])
            pannels.push_back(this->createPannels(pannel, type));
    return pannels;
}

std::vector<std::shared_ptr<GColorPicker>> MenuManager::loadsColorPickers(const nlohmann::json &jsonColorPickers, menuType type)
{
    std::vector<std::shared_ptr<GColorPicker>> colorPickers;

    this->_DebugLogger->Log("Creating ColorPickers", 4);
    if (jsonColorPickers.contains("colorPickers"))
        for (auto &colorPicker : jsonColorPickers["colorPickers"])
            colorPickers.push_back(this->createColorPickers(colorPicker, type));
    return colorPickers;
}

std::vector<std::shared_ptr<GProgressBar>> MenuManager::loadsProgressBars(const nlohmann::json &jsonProgressBars, menuType type)
{
    std::vector<std::shared_ptr<GProgressBar>> progressBars;

    this->_DebugLogger->Log("Creating ProgressBars", 4);
    if (jsonProgressBars.contains("progressBars"))
        for (auto &progressBar : jsonProgressBars["progressBars"])
            progressBars.push_back(this->createProgressBars(progressBar, type));
    return progressBars;
}

std::vector<std::shared_ptr<GDropDown>> MenuManager::loadsDropDowns(const nlohmann::json &jsonDropDowns, menuType type)
{
    std::vector<std::shared_ptr<GDropDown>> dropDowns;

    this->_DebugLogger->Log("Creating DropDowns", 4);
    if (jsonDropDowns.contains("dropDowns"))
        for (auto &dropDown : jsonDropDowns["dropDowns"])
            dropDowns.push_back(this->createDropDowns(dropDown, type));
    return dropDowns;
}

void MenuManager::integrateTemplate(const nlohmann::json &menu, const int menuID)
{
    this->_DebugLogger->Log("Integrating template", 3);
    if (menu.contains("templates")) {
        for (auto &templateID : menu["templates"]) {
            if (_menuTemplate.contains(templateID)) {
                this->createMenu(_menuTemplate[templateID], menuID);
            }
        }
    }
}

void MenuManager::eraseMenu()
{
    this->_DebugLogger->Log("Erasing Menu", 1);
    this->_menuList.clear();
    this->_JsonParser->eraseCache("./config/menu_settings.json");
}

void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    this->_JsonParser = jsonParser;
}

void MenuManager::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    this->_DebugLogger = debugLogger;
    this->_DebugLogger->Log("MenuManager DebugLogger setted");
}

void MenuManager::drawMenu() const
{
    this->_DebugLogger->Log("Drawing menu", 2);
    if (this->_menuList.find(_type) != this->_menuList.end())
        this->_menuList.at(_type)->DrawGui();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        for (auto &item : this->_MenuItems.at(_type)) {
            if (CheckCollisionPointRec(mousePosition, Rectangle{static_cast<float>(item.x), static_cast<float>(item.y), static_cast<float>(item.width), static_cast<float>(item.length)})) {
                std::function<void()> func = _guiFunction->getFunction(item.functionName);
                if (func != nullptr)
                    func();
            }
        }
    }
}

bool MenuManager::jsonToBool(const nlohmann::json &json) const
{
    if (json.is_string()) {
        if (json == "true")
            return true;
        return false;
    }
    return json.get<bool>();
}

std::shared_ptr<RaylibText> MenuManager::createTexts(const nlohmann::json &text, menuType type)
{
    this->_DebugLogger->Log("Creating Text : " + text.dump(), 5);
    try {
        this->newMenuItems(text["position"]["x"], text["position"]["y"], text["text"].get<std::string>().length() * (text["fontSize"].get<int>() / 2), text["fontSize"], text["functionName"], type);
        return std::make_shared<RaylibText>(
            text["text"].get<std::string>(),
            getRelativePos(text["position"]["x"], text["text"].get<std::string>().length() * (text["fontSize"].get<int>() / 2), text["position"]["y"], text["fontSize"]),
            text["fontSize"],
            Color{text["color"]["r"], text["color"]["g"], text["color"]["b"], text["color"]["a"]},
            text["id"].get<std::string>(),
            text["display"]
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<RaylibText>(errorText, getRelativePos(defaultErrorPosX, defaultErrorPosY), 0, Color{255, 0, 0, 255}, "errorId", true);
    }
}

std::shared_ptr<GButton> MenuManager::createButtons(const nlohmann::json &button, menuType type)
{
    this->_DebugLogger->Log("Creating Button : " + button.dump(), 5);
    try {
        this->newMenuItems(button["position"]["x"], button["position"]["y"], button["size"]["width"], button["size"]["height"], button["functionName"], type);
        return std::make_shared<GButton>(
            getRelativePos(button["position"]["x"], button["position"]["y"]),
            getRelativePos(button["size"]["width"], button["size"]["height"]),
            std::string(button["text"]),
            button["id"].get<std::string>(),
            jsonToBool(button["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GButton>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", true);
    }
}

std::shared_ptr<GWindBox> MenuManager::createWindBox(const nlohmann::json &windBox, menuType type)
{
    this->_DebugLogger->Log("Creating WindBox : " + windBox.dump(), 5);
    try {
        this->newMenuItems(windBox["position"]["x"], windBox["position"]["y"], windBox["size"]["width"], windBox["size"]["height"], windBox["functionName"], type);
        return std::make_shared<GWindBox>(
            getRelativePos(windBox["position"]["x"], windBox["position"]["y"]),
            getRelativePos(windBox["size"]["width"], windBox["size"]["height"]),
            std::string(windBox["text"]),
            windBox["id"].get<std::string>(),
            jsonToBool(windBox["isOpened"]),
            jsonToBool(windBox["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GWindBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", false, true);
    }
}

std::shared_ptr<GCheckBox> MenuManager::createCheckBoxes(const nlohmann::json &checkBox, menuType type)
{
    this->_DebugLogger->Log("Creating CheckBox : " + checkBox.dump(), 5);
    try {
        this->newMenuItems(checkBox["position"]["x"], checkBox["position"]["y"], checkBox["size"]["width"], checkBox["size"]["height"], checkBox["functionName"], type);
        return std::make_shared<GCheckBox>(
            getRelativePos(checkBox["position"]["x"], checkBox["position"]["y"]),
            getRelativePos(checkBox["size"]["width"], checkBox["size"]["height"]),
            std::string(checkBox["text"]),
            checkBox["id"].get<std::string>(),
            checkBox["isChecked"],
            jsonToBool(checkBox["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GCheckBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "defaultId", false, true);
    }
}

std::shared_ptr<GSlider> MenuManager::createSliders(const nlohmann::json &slider, menuType type)
{
    this->_DebugLogger->Log("Creating Slider : " + slider.dump(), 5);
    try {
        this->newMenuItems(slider["position"]["x"], slider["position"]["y"], slider["size"]["width"], slider["size"]["height"], slider["functionName"], type);
        return std::make_shared<GSlider>(
            getRelativePos(slider["position"]["x"], slider["position"]["y"]),
            getRelativePos(slider["size"]["width"], slider["size"]["height"]),
            std::string(slider["text"]),
            slider["id"].get<std::string>(),
            slider["value"],
            slider["minValue"],
            slider["maxValue"],
            jsonToBool(slider["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GSlider>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", 0.0F, 0.0F, 0.0F, true);
    }
}

std::shared_ptr<GList> MenuManager::createLists(const nlohmann::json &list, menuType type)
{
    this->_DebugLogger->Log("Creating List : " + list.dump(), 5);
    try {
        this->newMenuItems(list["position"]["x"], list["position"]["y"], list["size"]["width"], list["size"]["height"], list["functionName"], type);
        return std::make_shared<GList>(
            getRelativePos(list["position"]["x"], list["position"]["y"]),
            getRelativePos(list["size"]["width"], list["size"]["height"]),
            std::string(list["text"]),
            list["id"].get<std::string>(),
            jsonToBool(list["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GList>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", true);
    }
}

std::shared_ptr<GListEx> MenuManager::createListExs(const nlohmann::json &listEx, menuType type)
{
    this->_DebugLogger->Log("Creating ListEx : " + listEx.dump(), 5);
    try {
        this->newMenuItems(listEx["position"]["x"], listEx["position"]["y"], listEx["size"]["width"], listEx["size"]["height"], listEx["functionName"], type);
        std::vector<std::string> list = listEx["list"];
        return std::make_shared<GListEx>(
            getRelativePos(listEx["position"]["x"], listEx["position"]["y"]),
            getRelativePos(listEx["size"]["width"], listEx["size"]["height"]),
            listEx["id"].get<std::string>(),
            list,
            listEx["active"],
            jsonToBool(listEx["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GListEx>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, "defaultId", std::vector<std::string>{errorText}, 0, true);
    }
}

std::shared_ptr<GTextInput> MenuManager::createInputTexts(const nlohmann::json &inputText, menuType type)
{
    this->_DebugLogger->Log("Creating InputText : " + inputText.dump(), 5);
    try {
        this->newMenuItems(inputText["position"]["x"], inputText["position"]["y"], inputText["size"]["width"], inputText["size"]["height"], inputText["functionName"], type);
        return std::make_shared<GTextInput>(
            getRelativePos(inputText["position"]["x"], inputText["position"]["y"]),
            getRelativePos(inputText["size"]["width"], inputText["size"]["height"]),
            std::string(inputText["text"]),
            inputText["id"].get<std::string>(),
            inputText["textMaxSize"],
            inputText["editMode"],
            jsonToBool(inputText["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GTextInput>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "default", 0, false, true);
    }
}

std::shared_ptr<GTextInputBox> MenuManager::createInputTextsBoxs(const nlohmann::json &inputTextBox, menuType type)
{
    this->_DebugLogger->Log("Creating InputTextBox : " + inputTextBox.dump(), 5);
    try {
        this->newMenuItems(inputTextBox["position"]["x"], inputTextBox["position"]["y"], inputTextBox["size"]["width"], inputTextBox["size"]["height"], inputTextBox["functionName"], type);
        return std::make_shared<GTextInputBox>(
            getRelativePos(inputTextBox["position"]["x"], inputTextBox["position"]["y"]),
            getRelativePos(inputTextBox["size"]["width"], inputTextBox["size"]["height"]),
            inputTextBox["id"].get<std::string>(),
            std::string(inputTextBox["title"]),
            std::string(inputTextBox["message"]),
            std::string(inputTextBox["buttons"]),
            std::string(inputTextBox["text"]),
            inputTextBox["textMaxSize"],
            inputTextBox["secretViewActive"],
            jsonToBool(inputTextBox["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GTextInputBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, "defaultId", "default title", "default message", "default buttons", "default text", 0, false, true);
    }
}

std::shared_ptr<GSpinner> MenuManager::createSpinners(const nlohmann::json &spinner, menuType type)
{
    this->_DebugLogger->Log("Creating Spinner : " + spinner.dump(), 5);
    try {
        this->newMenuItems(spinner["position"]["x"], spinner["position"]["y"], spinner["size"]["width"], spinner["size"]["height"], spinner["functionName"], type);
        return std::make_shared<GSpinner>(
            getRelativePos(spinner["position"]["x"], spinner["position"]["y"]),
            getRelativePos(spinner["size"]["width"], spinner["size"]["height"]),
            std::string(spinner["text"]),
            spinner["id"].get<std::string>(),
            spinner["value"],
            spinner["minValue"],
            spinner["maxValue"],
            spinner["editMode"],
            jsonToBool(spinner["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GSpinner>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", 0, 0, 0, false, true);
    }
}

std::shared_ptr<GValueBox> MenuManager::createValueBoxes(const nlohmann::json &valueBox, menuType type)
{
    this->_DebugLogger->Log("Creating ValueBox : " + valueBox.dump(), 5);
    try {
        this->newMenuItems(valueBox["position"]["x"], valueBox["position"]["y"], valueBox["size"]["width"], valueBox["size"]["height"], valueBox["functionName"], type);
        return std::make_shared<GValueBox>(
            getRelativePos(valueBox["position"]["x"], valueBox["position"]["y"]),
            getRelativePos(valueBox["size"]["width"], valueBox["size"]["height"]),
            std::string(valueBox["text"]),
            valueBox["id"].get<std::string>(),
            valueBox["value"],
            valueBox["minValue"],
            valueBox["maxValue"],
            valueBox["editMode"],
            jsonToBool(valueBox["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GValueBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId",0, 0, 0, false, true);
    }
}

std::shared_ptr<GGroup> MenuManager::createGroups(const nlohmann::json &group, menuType type)
{
    this->_DebugLogger->Log("Creating Group : " + group.dump(), 5);
    try {
        this->newMenuItems(group["position"]["x"], group["position"]["y"], group["size"]["width"], group["size"]["height"], group["functionName"], type);
        return std::make_shared<GGroup>(
            getRelativePos(group["position"]["x"], group["position"]["y"]),
            getRelativePos(group["size"]["width"], group["size"]["height"]),
            std::string(group["text"]),
            group["id"].get<std::string>(),
            jsonToBool(group["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GGroup>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorID", true);
    }
}

std::shared_ptr<GToggleGroup> MenuManager::createToggleGroups(const nlohmann::json &toggleGroup, menuType type)
{
    this->_DebugLogger->Log("Creating ToggleGroup : " + toggleGroup.dump(), 5);
    try {
        this->newMenuItems(toggleGroup["position"]["x"], toggleGroup["position"]["y"], toggleGroup["size"]["width"], toggleGroup["size"]["height"], toggleGroup["functionName"], type);
        return std::make_shared<GToggleGroup>(
            getRelativePos(toggleGroup["position"]["x"], toggleGroup["position"]["y"]),
            getRelativePos(toggleGroup["size"]["width"], toggleGroup["size"]["height"]),
            std::string(toggleGroup["text"]),
            toggleGroup["id"].get<std::string>(),
            toggleGroup["active"],
            jsonToBool(toggleGroup["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GToggleGroup>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", 0, true);
    }
}

std::shared_ptr<GToggleSlider> MenuManager::createToggleSliders(const nlohmann::json &toggleSlider, menuType type)
{
    this->_DebugLogger->Log("Creating ToggleSlider : " + toggleSlider.dump(), 5);
    try {
        this->newMenuItems(toggleSlider["position"]["x"], toggleSlider["position"]["y"], toggleSlider["size"]["width"], toggleSlider["size"]["height"], toggleSlider["functionName"], type);
        return std::make_shared<GToggleSlider>(
            getRelativePos(toggleSlider["position"]["x"], toggleSlider["position"]["y"]),
            getRelativePos(toggleSlider["size"]["width"], toggleSlider["size"]["height"]),
            std::string(toggleSlider["text"]),
            toggleSlider["id"].get<std::string>(),
            toggleSlider["active"],
            jsonToBool(toggleSlider["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GToggleSlider>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", 0, true);
    }
}

std::shared_ptr<GPannel> MenuManager::createPannels(const nlohmann::json &pannel, menuType type)
{
    this->_DebugLogger->Log("Creating Pannel : " + pannel.dump(), 5);
    try {
        this->newMenuItems(pannel["position"]["x"], pannel["position"]["y"], pannel["size"]["width"], pannel["size"]["height"], pannel["functionName"], type);
        return std::make_shared<GPannel>(
            getRelativePos(pannel["position"]["x"], pannel["position"]["y"]),
            getRelativePos(pannel["size"]["width"], pannel["size"]["height"]),
            std::string(pannel["text"]),
            pannel["id"].get<std::string>(),
            jsonToBool(pannel["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GPannel>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", true);
    }
}

std::shared_ptr<GColorPicker> MenuManager::createColorPickers(const nlohmann::json &colorPicker, menuType type)
{
    this->_DebugLogger->Log("Creating ColorPicker : " + colorPicker.dump(), 5);
    try {
        this->newMenuItems(colorPicker["position"]["x"], colorPicker["position"]["y"], colorPicker["size"]["width"], colorPicker["size"]["height"], colorPicker["functionName"], type);
        return std::make_shared<GColorPicker>(
            getRelativePos(colorPicker["position"]["x"], colorPicker["position"]["y"]),
            getRelativePos(colorPicker["size"]["width"], colorPicker["size"]["height"]),
            std::string(colorPicker["text"]),
            colorPicker["id"].get<std::string>(),
            Color{colorPicker["color"]["r"], colorPicker["color"]["g"], colorPicker["color"]["b"], colorPicker["color"]["a"]},
            jsonToBool(colorPicker["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GColorPicker>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, "errorId", Color{0, 0, 0, 0}, true);
    }
}

std::shared_ptr<GProgressBar> MenuManager::createProgressBars(const nlohmann::json &progressBar, menuType type)
{
    this->_DebugLogger->Log("Creating ProgressBar : " + progressBar.dump(), 5);
    try {
        this->newMenuItems(progressBar["position"]["x"], progressBar["position"]["y"], progressBar["size"]["width"], progressBar["size"]["height"], progressBar["functionName"], type);
        return std::make_shared<GProgressBar>(
            getRelativePos(progressBar["position"]["x"], progressBar["position"]["y"]),
            getRelativePos(progressBar["size"]["width"], progressBar["size"]["height"]),
            progressBar["id"].get<std::string>(),
            std::string(progressBar["textLeft"]),
            std::string(progressBar["textRight"]),
            progressBar["value"],
            progressBar["minValue"],
            progressBar["maxValue"],
            jsonToBool(progressBar["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GProgressBar>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, "errorId", errorText, errorText, 0, 0, 0, true);
    }
}

std::shared_ptr<GDropDown> MenuManager::createDropDowns(const nlohmann::json &dropDown, menuType type)
{
    this->_DebugLogger->Log("Creating DropDown : " + dropDown.dump(), 5);
    try {
        this->newMenuItems(dropDown["position"]["x"], dropDown["position"]["y"], dropDown["size"]["width"], dropDown["size"]["height"], dropDown["functionName"], type);
        return std::make_shared<GDropDown>(
            getRelativePos(dropDown["position"]["x"], dropDown["position"]["y"]),
            getRelativePos(dropDown["size"]["width"], dropDown["size"]["height"]),
            std::string(dropDown["text"]),
            dropDown["id"].get<std::string>(),
            dropDown["active"],
            jsonToBool(dropDown["editMode"]),
            jsonToBool(dropDown["display"])
        );
    } catch (std::exception &e) {
        this->_DebugLogger->Log("error occured  : " + std::string(e.what()), 0);
    
std::string errorText = "error occured : " + std::string(e.what());
        return std::make_shared<GDropDown>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, "error;occured", "errorId", 0, false, true);
    }
}
