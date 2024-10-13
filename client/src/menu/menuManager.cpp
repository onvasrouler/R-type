/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#include "menuManager.hpp"

MenuManager::MenuManager()
{
    this->_type = SETTINGS_GENERAL;
    this->_guiFunction = std::make_shared<guiFunction>();
}
MenuManager::MenuManager(std::shared_ptr<JsonParser> jsonParser)
{
    this->_type = SETTINGS_GENERAL;
    this->_jsonParser = jsonParser;
    this->_guiFunction = std::make_shared<guiFunction>();
    this->loadMenu();
}

void MenuManager::setMenuType(menuType type)
{
    this->_type = type;
    this->reloadMenu();
}

void MenuManager::setMenuType(int typeId)
{
    this->_type = static_cast<menuType>(typeId);
    this->reloadMenu();
}


enum menuType MenuManager::getMenuType() const
{
    return this->_type;
}

std::shared_ptr<MenuManager> MenuManager::getThis()
{
    return shared_from_this();
}

void MenuManager::loadMenu()
{
    this->_menuJson = _jsonParser->parseFile("./config/menu_settings.json");
    this->_menuTemplate = _menuJson["templates"];

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
    _guiFunction->mapFunctions();
}

void MenuManager::newMenuItems(int x, int y, int width, int length, std::string functionName, menuType type)
{
    MenuItem item;
    item.x = x;
    item.y = y;
    item.width = width;
    item.length = length;
    item.functionName = functionName;
    if (_MenuItems.find(type) == _MenuItems.end()) {
        _MenuItems[type] = std::vector<MenuItem>();
    }
    this->_MenuItems[type].push_back(item);
}

void MenuManager::reloadMenu()
{
    this->eraseMenu();
    //this->_guiFunction->clearCache();
    this->loadMenu();
}

void MenuManager::reloadOnChanges()
{
    if (_jsonParser->fileHasChanged("./config/menu_settings.json"))
        this->reloadMenu();
}

void MenuManager::createMenu(const nlohmann::json &menu, int menuID)
{
    try {
        menuType type = static_cast<menuType>(menuID);
        std::cout << "menuID : " << menuID << std::endl;
        std::cout << "menu : " << menu << "\n\n\n\n" << std::endl;
        
        this->_menuList[type]->addListText(loadsTexts(menu, type));
        this->_menuList[type]->addListButton(loadsButtons(menu, type));
        this->_menuList[type]->addListWindBox(loadsWindBoxes(menu, type));
        this->_menuList[type]->addListCheckBox(loadsCheckBoxes(menu, type));
        this->_menuList[type]->addListSlider(loadsSliders(menu, type));
        this->_menuList[type]->addListList(loadsLists(menu, type));
        this->_menuList[type]->addListListEx(loadsListExs(menu, type));
        this->_menuList[type]->addListInputText(loadsInputTexts(menu, type));
        this->_menuList[type]->addListInputTextBox(loadsInputTextsBoxs(menu, type));
        this->_menuList[type]->addListSpinner(loadsSpinners(menu, type));
        this->_menuList[type]->addListValueBox(loadsValueBoxes(menu, type));
        this->_menuList[type]->addListGroup(loadsGroups(menu, type));
        this->_menuList[type]->addListToggleGroup(loadsToggleGroups(menu, type));
        this->_menuList[type]->addListToggleSlider(loadsToggleSliders(menu, type));
        this->_menuList[type]->addListPannel(loadsPannels(menu, type));
        this->_menuList[type]->addListColorPicker(loadsColorPickers(menu, type));
        this->_menuList[type]->addListProgressBar(loadsProgressBars(menu, type));
        this->_menuList[type]->addListDropDown(loadsDropDowns(menu, type));
    } catch (std::exception &e) {
        std::cerr << "invalid json : " << e.what() << std::endl;
    }
}

std::vector<GButton> MenuManager::loadsButtons(const nlohmann::json &jsonbuttons, menuType type)
{
    std::vector<GButton> buttons;
    if (jsonbuttons.contains("buttons"))
        for (auto &button : jsonbuttons["buttons"])
            buttons.push_back(this->createButton(button, type));
    return buttons;
}

std::vector<GWindBox> MenuManager::loadsWindBoxes(const nlohmann::json &jsonWindBoxes, menuType type)
{
    std::vector<GWindBox> windBoxes;
    if (jsonWindBoxes.contains("windBoxes"))
        for (auto &windBox : jsonWindBoxes["windBoxes"])
            windBoxes.push_back(this->createWindBox(windBox, type));
    return windBoxes;
}

