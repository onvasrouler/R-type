/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#include "gui.hpp"

// RGui::RGui()
// {
//     // this->AddButton(GButton(Vector2{150, 150}, Vector2{100, 50}, "Button"));
//     // this->AddWindBox(GWindBox(Vector2{300, 300}, Vector2{100, 50}, "WindBox"));
//     // this->_buttons[0].setAction([this]() { this->_windBoxes[0].setState(true); });
//     // this->AddText(RaylibText("Hello World", Vector2{400, 400}, 20, WHITE));
//     // this->AddCheckBox(GCheckBox(Vector2{500, 500}, Vector2{100, 50}, "CheckBox"));
//     // this->AddSlider(GSlider(Vector2{300, 400}, Vector2{100, 50}, "Slider", 50, 0, 100));
//     // this->AddList(GList(Vector2{300, 500}, Vector2{100, 50}, "List;elem1;elem2;elem3"));
//     // this->AddListEx(GListEx(Vector2{500, 0}, Vector2{100, 200}, {"List", "Ex", "with", "many", "element", "to", "test", "that"}, 0));
//     // this->addInputText(GTextInput(Vector2{500, 300}, Vector2{100, 50}, "enter text"));
//     // this->addInputTextBox(GTextInputBox(Vector2{500, 400}, Vector2{200, 100}, "InputText", "Enter text:", "OK;Cancel", "default text", 100));
//     // this->addSpinner(GSpinner(Vector2{400, 400}, Vector2{100, 50}, "Spinner", 0, 0, 100));
//     // this->AddValueBox(GValueBox(Vector2{400, 500}, Vector2{100, 50}, "ValueBox", 0, 0, 100));
//     // this->AddGroup(GGroup(Vector2{0, 0}, Vector2{100, 100}, "Group"));
//     // this->AddToggleGroup(GToggleGroup(Vector2{200, 200}, Vector2{100, 100}, "elem1;elem2;elem3"));
//     //this->AddToggleSlider(GToggleSlider(Vector2{400, 400}, Vector2{100, 50}, "elem1;elem2", 0));
//     // this->AddPannel(GPannel(Vector2{400, 400}, Vector2{200, 200}, "Pannel"));
//     // this->AddColorPicker(GColorPicker(Vector2{450, 450}, Vector2{100, 100}, "ColorPicker", Color{0, 0, 0, 255}));
//     //this->AddProgressBar(GProgressBar(Vector2{400, 400}, Vector2{100, 50}, "ProgressBar", "pwogwesbaw", 50, 0, 100));
// }


// ----------------------- DRAW GUI -----------------------
void RGui::DrawGui() const
{
    if (!_Buttons.empty())
        for (const auto &button : _Buttons)
            button.DrawRlibButton();
    if (!_WindBoxes.empty())
        for (const auto &windBox : _WindBoxes)
            windBox.DrawRlibWindBox();
    if (!_Texts.empty())
        for (const auto &text : _Texts)
            text.DrawRlibText();
    if (!_CheckBoxes.empty())
        for (const auto &checkBox : _CheckBoxes)
            checkBox.DrawRlibCheckBox();
    if (!_Sliders.empty())
        for (const auto &slider : _Sliders)
            slider.DrawRlibSlider();
    if (!_Lists.empty())
        for (const auto &list : _Lists)
            list.DrawRlibList();
    if (!_ListExs.empty())
        for (const auto &listEx : _ListExs)
            listEx.DrawRlibListEx();
    if (!_InputTexts.empty())
        for (const auto &inputText : _InputTexts)
            inputText.DrawRlibTextInput();
    if (!_InputTextsBoxs.empty())
        for (const auto &inputText : _InputTextsBoxs)
            inputText.DrawRlibTextInputBox();
    if (!_Spinners.empty())
        for (const auto &spinner : _Spinners)
            spinner.DrawRlibSpinner();
    if (!_ValueBoxes.empty())
        for (const auto &valueBox : _ValueBoxes)
            valueBox.DrawRlibValueBox();
    if (!_Groups.empty())
        for (const auto &group : _Groups)
            group.DrawRlibGroup();
    if (!_ToggleGroups.empty())
        for (const auto &toggleGroup : _ToggleGroups)
            toggleGroup.DrawRlibToggleGroup();
    if (!_ToggleSliders.empty())
        for (const auto &toggleSlider : _ToggleSliders)
            toggleSlider.DrawRlibToggleSlider();
    if (!_Pannels.empty())
        for (const auto &pannel : _Pannels)
            pannel.DrawRlibPannel();
    if (!_ColorPickers.empty())
        for (const auto &colorPicker : _ColorPickers)
            colorPicker.DrawRlibColorPicker();
    if (!_ProgressBars.empty())
        for (const auto &progressBar : _ProgressBars)
            progressBar.DrawRlibProgressBar();
    if (!_DropDowns.empty())
        for (const auto &dropDown : _DropDowns)
            dropDown.DrawRlibDropDown();
}





















