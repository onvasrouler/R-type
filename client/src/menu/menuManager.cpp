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
    this->_type = SETTINGS_VIDEO;
    this->_guiFunction = std::make_shared<guiFunction>();
}

MenuManager::MenuManager(std::shared_ptr<JsonParser> jsonParser)
{
    this->_type = SETTINGS_VIDEO;
    this->_jsonParser = jsonParser;
    this->_guiFunction = std::make_shared<guiFunction>();
    this->loadMenu();

}

void MenuManager::setMenuType(menuType type)
{
    _type = type;
}

void MenuManager::setMenuType(int typeId)
{
    _type = static_cast<menuType>(typeId);
}


enum menuType MenuManager::getMenuType() const
{
    return _type;
}

void MenuManager::hello()
{
    std::cout << "hello" << std::endl;
}

std::shared_ptr<MenuManager> MenuManager::getThis()
{
    return shared_from_this();
}

void MenuManager::loadMenu()
{
    _menuJson = _jsonParser->parseFile("./config/menu_settings.json");
    _menuTemplate = _menuJson["templates"];

    for (auto &menu : _menuJson["menus"]) {
        if (menu["isSimple"] == false)
            continue;
        if (!menu.is_null()) {
            menuType type = static_cast<menuType>(menu["id"]);
            _menuList[type] = std::make_shared<RGui>();
            this->integrateTemplate(menu, menu["id"]);
            this->createMenu(menu, menu["id"]);
        }
        
    }
   // _guiFunction->mapFunctions();
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

std::function<void (const std::string &)> MenuManager::getFunction(const std::string functionName)
{
    return _guiFunction->getFunction(functionName);
}

void MenuManager::createMenu(const nlohmann::json &menu, int menuID)
{
    try {
        menuType type = static_cast<menuType>(menuID);
        _menuList[type]->addListText(loadsTexts(menu));
        _menuList[type]->addListButton(loadsButtons(menu));
        _menuList[type]->addListWindBox(loadsWindBoxes(menu));
        _menuList[type]->addListCheckBox(loadsCheckBoxes(menu));
        _menuList[type]->addListSlider(loadsSliders(menu));
        _menuList[type]->addListList(loadsLists(menu));
        _menuList[type]->addListListEx(loadsListExs(menu));
        _menuList[type]->addListInputText(loadsInputTexts(menu));
        _menuList[type]->addListInputTextBox(loadsInputTextsBoxs(menu));
        _menuList[type]->addListSpinner(loadsSpinners(menu));
        _menuList[type]->addListValueBox(loadsValueBoxes(menu));
        _menuList[type]->addListGroup(loadsGroups(menu));
        _menuList[type]->addListToggleGroup(loadsToggleGroups(menu));
        _menuList[type]->addListToggleSlider(loadsToggleSliders(menu));
        _menuList[type]->addListPannel(loadsPannels(menu));
        _menuList[type]->addListColorPicker(loadsColorPickers(menu));
        _menuList[type]->addListProgressBar(loadsProgressBars(menu));
        _menuList[type]->addListDropDown(loadsDropDowns(menu));
    } catch (std::exception &e) {
        std::cerr << "invalid json : " << e.what() << std::endl;
    }
}

std::vector<GButton> MenuManager::loadsButtons(const nlohmann::json &jsonbuttons)
{
    std::vector<GButton> buttons;
    if (jsonbuttons.contains("buttons"))
        for (auto &button : jsonbuttons["buttons"])
            buttons.push_back(this->createButton(button));
    return buttons;
}

std::vector<GWindBox> MenuManager::loadsWindBoxes(const nlohmann::json &jsonWindBoxes)
{
    std::vector<GWindBox> windBoxes;
    if (jsonWindBoxes.contains("windBoxes"))
        for (auto &windBox : jsonWindBoxes["windBoxes"])
            windBoxes.push_back(this->createWindBox(windBox));
    return windBoxes;
}

std::vector<RaylibText> MenuManager::loadsTexts(const nlohmann::json &jsonTexts)
{
    std::vector<RaylibText> texts;
    if (jsonTexts.contains("texts"))
        for (auto &text : jsonTexts["texts"])
            texts.push_back(this->createTexts(text));
    return texts;
}

std::vector<GCheckBox> MenuManager::loadsCheckBoxes(const nlohmann::json &jsonCheckBoxes)
{
    std::vector<GCheckBox> checkBoxes;
    if (jsonCheckBoxes.contains("checkBoxes"))
        for (auto &checkBox : jsonCheckBoxes["checkBoxes"])
            checkBoxes.push_back(this->createCheckBox(checkBox));
    return checkBoxes;
}

std::vector<GSlider> MenuManager::loadsSliders(const nlohmann::json &jsonSliders)
{
    std::vector<GSlider> sliders;
    if (jsonSliders.contains("sliders"))
        for (auto &slider : jsonSliders["sliders"])
            sliders.push_back(this->createSlider(slider));
    return sliders;
}

std::vector<GList> MenuManager::loadsLists(const nlohmann::json &jsonLists)
{
    std::vector<GList> lists;
    if (jsonLists.contains("lists"))
        for (auto &list : jsonLists["lists"])
            lists.push_back(this->createList(list));
    return lists;
}

std::vector<GListEx> MenuManager::loadsListExs(const nlohmann::json &jsonListExs)
{
    std::vector<GListEx> listExs;
    if (jsonListExs.contains("listExs"))
        for (auto &listEx : jsonListExs["listExs"])
            listExs.push_back(this->createListEx(listEx));
    return listExs;
}

std::vector<GTextInput> MenuManager::loadsInputTexts(const nlohmann::json &jsonInputTexts)
{
    std::vector<GTextInput> inputTexts;
    if (jsonInputTexts.contains("inputTexts"))
        for (auto &inputText : jsonInputTexts["inputTexts"])
            inputTexts.push_back(this->createInputText(inputText));
    return inputTexts;
}

std::vector<GTextInputBox> MenuManager::loadsInputTextsBoxs(const nlohmann::json &jsonInputTextBoxs)
{
    std::vector<GTextInputBox> inputTextBoxs;
    if (jsonInputTextBoxs.contains("inputTextBoxs"))
        for (auto &inputTextBox : jsonInputTextBoxs["inputTextBoxs"])
            inputTextBoxs.push_back(this->createInputTextBox(inputTextBox));
    return inputTextBoxs;
}

std::vector<GSpinner> MenuManager::loadsSpinners(const nlohmann::json &jsonSpinners)
{
    std::vector<GSpinner> spinners;
    if (jsonSpinners.contains("spinners"))
        for (auto &spinner : jsonSpinners["spinners"])
            spinners.push_back(this->createSpinner(spinner));
    return spinners;
}

std::vector<GValueBox> MenuManager::loadsValueBoxes(const nlohmann::json &jsonValueBoxes)
{
    std::vector<GValueBox> valueBoxes;
    if (jsonValueBoxes.contains("valueBoxes"))
        for (auto &valueBox : jsonValueBoxes["valueBoxes"])
            valueBoxes.push_back(this->createValueBox(valueBox));
    return valueBoxes;
}

std::vector<GGroup> MenuManager::loadsGroups(const nlohmann::json &jsonGroups)
{
    std::vector<GGroup> groups;
    if (jsonGroups.contains("groups"))
        for (auto &group : jsonGroups["groups"])
            groups.push_back(this->createGroup(group));
    return groups;
}

std::vector<GToggleGroup> MenuManager::loadsToggleGroups(const nlohmann::json &jsonToggleGroups)
{
    std::vector<GToggleGroup> toggleGroups;
    if (jsonToggleGroups.contains("toggleGroups"))
        for (auto &toggleGroup : jsonToggleGroups["toggleGroups"])
            toggleGroups.push_back(this->createToggleGroup(toggleGroup));
    return toggleGroups;
}

std::vector<GToggleSlider> MenuManager::loadsToggleSliders(const nlohmann::json &jsonToggleSliders)
{
    std::vector<GToggleSlider> toggleSliders;
    if (jsonToggleSliders.contains("toggleSliders"))
        for (auto &toggleSlider : jsonToggleSliders["toggleSliders"])
            toggleSliders.push_back(this->createToggleSlider(toggleSlider));
    return toggleSliders;
}

std::vector<GPannel> MenuManager::loadsPannels(const nlohmann::json &jsonPannels)
{
    std::vector<GPannel> pannels;
    if (jsonPannels.contains("pannels"))
        for (auto &pannel : jsonPannels["pannels"])
            pannels.push_back(this->createPannel(pannel));
    return pannels;
}

std::vector<GColorPicker> MenuManager::loadsColorPickers(const nlohmann::json &jsonColorPickers)
{
    std::vector<GColorPicker> colorPickers;
    if (jsonColorPickers.contains("colorPickers"))
        for (auto &colorPicker : jsonColorPickers["colorPickers"])
            colorPickers.push_back(this->createColorPicker(colorPicker));
    return colorPickers;
}

std::vector<GProgressBar> MenuManager::loadsProgressBars(const nlohmann::json &jsonProgressBars)
{
    std::vector<GProgressBar> progressBars;
    if (jsonProgressBars.contains("progressBars"))
        for (auto &progressBar : jsonProgressBars["progressBars"])
            progressBars.push_back(this->createProgressBar(progressBar));
    return progressBars;
}

std::vector<GDropDown> MenuManager::loadsDropDowns(const nlohmann::json &jsonDropDowns)
{
    std::vector<GDropDown> dropDowns;
    if (jsonDropDowns.contains("dropDowns"))
        for (auto &dropDown : jsonDropDowns["dropDowns"])
            dropDowns.push_back(this->createDropDown(dropDown));
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
    _menuList.clear();
    _jsonParser->eraseCache("./config/menu_settings.json");
}


void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _jsonParser = jsonParser;
}