std::vector<RaylibText> MenuManager::loadsTexts(const nlohmann::json &jsonTexts, menuType type)
{
    std::vector<RaylibText> texts;
    if (jsonTexts.contains("texts"))
        for (auto &text : jsonTexts["texts"])
            texts.push_back(this->createTexts(text, type));
    return texts;
}

std::vector<GCheckBox> MenuManager::loadsCheckBoxes(const nlohmann::json &jsonCheckBoxes, menuType type)
{
    std::vector<GCheckBox> checkBoxes;
    if (jsonCheckBoxes.contains("checkBoxes"))
        for (auto &checkBox : jsonCheckBoxes["checkBoxes"])
            checkBoxes.push_back(this->createCheckBox(checkBox, type));
    return checkBoxes;
}

std::vector<GSlider> MenuManager::loadsSliders(const nlohmann::json &jsonSliders, menuType type)
{
    std::vector<GSlider> sliders;
    if (jsonSliders.contains("sliders"))
        for (auto &slider : jsonSliders["sliders"])
            sliders.push_back(this->createSlider(slider, type));
    return sliders;
}

std::vector<GList> MenuManager::loadsLists(const nlohmann::json &jsonLists, menuType type)
{
    std::vector<GList> lists;
    if (jsonLists.contains("lists"))
        for (auto &list : jsonLists["lists"])
            lists.push_back(this->createList(list, type));
    return lists;
}

std::vector<GListEx> MenuManager::loadsListExs(const nlohmann::json &jsonListExs, menuType type)
{
    std::vector<GListEx> listExs;
    if (jsonListExs.contains("listExs"))
        for (auto &listEx : jsonListExs["listExs"])
            listExs.push_back(this->createListEx(listEx, type));
    return listExs;
}

std::vector<GTextInput> MenuManager::loadsInputTexts(const nlohmann::json &jsonInputTexts, menuType type)
{
    std::vector<GTextInput> inputTexts;
    if (jsonInputTexts.contains("inputTexts"))
        for (auto &inputText : jsonInputTexts["inputTexts"])
            inputTexts.push_back(this->createInputText(inputText, type));
    return inputTexts;
}

std::vector<GTextInputBox> MenuManager::loadsInputTextsBoxs(const nlohmann::json &jsonInputTextBoxs, menuType type)
{
    std::vector<GTextInputBox> inputTextBoxs;
    if (jsonInputTextBoxs.contains("inputTextBoxs"))
        for (auto &inputTextBox : jsonInputTextBoxs["inputTextBoxs"])
            inputTextBoxs.push_back(this->createInputTextBox(inputTextBox, type));
    return inputTextBoxs;
}

std::vector<GSpinner> MenuManager::loadsSpinners(const nlohmann::json &jsonSpinners, menuType type)
{
    std::vector<GSpinner> spinners;
    if (jsonSpinners.contains("spinners"))
        for (auto &spinner : jsonSpinners["spinners"])
            spinners.push_back(this->createSpinner(spinner, type));
    return spinners;
}

std::vector<GValueBox> MenuManager::loadsValueBoxes(const nlohmann::json &jsonValueBoxes, menuType type)
{
    std::vector<GValueBox> valueBoxes;
    if (jsonValueBoxes.contains("valueBoxes"))
        for (auto &valueBox : jsonValueBoxes["valueBoxes"])
            valueBoxes.push_back(this->createValueBox(valueBox, type));
    return valueBoxes;
}

std::vector<GGroup> MenuManager::loadsGroups(const nlohmann::json &jsonGroups, menuType type)
{
    std::vector<GGroup> groups;
    if (jsonGroups.contains("groups"))
        for (auto &group : jsonGroups["groups"])
            groups.push_back(this->createGroup(group, type));
    return groups;
}

std::vector<GToggleGroup> MenuManager::loadsToggleGroups(const nlohmann::json &jsonToggleGroups, menuType type)
{
    std::vector<GToggleGroup> toggleGroups;
    if (jsonToggleGroups.contains("toggleGroups"))
        for (auto &toggleGroup : jsonToggleGroups["toggleGroups"])
            toggleGroups.push_back(this->createToggleGroup(toggleGroup, type));
    return toggleGroups;
}

std::vector<GToggleSlider> MenuManager::loadsToggleSliders(const nlohmann::json &jsonToggleSliders, menuType type)
{
    std::vector<GToggleSlider> toggleSliders;
    if (jsonToggleSliders.contains("toggleSliders"))
        for (auto &toggleSlider : jsonToggleSliders["toggleSliders"])
            toggleSliders.push_back(this->createToggleSlider(toggleSlider, type));
    return toggleSliders;
}