// ----------------------- ADDERS -----------------------

void RGui::AddButton(GButton button)
{
    _Buttons.push_back(button);
}

void RGui::AddWindBox(GWindBox windBox)
{
    _WindBoxes.push_back(windBox);
}

void RGui::AddText(RaylibText text)
{
    _Texts.push_back(text);
}

void RGui::AddCheckBox(GCheckBox checkBox)
{
    _CheckBoxes.push_back(checkBox);
}

void RGui::AddSlider(GSlider slider)
{
    _Sliders.push_back(slider);
}

void RGui::AddList(GList list)
{
    _Lists.push_back(list);
}

void RGui::AddListEx(GListEx listEx)
{
    _ListExs.push_back(listEx);
}

void RGui::addInputText(GTextInput inputText)
{
    _InputTexts.push_back(inputText);
}

void RGui::addInputTextBox(GTextInputBox inputText)
{
    _InputTextsBoxs.push_back(inputText);
}

void RGui::addSpinner(GSpinner spinner)
{
    _Spinners.push_back(spinner);
}

void RGui::AddValueBox(GValueBox valueBox)
{
    _ValueBoxes.push_back(valueBox);
}

void RGui::AddGroup(GGroup group)
{
    _Groups.push_back(group);
}

void RGui::AddToggleGroup(GToggleGroup toggleGroup)
{
    _ToggleGroups.push_back(toggleGroup);
}

void RGui::AddToggleSlider(GToggleSlider toggleSlider)
{
    _ToggleSliders.push_back(toggleSlider);
}

void RGui::AddPannel(GPannel pannel)
{
    _Pannels.push_back(pannel);
}

void RGui::AddColorPicker(GColorPicker colorPicker)
{
    _ColorPickers.push_back(colorPicker);
}

void RGui::AddProgressBar(GProgressBar progressBar)
{
    _ProgressBars.push_back(progressBar);
}

void RGui::AddDropDown(GDropDown dropDown)
{
    _DropDowns.push_back(dropDown);
}

















// ----------------------- SETTERS -----------------------

void RGui::SetButtons(std::vector<GButton> buttons)
{
    _Buttons = buttons;
}

void RGui::SetWindBoxes(std::vector<GWindBox> windBoxes)
{
    _WindBoxes = windBoxes;
}

void RGui::setTexts(std::vector<RaylibText> texts)
{
    _Texts = texts;
}

void RGui::setCheckBoxes(std::vector<GCheckBox> checkBoxes)
{
    _CheckBoxes = checkBoxes;
}

void RGui::setSliders(std::vector<GSlider> sliders)
{
    _Sliders = sliders;
}

void RGui::setLists(std::vector<GList> lists)
{
    _Lists = lists;
}

void RGui::setListExs(std::vector<GListEx> listExs)
{
    _ListExs = listExs;
}

void RGui::setInputTexts(std::vector<GTextInput> inputTexts)
{
    _InputTexts = inputTexts;
}

void RGui::setInputTextsBoxs(std::vector<GTextInputBox> inputTexts)
{
    _InputTextsBoxs = inputTexts;
}

void RGui::setSpinners(std::vector<GSpinner> spinners)
{
    _Spinners = spinners;
}

