/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#include "gui.hpp"

RGui::RGui()
{
    this->AddButton(GButton(Vector2{150, 150}, Vector2{100, 50}, "Button"));
    this->AddWindBox(GWindBox(Vector2{300, 300}, Vector2{100, 50}, "WindBox"));
    this->_buttons[0].setAction([this]() { this->_windBoxes[0].setState(true); });
    this->AddText(RaylibText("Hello World", Vector2{400, 400}, 20, WHITE));
    this->AddCheckBox(GCheckBox(Vector2{500, 500}, Vector2{100, 50}, "CheckBox"));
    this->AddSlider(GSlider(Vector2{300, 400}, Vector2{100, 50}, "Slider", 50, 0, 100));
    this->AddList(GList(Vector2{300, 500}, Vector2{100, 50}, "List;elem1;elem2;elem3"));
    this->AddListEx(GListEx(Vector2{500, 0}, Vector2{100, 200}, {"List", "Ex", "with", "many", "element", "to", "test", "that"}, 0));
    this->addInputText(GTextInput(Vector2{500, 300}, Vector2{100, 50}, "enter text"));
    this->addInputTextBox(GTextInputBox(Vector2{500, 400}, Vector2{200, 100}, "InputText", "Enter text:", "OK;Cancel", "default text", 100));
}


// ----------------------- DRAW GUI -----------------------
void RGui::DrawGui() const
{
    if (!_buttons.empty())
        for (const auto &button : _buttons)
            button.DrawRlibButton();
    if (!_windBoxes.empty())
        for (const auto &windBox : _windBoxes)
            windBox.DrawRlibWindBox();
    if (!_texts.empty())
        for (const auto &text : _texts)
            text.DrawRlibText();
    if (!_checkBoxes.empty())
        for (const auto &checkBox : _checkBoxes)
            checkBox.DrawRlibCheckBox();
    if (!_sliders.empty())
        for (const auto &slider : _sliders)
            slider.DrawRlibSlider();
    if (!_lists.empty())
        for (const auto &list : _lists)
            list.DrawRlibList();
    if (!_listExs.empty())
        for (const auto &listEx : _listExs)
            listEx.DrawRlibListEx();
    if (!_inputTexts.empty())
        for (const auto &inputText : _inputTexts)
            inputText.DrawRlibTextInput();
    if (!_inputTextsBoxs.empty())
        for (const auto &inputText : _inputTextsBoxs)
            inputText.DrawRlibTextInputBox();
}





















// ----------------------- ADDERS -----------------------

void RGui::AddButton(GButton button)
{
    _buttons.push_back(button);
}

void RGui::AddWindBox(GWindBox windBox)
{
    _windBoxes.push_back(windBox);
}

void RGui::AddText(RaylibText text)
{
    _texts.push_back(text);
}

void RGui::AddCheckBox(GCheckBox checkBox)
{
    _checkBoxes.push_back(checkBox);
}

void RGui::AddSlider(GSlider slider)
{
    _sliders.push_back(slider);
}

void RGui::AddList(GList list)
{
    _lists.push_back(list);
}

void RGui::AddListEx(GListEx listEx)
{
    _listExs.push_back(listEx);
}

void RGui::addInputText(GTextInput inputText)
{
    _inputTexts.push_back(inputText);
}

void RGui::addInputTextBox(GTextInputBox inputText)
{
    _inputTextsBoxs.push_back(inputText);
}





















// ----------------------- SETTERS -----------------------

void RGui::SetButtons(std::vector<GButton> buttons)
{
    _buttons = buttons;
}

void RGui::SetWindBoxes(std::vector<GWindBox> windBoxes)
{
    _windBoxes = windBoxes;
}

void RGui::setTexts(std::vector<RaylibText> texts)
{
    _texts = texts;
}

void RGui::setCheckBoxes(std::vector<GCheckBox> checkBoxes)
{
    _checkBoxes = checkBoxes;
}

void RGui::setSliders(std::vector<GSlider> sliders)
{
    _sliders = sliders;
}

void RGui::setLists(std::vector<GList> lists)
{
    _lists = lists;
}

void RGui::setListExs(std::vector<GListEx> listExs)
{
    _listExs = listExs;
}

void RGui::setInputTexts(std::vector<GTextInput> inputTexts)
{
    _inputTexts = inputTexts;
}

void RGui::setInputTextsBoxs(std::vector<GTextInputBox> inputTexts)
{
    _inputTextsBoxs = inputTexts;
}
