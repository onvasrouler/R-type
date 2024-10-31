/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** GuiElementFactory
*/


#include "GuiElementFactory.hpp"


GuiElementFactory::GuiElementFactory(std::shared_ptr<JsonParser> jsonParser)
{
    this->_JsonParser = jsonParser;
}

int GuiElementFactory::convertToRelativePosX(std::string pos, const int windowWidth) const
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

int GuiElementFactory::convertToRelativePosX(std::string pos, const int width, const int windowWidth) const
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

int GuiElementFactory::convertToRelativePosY(std::string pos, const int windowHeight) const
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

int GuiElementFactory::convertToRelativePosY(std::string pos, const int height, const int windowHeight) const
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

Vector2 GuiElementFactory::getRelativePos(const nlohmann::json &x, const nlohmann::json &y) const
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

Vector2 GuiElementFactory::getRelativePos(const nlohmann::json &x, const int width, const nlohmann::json &y, const int height) const
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

bool GuiElementFactory::jsonToBool(const nlohmann::json &json) const
{
    if (json.is_string()) {
        if (json == "true")
            return true;
        return false;
    }
    return json.get<bool>();
}

std::shared_ptr<RLText> GuiElementFactory::createTexts(const nlohmann::json &text, const menuType type)
{
    this->_DebugLogger->Log("Creating Text : " + text.dump(), 5);
    int width = text["text"].get<std::string>().length() * (text["fontSize"].get<int>() / 2);
    try {
        this->newMenuItems(text["position"]["x"], text["position"]["y"], width, text["fontSize"], text["functionName"], type);
        return std::make_shared<RLText>(
            getRelativePos(text["position"]["x"], width, text["position"]["y"], text["fontSize"]),
            getRelativePos(width, text["fontSize"]),
            text["text"].get<std::string>(),
            text.contains("z-index") ? text["z-index"].get<int>() : 0,
            Color{text["color"]["r"], text["color"]["g"], text["color"]["b"], text["color"]["a"]},
            text["id"].get<std::string>(),
            text["display"]
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<RLText>(getRelativePos(defaultErrorPosX, defaultErrorPosY), Vector2{10, 10}, errorText, defaultErrorZindex, defaultErrorColor, defaultErrroId, defaultDoDisplayElement);
    }
}

std::shared_ptr<GButton> GuiElementFactory::createButtons(const nlohmann::json &button, const menuType type)
{
    this->_DebugLogger->Log("Creating Button : " + button.dump(), 5);
    try {
        this->newMenuItems(button["position"]["x"], button["position"]["y"], button["size"]["width"], button["size"]["height"], button["functionName"], type);
        return std::make_shared<GButton>(
            getRelativePos(button["position"]["x"], button["position"]["y"]),
            getRelativePos(button["size"]["width"], button["size"]["height"]),
            std::string(button["text"]),
            button.contains("z-index") ? button["z-index"].get<int>() : 0,
            button["id"].get<std::string>(),
            jsonToBool(button["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GButton>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, defaultDoDisplayElement);
    }
}

std::shared_ptr<GWindBox> GuiElementFactory::createWindBox(const nlohmann::json &windBox, const menuType type)
{
    this->_DebugLogger->Log("Creating WindBox : " + windBox.dump(), 5);
    try {
        this->newMenuItems(windBox["position"]["x"], windBox["position"]["y"], windBox["size"]["width"], windBox["size"]["height"], windBox["functionName"], type);
        return std::make_shared<GWindBox>(
            getRelativePos(windBox["position"]["x"], windBox["position"]["y"]),
            getRelativePos(windBox["size"]["width"], windBox["size"]["height"]),
            std::string(windBox["text"]),
            windBox.contains("z-index") ? windBox["z-index"].get<int>() : 0,
            windBox["id"].get<std::string>(),
            jsonToBool(windBox["isOpened"]),
            jsonToBool(windBox["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GWindBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GCheckBox> GuiElementFactory::createCheckBoxes(const nlohmann::json &checkBox, const menuType type)
{
    this->_DebugLogger->Log("Creating CheckBox : " + checkBox.dump(), 5);
    try {
        this->newMenuItems(checkBox["position"]["x"], checkBox["position"]["y"], checkBox["size"]["width"], checkBox["size"]["height"], checkBox["functionName"], type);
        return std::make_shared<GCheckBox>(
            getRelativePos(checkBox["position"]["x"], checkBox["position"]["y"]),
            getRelativePos(checkBox["size"]["width"], checkBox["size"]["height"]),
            std::string(checkBox["text"]),
            checkBox.contains("z-index") ? checkBox["z-index"].get<int>() : 0,
            checkBox["id"].get<std::string>(),
            checkBox["isChecked"],
            jsonToBool(checkBox["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GCheckBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GSlider> GuiElementFactory::createSliders(const nlohmann::json &slider, const menuType type)
{
    this->_DebugLogger->Log("Creating Slider : " + slider.dump(), 5);
    try {
        this->newMenuItems(slider["position"]["x"], slider["position"]["y"], slider["size"]["width"], slider["size"]["height"], slider["functionName"], type);
        return std::make_shared<GSlider>(
            getRelativePos(slider["position"]["x"], slider["position"]["y"]),
            getRelativePos(slider["size"]["width"], slider["size"]["height"]),
            std::string(slider["text"]),
            slider.contains("z-index") ? slider["z-index"].get<int>() : 0,
            slider["id"].get<std::string>(),
            slider["value"],
            slider["minValue"],
            slider["maxValue"],
            jsonToBool(slider["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GSlider>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, 0.0F, 0.0F, 0.0F, defaultDoDisplayElement);
    }
}

std::shared_ptr<GList> GuiElementFactory::createLists(const nlohmann::json &list, const menuType type)
{
    this->_DebugLogger->Log("Creating List : " + list.dump(), 5);
    try {
        this->newMenuItems(list["position"]["x"], list["position"]["y"], list["size"]["width"], list["size"]["height"], list["functionName"], type);
        return std::make_shared<GList>(
            getRelativePos(list["position"]["x"], list["position"]["y"]),
            getRelativePos(list["size"]["width"], list["size"]["height"]),
            std::string(list["text"]),
            list.contains("z-index") ? list["z-index"].get<int>() : 0,
            list["id"].get<std::string>(),
            jsonToBool(list["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GList>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, defaultDoDisplayElement);
    }
}

std::shared_ptr<GListEx> GuiElementFactory::createListExs(const nlohmann::json &listEx, const menuType type)
{
    this->_DebugLogger->Log("Creating ListEx : " + listEx.dump(), 5);
    try {
        this->newMenuItems(listEx["position"]["x"], listEx["position"]["y"], listEx["size"]["width"], listEx["size"]["height"], listEx["functionName"], type);
        std::vector<std::string> list = listEx["list"];
        return std::make_shared<GListEx>(
            getRelativePos(listEx["position"]["x"], listEx["position"]["y"]),
            getRelativePos(listEx["size"]["width"], listEx["size"]["height"]),
            listEx.contains("z-index") ? listEx["z-index"].get<int>() : 0,
            listEx["id"].get<std::string>(),
            list,
            listEx["active"],
            jsonToBool(listEx["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GListEx>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, defaultErrorZindex, defaultErrroId, std::vector<std::string>{errorText}, 0, defaultDoDisplayElement);
    }
}

std::shared_ptr<GTextInput> GuiElementFactory::createInputTexts(const nlohmann::json &inputText, const menuType type)
{
    this->_DebugLogger->Log("Creating InputText : " + inputText.dump(), 5);
    try {
        this->newMenuItems(inputText["position"]["x"], inputText["position"]["y"], inputText["size"]["width"], inputText["size"]["height"], inputText["functionName"], type);
        return std::make_shared<GTextInput>(
            getRelativePos(inputText["position"]["x"], inputText["position"]["y"]),
            getRelativePos(inputText["size"]["width"], inputText["size"]["height"]),
            std::string(inputText["text"]),
            inputText.contains("z-index") ? inputText["z-index"].get<int>() : 0,
            inputText["id"].get<std::string>(),
            inputText["textMaxSize"],
            inputText["editMode"],
            jsonToBool(inputText["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GTextInput>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, 0, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GTextInputBox> GuiElementFactory::createInputTextsBoxs(const nlohmann::json &inputTextBox, const menuType type)
{
    this->_DebugLogger->Log("Creating InputTextBox : " + inputTextBox.dump(), 5);
    try {
        this->newMenuItems(inputTextBox["position"]["x"], inputTextBox["position"]["y"], inputTextBox["size"]["width"], inputTextBox["size"]["height"], inputTextBox["functionName"], type);
        return std::make_shared<GTextInputBox>(
            getRelativePos(inputTextBox["position"]["x"], inputTextBox["position"]["y"]),
            getRelativePos(inputTextBox["size"]["width"], inputTextBox["size"]["height"]),
            inputTextBox.contains("z-index") ? inputTextBox["z-index"].get<int>() : 0,
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
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GTextInputBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, defaultErrorZindex, defaultErrroId, "default title", "default message", "default buttons", "default text", 0, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GSpinner> GuiElementFactory::createSpinners(const nlohmann::json &spinner, const menuType type)
{
    this->_DebugLogger->Log("Creating Spinner : " + spinner.dump(), 5);
    try {
        this->newMenuItems(spinner["position"]["x"], spinner["position"]["y"], spinner["size"]["width"], spinner["size"]["height"], spinner["functionName"], type);
        return std::make_shared<GSpinner>(
            getRelativePos(spinner["position"]["x"], spinner["position"]["y"]),
            getRelativePos(spinner["size"]["width"], spinner["size"]["height"]),
            std::string(spinner["text"]),
            spinner.contains("z-index") ? spinner["z-index"].get<int>() : 0,
            spinner["id"].get<std::string>(),
            spinner["value"],
            spinner["minValue"],
            spinner["maxValue"],
            spinner["editMode"],
            jsonToBool(spinner["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GSpinner>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, 0, 0, 0, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GValueBox> GuiElementFactory::createValueBoxes(const nlohmann::json &valueBox, const menuType type)
{
    this->_DebugLogger->Log("Creating ValueBox : " + valueBox.dump(), 5);
    try {
        this->newMenuItems(valueBox["position"]["x"], valueBox["position"]["y"], valueBox["size"]["width"], valueBox["size"]["height"], valueBox["functionName"], type);
        return std::make_shared<GValueBox>(
            getRelativePos(valueBox["position"]["x"], valueBox["position"]["y"]),
            getRelativePos(valueBox["size"]["width"], valueBox["size"]["height"]),
            std::string(valueBox["text"]),
            valueBox.contains("z-index") ? valueBox["z-index"].get<int>() : 0,
            valueBox["id"].get<std::string>(),
            valueBox["value"],
            valueBox["minValue"],
            valueBox["maxValue"],
            valueBox["editMode"],
            jsonToBool(valueBox["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GValueBox>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId,0, 0, 0, false, defaultDoDisplayElement);
    }
}

std::shared_ptr<GGroup> GuiElementFactory::createGroups(const nlohmann::json &group, const menuType type)
{
    this->_DebugLogger->Log("Creating Group : " + group.dump(), 5);
    try {
        this->newMenuItems(group["position"]["x"], group["position"]["y"], group["size"]["width"], group["size"]["height"], group["functionName"], type);
        return std::make_shared<GGroup>(
            getRelativePos(group["position"]["x"], group["position"]["y"]),
            getRelativePos(group["size"]["width"], group["size"]["height"]),
            std::string(group["text"]),
            group.contains("z-index") ? group["z-index"].get<int>() : 0,
            group["id"].get<std::string>(),
            jsonToBool(group["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GGroup>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, defaultDoDisplayElement);
    }
}

std::shared_ptr<GToggleGroup> GuiElementFactory::createToggleGroups(const nlohmann::json &toggleGroup, const menuType type)
{
    this->_DebugLogger->Log("Creating ToggleGroup : " + toggleGroup.dump(), 5);
    try {
        this->newMenuItems(toggleGroup["position"]["x"], toggleGroup["position"]["y"], toggleGroup["size"]["width"], toggleGroup["size"]["height"], toggleGroup["functionName"], type);
        return std::make_shared<GToggleGroup>(
            getRelativePos(toggleGroup["position"]["x"], toggleGroup["position"]["y"]),
            getRelativePos(toggleGroup["size"]["width"], toggleGroup["size"]["height"]),
            std::string(toggleGroup["text"]),
            toggleGroup.contains("z-index") ? toggleGroup["z-index"].get<int>() : 0,
            toggleGroup["id"].get<std::string>(),
            toggleGroup["active"],
            jsonToBool(toggleGroup["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GToggleGroup>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, 0, defaultDoDisplayElement);
    }
}

std::shared_ptr<GToggleSlider> GuiElementFactory::createToggleSliders(const nlohmann::json &toggleSlider, const menuType type)
{
    this->_DebugLogger->Log("Creating ToggleSlider : " + toggleSlider.dump(), 5);
    try {
        this->newMenuItems(toggleSlider["position"]["x"], toggleSlider["position"]["y"], toggleSlider["size"]["width"], toggleSlider["size"]["height"], toggleSlider["functionName"], type);
        return std::make_shared<GToggleSlider>(
            getRelativePos(toggleSlider["position"]["x"], toggleSlider["position"]["y"]),
            getRelativePos(toggleSlider["size"]["width"], toggleSlider["size"]["height"]),
            std::string(toggleSlider["text"]),
            toggleSlider.contains("z-index") ? toggleSlider["z-index"].get<int>() : 0,
            toggleSlider["id"].get<std::string>(),
            toggleSlider["active"],
            jsonToBool(toggleSlider["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GToggleSlider>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, 0, defaultDoDisplayElement);
    }
}

std::shared_ptr<GPannel> GuiElementFactory::createPannels(const nlohmann::json &pannel, const menuType type)
{
    this->_DebugLogger->Log("Creating Pannel : " + pannel.dump(), 5);
    try {
        this->newMenuItems(pannel["position"]["x"], pannel["position"]["y"], pannel["size"]["width"], pannel["size"]["height"], pannel["functionName"], type);
        return std::make_shared<GPannel>(
            getRelativePos(pannel["position"]["x"], pannel["position"]["y"]),
            getRelativePos(pannel["size"]["width"], pannel["size"]["height"]),
            std::string(pannel["text"]),
            pannel.contains("z-index") ? pannel["z-index"].get<int>() : 0,
            pannel["id"].get<std::string>(),
            jsonToBool(pannel["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GPannel>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, defaultDoDisplayElement);
    }
}

std::shared_ptr<GColorPicker> GuiElementFactory::createColorPickers(const nlohmann::json &colorPicker, const menuType type)
{
    this->_DebugLogger->Log("Creating ColorPicker : " + colorPicker.dump(), 5);
    try {
        this->newMenuItems(colorPicker["position"]["x"], colorPicker["position"]["y"], colorPicker["size"]["width"], colorPicker["size"]["height"], colorPicker["functionName"], type);
        return std::make_shared<GColorPicker>(
            getRelativePos(colorPicker["position"]["x"], colorPicker["position"]["y"]),
            getRelativePos(colorPicker["size"]["width"], colorPicker["size"]["height"]),
            std::string(colorPicker["text"]),
            colorPicker.contains("z-index") ? colorPicker["z-index"].get<int>() : 0,
            colorPicker["id"].get<std::string>(),
            Color{colorPicker["color"]["r"], colorPicker["color"]["g"], colorPicker["color"]["b"], colorPicker["color"]["a"]},
            jsonToBool(colorPicker["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GColorPicker>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, errorText, defaultErrorZindex, defaultErrroId, defaultErrorColor, defaultDoDisplayElement);
    }
}

std::shared_ptr<GProgressBar> GuiElementFactory::createProgressBars(const nlohmann::json &progressBar, const menuType type)
{
    this->_DebugLogger->Log("Creating ProgressBar : " + progressBar.dump(), 5);
    try {
        this->newMenuItems(progressBar["position"]["x"], progressBar["position"]["y"], progressBar["size"]["width"], progressBar["size"]["height"], progressBar["functionName"], type);
        return std::make_shared<GProgressBar>(
            getRelativePos(progressBar["position"]["x"], progressBar["position"]["y"]),
            getRelativePos(progressBar["size"]["width"], progressBar["size"]["height"]),
            progressBar.contains("z-index") ? progressBar["z-index"].get<int>() : 0,
            progressBar["id"].get<std::string>(),
            std::string(progressBar["textLeft"]),
            std::string(progressBar["textRight"]),
            progressBar["value"],
            progressBar["minValue"],
            progressBar["maxValue"],
            jsonToBool(progressBar["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GProgressBar>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, defaultErrorZindex, defaultErrroId, errorText, errorText, defaultErrorZindex, 0, 0, defaultDoDisplayElement);
    }
}

std::shared_ptr<GDropDown> GuiElementFactory::createDropDowns(const nlohmann::json &dropDown, const menuType type)
{
    this->_DebugLogger->Log("Creating DropDown : " + dropDown.dump(), 5);
    try {
        this->newMenuItems(dropDown["position"]["x"], dropDown["position"]["y"], dropDown["size"]["width"], dropDown["size"]["height"], dropDown["functionName"], type);
        return std::make_shared<GDropDown>(
            getRelativePos(dropDown["position"]["x"], dropDown["position"]["y"]),
            getRelativePos(dropDown["size"]["width"], dropDown["size"]["height"]),
            std::string(dropDown["text"]),
            dropDown.contains("z-index") ? dropDown["z-index"].get<int>() : 0,
            dropDown["id"].get<std::string>(),
            dropDown["active"],
            jsonToBool(dropDown["editMode"]),
            jsonToBool(dropDown["display"])
        );
    } catch (std::exception &e) {
        std::string errorText = "error occured : " + std::string(e.what());
        this->_DebugLogger->Log(errorText, 0);
        return std::make_shared<GDropDown>(Vector2{defaultErrorPosX, defaultErrorPosY}, Vector2{defaultErrorWidth, defaultErrorHeight}, "error;occured", defaultErrorZindex, defaultErrroId, 0, false, defaultDoDisplayElement);
    }
}


std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsButtons(const nlohmann::json &jsonbuttons, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> buttons;

    this->_DebugLogger->Log("Creating Buttons", 4);
    if (jsonbuttons.contains("buttons"))
        for (auto &button : jsonbuttons["buttons"])
            buttons.push_back(this->createButtons(button, type));
    return buttons;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsWindBoxes(const nlohmann::json &jsonWindBoxes, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> windBoxes;

    this->_DebugLogger->Log("Creating WindBoxes", 4);
    if (jsonWindBoxes.contains("windBoxes"))
        for (auto &windBox : jsonWindBoxes["windBoxes"])
            windBoxes.push_back(this->createWindBox(windBox, type));
    return windBoxes;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsTexts(const nlohmann::json &jsonTexts, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> texts;

    this->_DebugLogger->Log("Creating List Texts", 4);
    if (jsonTexts.contains("texts"))
        for (auto &text : jsonTexts["texts"])
            texts.push_back(this->createTexts(text, type));
    return texts;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsCheckBoxes(const nlohmann::json &jsonCheckBoxes, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> checkBoxes;

    this->_DebugLogger->Log("Creating CheckBoxes", 4);
    if (jsonCheckBoxes.contains("checkBoxes"))
        for (auto &checkBox : jsonCheckBoxes["checkBoxes"])
            checkBoxes.push_back(this->createCheckBoxes(checkBox, type));
    return checkBoxes;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsSliders(const nlohmann::json &jsonSliders, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> sliders;

    this->_DebugLogger->Log("Creating Sliders", 4);
    if (jsonSliders.contains("sliders"))
        for (auto &slider : jsonSliders["sliders"])
            sliders.push_back(this->createSliders(slider, type));
    return sliders;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsLists(const nlohmann::json &jsonLists, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> lists;

    this->_DebugLogger->Log("Creating Lists", 4);
    if (jsonLists.contains("lists"))
        for (auto &list : jsonLists["lists"])
            lists.push_back(this->createLists(list, type));
    return lists;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsListExs(const nlohmann::json &jsonListExs, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> listExs;

    this->_DebugLogger->Log("Creating ListExs", 4);
    if (jsonListExs.contains("listExs"))
        for (auto &listEx : jsonListExs["listExs"])
            listExs.push_back(this->createListExs(listEx, type));
    return listExs;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsInputTexts(const nlohmann::json &jsonInputTexts, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> inputTexts;

    this->_DebugLogger->Log("Creating InputTexts", 4);
    if (jsonInputTexts.contains("inputTexts"))
        for (auto &inputText : jsonInputTexts["inputTexts"])
            inputTexts.push_back(this->createInputTexts(inputText, type));
    return inputTexts;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsInputTextsBoxs(const nlohmann::json &jsonInputTextBoxs, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> inputTextBoxs;

    this->_DebugLogger->Log("Creating InputTextBoxs", 4);
    if (jsonInputTextBoxs.contains("inputTextBoxs"))
        for (auto &inputTextBox : jsonInputTextBoxs["inputTextBoxs"])
            inputTextBoxs.push_back(this->createInputTextsBoxs(inputTextBox, type));
    return inputTextBoxs;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsSpinners(const nlohmann::json &jsonSpinners, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> spinners;

    this->_DebugLogger->Log("Creating Spinners", 4);
    if (jsonSpinners.contains("spinners"))
        for (auto &spinner : jsonSpinners["spinners"])
            spinners.push_back(this->createSpinners(spinner, type));
    return spinners;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsValueBoxes(const nlohmann::json &jsonValueBoxes, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> valueBoxes;

    this->_DebugLogger->Log("Creating ValueBoxes", 4);
    if (jsonValueBoxes.contains("valueBoxes"))
        for (auto &valueBox : jsonValueBoxes["valueBoxes"])
            valueBoxes.push_back(this->createValueBoxes(valueBox, type));
    return valueBoxes;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsGroups(const nlohmann::json &jsonGroups, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> groups;

    this->_DebugLogger->Log("Creating Groups", 4);
    if (jsonGroups.contains("groups"))
        for (auto &group : jsonGroups["groups"])
            groups.push_back(this->createGroups(group, type));
    return groups;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsToggleGroups(const nlohmann::json &jsonToggleGroups, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> toggleGroups;

    this->_DebugLogger->Log("Creating ToggleGroups", 4);
    if (jsonToggleGroups.contains("toggleGroups"))
        for (auto &toggleGroup : jsonToggleGroups["toggleGroups"])
            toggleGroups.push_back(this->createToggleGroups(toggleGroup, type));
    return toggleGroups;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsToggleSliders(const nlohmann::json &jsonToggleSliders, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> toggleSliders;

    this->_DebugLogger->Log("Creating ToggleSliders", 4);
    if (jsonToggleSliders.contains("toggleSliders"))
        for (auto &toggleSlider : jsonToggleSliders["toggleSliders"])
            toggleSliders.push_back(this->createToggleSliders(toggleSlider, type));
    return toggleSliders;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsPannels(const nlohmann::json &jsonPannels, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> pannels;

    this->_DebugLogger->Log("Creating Pannels", 4);
    if (jsonPannels.contains("pannels"))
        for (auto &pannel : jsonPannels["pannels"])
            pannels.push_back(this->createPannels(pannel, type));
    return pannels;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsColorPickers(const nlohmann::json &jsonColorPickers, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> colorPickers;

    this->_DebugLogger->Log("Creating ColorPickers", 4);
    if (jsonColorPickers.contains("colorPickers"))
        for (auto &colorPicker : jsonColorPickers["colorPickers"])
            colorPickers.push_back(this->createColorPickers(colorPicker, type));
    return colorPickers;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsProgressBars(const nlohmann::json &jsonProgressBars, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> progressBars;

    this->_DebugLogger->Log("Creating ProgressBars", 4);
    if (jsonProgressBars.contains("progressBars"))
        for (auto &progressBar : jsonProgressBars["progressBars"])
            progressBars.push_back(this->createProgressBars(progressBar, type));
    return progressBars;
}

std::vector<std::shared_ptr<AGuiElem>> GuiElementFactory::loadsDropDowns(const nlohmann::json &jsonDropDowns, const menuType type)
{
    std::vector<std::shared_ptr<AGuiElem>> dropDowns;

    this->_DebugLogger->Log("Creating DropDowns", 4);
    if (jsonDropDowns.contains("dropDowns"))
        for (auto &dropDown : jsonDropDowns["dropDowns"])
            dropDowns.push_back(this->createDropDowns(dropDown, type));
    return dropDowns;
}

void GuiElementFactory::newMenuItems(const nlohmann::json_abi_v3_11_3::json &x, const nlohmann::json_abi_v3_11_3::json &y, const nlohmann::json_abi_v3_11_3::json &width, const nlohmann::json_abi_v3_11_3::json &length, const std::string functionName, menuType type)
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


void GuiElementFactory::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    this->_JsonParser = jsonParser;
}

void GuiElementFactory::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    this->_DebugLogger = debugLogger;
}

void GuiElementFactory::setWindowWidth(int width)
{
    this->_WindowWidth = width;
}

void GuiElementFactory::setWindowHeight(int height)
{
    this->_WindowHeight = height;
}

std::map<menuType, std::vector<GuiElementFactory::MenuItem>> GuiElementFactory::getMenuItems() const
{
    return this->_MenuItems;
}

void GuiElementFactory::clearMenuItems()
{
    this->_MenuItems.clear();
}