void RGui::setValueBoxes(std::vector<GValueBox> valueBoxes)
{
    _ValueBoxes = valueBoxes;
}

void RGui::setGroups(std::vector<GGroup> groups)
{
    _Groups = groups;
}

void RGui::setToggleGroups(std::vector<GToggleGroup> toggleGroups)
{
    _ToggleGroups = toggleGroups;
}

void RGui::setToggleSliders(std::vector<GToggleSlider> toggleSliders)
{
    _ToggleSliders = toggleSliders;
}

void RGui::setPannels(std::vector<GPannel> pannels)
{
    _Pannels = pannels;
}

void RGui::setColorPickers(std::vector<GColorPicker> colorPickers)
{
    _ColorPickers = colorPickers;
}

void RGui::setProgressBars(std::vector<GProgressBar> progressBars)
{
    _ProgressBars = progressBars;
}

void RGui::setDropDowns(std::vector<GDropDown> dropDowns)
{
    _DropDowns = dropDowns;
}

















// ----------------------- LIST ADDER -----------------------

void RGui::addListButton(std::vector<GButton> buttons)
{
    for (const auto &button : buttons)
        _Buttons.push_back(button);
}

void RGui::addListWindBox(std::vector<GWindBox> windBoxes)
{
    for (const auto &windBox : windBoxes)
        _WindBoxes.push_back(windBox);
}

void RGui::addListText(std::vector<RaylibText> texts)
{
    for (const auto &text : texts)
        _Texts.push_back(text);
}

void RGui::addListCheckBox(std::vector<GCheckBox> checkBoxes)
{
    for (const auto &checkBox : checkBoxes)
        _CheckBoxes.push_back(checkBox);
}

void RGui::addListSlider(std::vector<GSlider> sliders)
{
    for (const auto &slider : sliders)
        _Sliders.push_back(slider);
}

void RGui::addListList(std::vector<GList> lists)
{
    for (const auto &list : lists)
        _Lists.push_back(list);
}

void RGui::addListListEx(std::vector<GListEx> listExs)
{
    for (const auto &listEx : listExs)
        _ListExs.push_back(listEx);
}

void RGui::addListInputText(std::vector<GTextInput> inputTexts)
{
    for (const auto &inputText : inputTexts)
        _InputTexts.push_back(inputText);
}

void RGui::addListInputTextBox(std::vector<GTextInputBox> inputTexts)
{
    for (const auto &inputText : inputTexts)
        _InputTextsBoxs.push_back(inputText);
}

void RGui::addListSpinner(std::vector<GSpinner> spinners)
{
    for (const auto &spinner : spinners)
        _Spinners.push_back(spinner);
}

void RGui::addListValueBox(std::vector<GValueBox> valueBoxes)
{
    for (const auto &valueBox : valueBoxes)
        _ValueBoxes.push_back(valueBox);
}

void RGui::addListGroup(std::vector<GGroup> groups)
{
    for (const auto &group : groups)
        _Groups.push_back(group);
}

void RGui::addListToggleGroup(std::vector<GToggleGroup> toggleGroups)
{
    for (const auto &toggleGroup : toggleGroups)
        _ToggleGroups.push_back(toggleGroup);
}

void RGui::addListToggleSlider(std::vector<GToggleSlider> toggleSliders)
{
    for (const auto &toggleSlider : toggleSliders)
        _ToggleSliders.push_back(toggleSlider);
}

void RGui::addListPannel(std::vector<GPannel> pannels)
{
    for (const auto &pannel : pannels)
        _Pannels.push_back(pannel);
}

void RGui::addListColorPicker(std::vector<GColorPicker> colorPickers)
{
    for (const auto &colorPicker : colorPickers)
        _ColorPickers.push_back(colorPicker);
}

void RGui::addListProgressBar(std::vector<GProgressBar> progressBars)
{
    for (const auto &progressBar : progressBars)
        _ProgressBars.push_back(progressBar);
}

void RGui::addListDropDown(std::vector<GDropDown> dropDowns)
{
    for (const auto &dropDown : dropDowns)
        _DropDowns.push_back(dropDown);
}