void MenuManager::drawMenu() const
{
    if (_menuList.find(_type) != _menuList.end())
        _menuList.at(_type)->DrawGui();
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

GButton MenuManager::createButton(const nlohmann::json &button)
{
    try {
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

GWindBox MenuManager::createWindBox(const nlohmann::json &windBox)
{
    try {
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

GCheckBox MenuManager::createCheckBox(const nlohmann::json &checkBox)
{
    try {
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

GSlider MenuManager::createSlider(const nlohmann::json &slider)
{
    try {
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

GList MenuManager::createList(const nlohmann::json &list)
{
    try {
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

GListEx MenuManager::createListEx(const nlohmann::json &listEx)
{
    try {
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

GTextInput MenuManager::createInputText(const nlohmann::json &inputText)
{
    try {
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

GTextInputBox MenuManager::createInputTextBox(const nlohmann::json &inputTextBox)
{
    try {
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

GSpinner MenuManager::createSpinner(const nlohmann::json &spinner)
{
    try {
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

GValueBox MenuManager::createValueBox(const nlohmann::json &valueBox)
{
    try {
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

GGroup MenuManager::createGroup(const nlohmann::json &group)
{
    try {
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

GToggleGroup MenuManager::createToggleGroup(const nlohmann::json &toggleGroup)
{
    try {
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

GToggleSlider MenuManager::createToggleSlider(const nlohmann::json &toggleSlider)
{
    try {
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

GPannel MenuManager::createPannel(const nlohmann::json &pannel)
{
    try {
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

GColorPicker MenuManager::createColorPicker(const nlohmann::json &colorPicker)
{
    try {
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

GProgressBar MenuManager::createProgressBar(const nlohmann::json &progressBar)
{
    try {
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

GDropDown MenuManager::createDropDown(const nlohmann::json &dropDown)
{
    try {
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