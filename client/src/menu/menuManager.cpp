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

void MenuManager::reloadMenu()
{
    this->eraseMenu();
    this->loadMenu();
}

void MenuManager::reloadOnChanges()
{
    if (_jsonParser->fileHasChanged("./config/menu_settings.json"))
        this->reloadMenu();
}

void MenuManager::createMenu(const nlohmann::json &menu)
{
    try {
        menuType type = static_cast<menuType>(menu["id"]);
        std::vector<GButton> buttons;
        std::vector<GWindBox> windBoxes;
        std::vector<RaylibText> texts;
        std::vector<GCheckBox> checkBoxes;
        std::vector<GSlider> sliders;
        std::vector<GList> lists;
        std::vector<GListEx> listExs;
        std::vector<GTextInput> inputTexts;
        std::vector<GTextInputBox> inputTextsBoxs;
        std::vector<GSpinner> spinners;
        std::vector<GValueBox> valueBoxes;
        std::vector<GGroup> groups;
        std::vector<GToggleGroup> toggleGroups;
        std::vector<GToggleSlider> toggleSliders;
        std::vector<GPannel> pannels;
        std::vector<GColorPicker> colorPickers;
        std::vector<GProgressBar> progressBars;
        std::vector<GDropDown> dropDowns;

        if (menu.contains("buttons"))
            for (auto &button : menu["buttons"])
                buttons.push_back(this->createButton(button));
        if (menu.contains("Boxes"))
            for (auto &windBox : menu["Boxes"])
                windBoxes.push_back(this->createWindBox(windBox));
        if (menu.contains("texts"))
            for (auto &text : menu["texts"])
                texts.push_back(this->createTexts(text));
        if (menu.contains("checkBoxes"))
            for (auto &checkBox : menu["checkBoxes"])
                checkBoxes.push_back(this->createCheckBox(checkBox));
        if (menu.contains("sliders"))
            for (auto &slider : menu["sliders"])
                sliders.push_back(this->createSlider(slider));
        if (menu.contains("lists"))
            for (auto &list : menu["lists"])
                lists.push_back(this->createList(list));
        if (menu.contains("listExs"))
            for (auto &listEx : menu["listExs"])
                listExs.push_back(this->createListEx(listEx));
        if (menu.contains("inputTexts"))
            for (auto &inputText : menu["inputTexts"])
                inputTexts.push_back(this->createInputText(inputText));
        if (menu.contains("inputTextsBoxs"))
            for (auto &inputText : menu["inputTextsBoxs"])
                inputTextsBoxs.push_back(this->createInputTextBox(inputText));
        if (menu.contains("spinners"))
            for (auto &spinner : menu["spinners"])
                spinners.push_back(this->createSpinner(spinner));
        if (menu.contains("valueBoxes"))
            for (auto &valueBox : menu["valueBoxes"])
                valueBoxes.push_back(this->createValueBox(valueBox));
        if (menu.contains("groups"))
            for (auto &group : menu["groups"])
                groups.push_back(this->createGroup(group));
        if (menu.contains("toggleGroups"))
            for (auto &toggleGroup : menu["toggleGroups"])
                toggleGroups.push_back(this->createToggleGroup(toggleGroup));
        if (menu.contains("toggleSliders"))
            for (auto &toggleSlider : menu["toggleSliders"])
                toggleSliders.push_back(this->createToggleSlider(toggleSlider));
        if (menu.contains("pannels"))
            for (auto &pannel : menu["pannels"])
                pannels.push_back(this->createPannel(pannel));
        if (menu.contains("colorPickers"))
            for (auto &colorPicker : menu["colorPickers"])
                colorPickers.push_back(this->createColorPicker(colorPicker));
        if (menu.contains("progressBars"))
            for (auto &progressBar : menu["progressBars"])
                progressBars.push_back(this->createProgressBar(progressBar));
        if (menu.contains("dropDowns"))
            for (auto &dropDown : menu["dropDowns"])
                dropDowns.push_back(this->createDropDown(dropDown));
        _menuList[type] = std::make_shared<RGui>();
        _menuList[type]->setTexts(texts);
        _menuList[type]->SetButtons(buttons);
        _menuList[type]->SetWindBoxes(windBoxes);
        _menuList[type]->setCheckBoxes(checkBoxes);
        _menuList[type]->setSliders(sliders);
        _menuList[type]->setLists(lists);
        _menuList[type]->setListExs(listExs);
        _menuList[type]->setInputTexts(inputTexts);
        _menuList[type]->setInputTextsBoxs(inputTextsBoxs);
        _menuList[type]->setSpinners(spinners);
        _menuList[type]->setValueBoxes(valueBoxes);
        _menuList[type]->setGroups(groups);
        _menuList[type]->setToggleGroups(toggleGroups);
        _menuList[type]->setToggleSliders(toggleSliders);
        _menuList[type]->setPannels(pannels);
        _menuList[type]->setColorPickers(colorPickers);
        _menuList[type]->setProgressBars(progressBars);
        _menuList[type]->setDropDowns(dropDowns);
    } catch (std::exception &e) {
        std::cerr << "invalid json : " << e.what() << std::endl;
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