std::vector<GPannel> MenuManager::loadsPannels(const nlohmann::json &jsonPannels, menuType type)
{
    std::vector<GPannel> pannels;
    if (jsonPannels.contains("pannels"))
        for (auto &pannel : jsonPannels["pannels"])
            pannels.push_back(this->createPannel(pannel, type));
    return pannels;
}

std::vector<GColorPicker> MenuManager::loadsColorPickers(const nlohmann::json &jsonColorPickers, menuType type)
{
    std::vector<GColorPicker> colorPickers;
    if (jsonColorPickers.contains("colorPickers"))
        for (auto &colorPicker : jsonColorPickers["colorPickers"])
            colorPickers.push_back(this->createColorPicker(colorPicker, type));
    return colorPickers;
}

std::vector<GProgressBar> MenuManager::loadsProgressBars(const nlohmann::json &jsonProgressBars, menuType type)
{
    std::vector<GProgressBar> progressBars;
    if (jsonProgressBars.contains("progressBars"))
        for (auto &progressBar : jsonProgressBars["progressBars"])
            progressBars.push_back(this->createProgressBar(progressBar, type));
    return progressBars;
}

std::vector<GDropDown> MenuManager::loadsDropDowns(const nlohmann::json &jsonDropDowns, menuType type)
{
    std::vector<GDropDown> dropDowns;
    if (jsonDropDowns.contains("dropDowns"))
        for (auto &dropDown : jsonDropDowns["dropDowns"])
            dropDowns.push_back(this->createDropDown(dropDown, type));
    return dropDowns;
}

void MenuManager::integrateTemplate(const nlohmann::json &menu, int menuID)
{
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
    this->_menuList.clear();
    this->_jsonParser->eraseCache("./config/menu_settings.json");
}

void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    this->_jsonParser = jsonParser;
}

void MenuManager::drawMenu() const
{
    if (this->_menuList.find(_type) != this->_menuList.end())
        this->_menuList.at(_type)->DrawGui();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        for (auto &item : this->_MenuItems.at(_type)) {
            if (CheckCollisionPointRec(mousePosition, Rectangle{static_cast<float>(item.x), static_cast<float>(item.y), static_cast<float>(item.width), static_cast<float>(item.length)})) {
                std::cout << "function name : " << item.functionName << std::endl;
                std::function<void()> func = _guiFunction->getFunction(item.functionName);
                if (func != nullptr) {
                    func();
                    return;
                }
            }
        }
    }
}

RaylibText MenuManager::createTexts(const nlohmann::json &text, menuType type)
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

GButton MenuManager::createButton(const nlohmann::json &button, menuType type)
{
    try {
        this->newMenuItems(button["position"]["x"], button["position"]["y"], button["size"]["width"], button["size"]["height"], button["functionName"], type);
        return GButton(
            Vector2{button["position"]["x"], button["position"]["y"]},
            Vector2{button["size"]["width"], button["size"]["height"]},
            std::string(button["text"])
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GButton( Vector2{0, 0}, Vector2{0, 0}, "error occured");
    }
}

GWindBox MenuManager::createWindBox(const nlohmann::json &windBox, menuType type)
{
    try {
        this->newMenuItems(windBox["position"]["x"], windBox["position"]["y"], windBox["size"]["width"], windBox["size"]["height"], windBox["functionName"], type);
        return GWindBox(
            Vector2{windBox["position"]["x"], windBox["position"]["y"]},
            Vector2{windBox["size"]["width"], windBox["size"]["height"]},
            std::string(windBox["text"],
            windBox["isOpened"])
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GWindBox(Vector2{0, 0}, Vector2{0, 0}, "error occured");
    }
}

GCheckBox MenuManager::createCheckBox(const nlohmann::json &checkBox, menuType type)
{
    try {
        this->newMenuItems(checkBox["position"]["x"], checkBox["position"]["y"], checkBox["size"]["width"], checkBox["size"]["height"], checkBox["functionName"], type);
        return GCheckBox(
            Vector2{checkBox["position"]["x"], checkBox["position"]["y"]},
            Vector2{checkBox["size"]["width"], checkBox["size"]["height"]},
            std::string(checkBox["text"]),
            checkBox["isChecked"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GCheckBox(Vector2{0, 0}, Vector2{0, 0}, "error occured", false);
    }
}

GSlider MenuManager::createSlider(const nlohmann::json &slider, menuType type)
{
    try {
        this->newMenuItems(slider["position"]["x"], slider["position"]["y"], slider["size"]["width"], slider["size"]["height"], slider["functionName"], type);
        return GSlider(
            Vector2{slider["position"]["x"], slider["position"]["y"]},
            Vector2{slider["size"]["width"], slider["size"]["height"]},
            std::string(slider["text"]),
            slider["value"],
            slider["minValue"],
            slider["maxValue"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GSlider(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0, 0, 0);
    }
}

GList MenuManager::createList(const nlohmann::json &list, menuType type)
{
    try {
        this->newMenuItems(list["position"]["x"], list["position"]["y"], list["size"]["width"], list["size"]["height"], list["functionName"], type);
        return GList(
            Vector2{list["position"]["x"], list["position"]["y"]},
            Vector2{list["size"]["width"], list["size"]["height"]},
            std::string(list["text"])
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GList(Vector2{0, 0}, Vector2{0, 0}, "error occured");
    }
}

GListEx MenuManager::createListEx(const nlohmann::json &listEx, menuType type)
{
    try {
        this->newMenuItems(listEx["position"]["x"], listEx["position"]["y"], listEx["size"]["width"], listEx["size"]["height"], listEx["functionName"], type);
        std::vector<std::string> list = listEx["list"];
        return GListEx(
            Vector2{listEx["position"]["x"], listEx["position"]["y"]},
            Vector2{listEx["size"]["width"], listEx["size"]["height"]},
            list,
            listEx["active"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GListEx(Vector2{0, 0}, Vector2{0, 0}, std::vector<std::string>{"error occured"}, 0);
    }
}

GTextInput MenuManager::createInputText(const nlohmann::json &inputText, menuType type)
{
    try {
        this->newMenuItems(inputText["position"]["x"], inputText["position"]["y"], inputText["size"]["width"], inputText["size"]["height"], inputText["functionName"], type);
        return GTextInput(
            Vector2{inputText["position"]["x"], inputText["position"]["y"]},
            Vector2{inputText["size"]["width"], inputText["size"]["height"]},
            std::string(inputText["text"]),
            inputText["textMaxSize"],
            inputText["editMode"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GTextInput(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0, false);
    }
}

GTextInputBox MenuManager::createInputTextBox(const nlohmann::json &inputTextBox, menuType type)
{
    try {
        this->newMenuItems(inputTextBox["position"]["x"], inputTextBox["position"]["y"], inputTextBox["size"]["width"], inputTextBox["size"]["height"], inputTextBox["functionName"], type);
        return GTextInputBox(
            Vector2{inputTextBox["position"]["x"], inputTextBox["position"]["y"]},
            Vector2{inputTextBox["size"]["width"], inputTextBox["size"]["height"]},
            std::string(inputTextBox["title"]),
            std::string(inputTextBox["message"]),
            std::string(inputTextBox["buttons"]),
            std::string(inputTextBox["text"]),
            inputTextBox["textMaxSize"],
            inputTextBox["secretViewActive"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GTextInputBox(Vector2{0, 0}, Vector2{0, 0}, "error occured", "error occured", "error occured", "error occured", 100, NULL);
    }
}

GSpinner MenuManager::createSpinner(const nlohmann::json &spinner, menuType type)
{
    try {
        this->newMenuItems(spinner["position"]["x"], spinner["position"]["y"], spinner["size"]["width"], spinner["size"]["height"], spinner["functionName"], type);
        return GSpinner(
            Vector2{spinner["position"]["x"], spinner["position"]["y"]},
            Vector2{spinner["size"]["width"], spinner["size"]["height"]},
            std::string(spinner["text"]),
            spinner["value"],
            spinner["minValue"],
            spinner["maxValue"],
            spinner["editMode"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GSpinner(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0, 0, 0, false);
    }
}

GValueBox MenuManager::createValueBox(const nlohmann::json &valueBox, menuType type)
{
    try {
        this->newMenuItems(valueBox["position"]["x"], valueBox["position"]["y"], valueBox["size"]["width"], valueBox["size"]["height"], valueBox["functionName"], type);
        return GValueBox(
            Vector2{valueBox["position"]["x"], valueBox["position"]["y"]},
            Vector2{valueBox["size"]["width"], valueBox["size"]["height"]},
            std::string(valueBox["text"]),
            valueBox["value"],
            valueBox["minValue"],
            valueBox["maxValue"],
            valueBox["editMode"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GValueBox(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0, 0, 0, false);
    }
}

GGroup MenuManager::createGroup(const nlohmann::json &group, menuType type)
{
    try {
        this->newMenuItems(group["position"]["x"], group["position"]["y"], group["size"]["width"], group["size"]["height"], group["functionName"], type);
        return GGroup(
            Vector2{group["position"]["x"], group["position"]["y"]},
            Vector2{group["size"]["width"], group["size"]["height"]},
            std::string(group["text"])
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GGroup(Vector2{0, 0}, Vector2{0, 0}, "error occured");
    }
}

GToggleGroup MenuManager::createToggleGroup(const nlohmann::json &toggleGroup, menuType type)
{
    try {
        this->newMenuItems(toggleGroup["position"]["x"], toggleGroup["position"]["y"], toggleGroup["size"]["width"], toggleGroup["size"]["height"], toggleGroup["functionName"], type);
        return GToggleGroup(
            Vector2{toggleGroup["position"]["x"], toggleGroup["position"]["y"]},
            Vector2{toggleGroup["size"]["width"], toggleGroup["size"]["height"]},
            std::string(toggleGroup["text"]),
            toggleGroup["active"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GToggleGroup(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0);
    }
}

GToggleSlider MenuManager::createToggleSlider(const nlohmann::json &toggleSlider, menuType type)
{
    try {
        this->newMenuItems(toggleSlider["position"]["x"], toggleSlider["position"]["y"], toggleSlider["size"]["width"], toggleSlider["size"]["height"], toggleSlider["functionName"], type);
        return GToggleSlider(
            Vector2{toggleSlider["position"]["x"], toggleSlider["position"]["y"]},
            Vector2{toggleSlider["size"]["width"], toggleSlider["size"]["height"]},
            std::string(toggleSlider["text"]),
            toggleSlider["active"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GToggleSlider(Vector2{0, 0}, Vector2{0, 0}, "error occured", 0);
    }
}

GPannel MenuManager::createPannel(const nlohmann::json &pannel, menuType type)
{
    try {
        this->newMenuItems(pannel["position"]["x"], pannel["position"]["y"], pannel["size"]["width"], pannel["size"]["height"], pannel["functionName"], type);
        return GPannel(
            Vector2{pannel["position"]["x"], pannel["position"]["y"]},
            Vector2{pannel["size"]["width"], pannel["size"]["height"]},
            std::string(pannel["text"])
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GPannel(Vector2{0, 0}, Vector2{0, 0}, "error occured");
    }
}

GColorPicker MenuManager::createColorPicker(const nlohmann::json &colorPicker, menuType type)
{
    try {
        this->newMenuItems(colorPicker["position"]["x"], colorPicker["position"]["y"], colorPicker["size"]["width"], colorPicker["size"]["height"], colorPicker["functionName"], type);
        return GColorPicker(
            Vector2{colorPicker["position"]["x"], colorPicker["position"]["y"]},
            Vector2{colorPicker["size"]["width"], colorPicker["size"]["height"]},
            std::string(colorPicker["text"]),
            Color{colorPicker["color"]["r"], colorPicker["color"]["g"], colorPicker["color"]["b"], colorPicker["color"]["a"]}
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GColorPicker(Vector2{0, 0}, Vector2{0, 0}, "error occured", Color{0, 0, 0, 0});
    }
}

GProgressBar MenuManager::createProgressBar(const nlohmann::json &progressBar, menuType type)
{
    try {
        this->newMenuItems(progressBar["position"]["x"], progressBar["position"]["y"], progressBar["size"]["width"], progressBar["size"]["height"], progressBar["functionName"], type);
        return GProgressBar(
            Vector2{progressBar["position"]["x"], progressBar["position"]["y"]},
            Vector2{progressBar["size"]["width"], progressBar["size"]["height"]},
            std::string(progressBar["textLeft"]),
            std::string(progressBar["textRight"]),
            progressBar["value"],
            progressBar["minValue"],
            progressBar["maxValue"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GProgressBar(Vector2{0, 0}, Vector2{0, 0}, "error occured", "error occured", 0, 0, 0);
    }
}

GDropDown MenuManager::createDropDown(const nlohmann::json &dropDown, menuType type)
{
    try {
        this->newMenuItems(dropDown["position"]["x"], dropDown["position"]["y"], dropDown["size"]["width"], dropDown["size"]["height"], dropDown["functionName"], type);
        return GDropDown(
            Vector2{dropDown["position"]["x"], dropDown["position"]["y"]},
            Vector2{dropDown["size"]["width"], dropDown["size"]["height"]},
            std::string(dropDown["text"]),
            dropDown["active"],
            dropDown["editMode"]
        );
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return GDropDown(Vector2{0, 0}, Vector2{0, 0}, "error;occured", 0, false);
    }
}
