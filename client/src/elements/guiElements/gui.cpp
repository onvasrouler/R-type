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
//     // this->this->_Buttons[0].setAction([this]() { this->this->_WindBoxes[0].setState(true); });
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
    if (!this->_Buttons.empty())
        for (const auto &button : this->_Buttons)
            button.DrawRlibButton();
    if (!this->_WindBoxes.empty())
        for (const auto &windBox : this->_WindBoxes)
            windBox.DrawRlibWindBox();
    if (!this->_Texts.empty())
        for (const auto &text : this->_Texts)
            text.DrawRlibText();
    if (!this->_CheckBoxes.empty())
        for (const auto &checkBox : this->_CheckBoxes)
            checkBox.DrawRlibCheckBox();
    if (!this->_Sliders.empty())
        for (const auto &slider : this->_Sliders)
            slider.DrawRlibSlider();
    if (!this->_Lists.empty())
        for (const auto &list : this->_Lists)
            list.DrawRlibList();
    if (!this->_ListExs.empty())
        for (const auto &listEx : this->_ListExs)
            listEx.DrawRlibListEx();
    if (!this->_InputTexts.empty())
        for (const auto &inputText : this->_InputTexts)
            inputText.DrawRlibTextInput();
    if (!this->_InputTextsBoxs.empty())
        for (const auto &inputText : this->_InputTextsBoxs)
            inputText.DrawRlibTextInputBox();
    if (!this->_Spinners.empty())
        for (const auto &spinner : this->_Spinners)
            spinner.DrawRlibSpinner();
    if (!this->_ValueBoxes.empty())
        for (const auto &valueBox : this->_ValueBoxes)
            valueBox.DrawRlibValueBox();
    if (!this->_Groups.empty())
        for (const auto &group : this->_Groups)
            group.DrawRlibGroup();
    if (!this->_ToggleGroups.empty())
        for (const auto &toggleGroup : this->_ToggleGroups)
            toggleGroup.DrawRlibToggleGroup();
    if (!this->_ToggleSliders.empty())
        for (const auto &toggleSlider : this->_ToggleSliders)
            toggleSlider.DrawRlibToggleSlider();
    if (!this->_Pannels.empty())
        for (const auto &pannel : this->_Pannels)
            pannel.DrawRlibPannel();
    if (!this->_ColorPickers.empty())
        for (const auto &colorPicker : this->_ColorPickers)
            colorPicker.DrawRlibColorPicker();
    if (!this->_ProgressBars.empty())
        for (const auto &progressBar : this->_ProgressBars)
            progressBar.DrawRlibProgressBar();
    if (!this->_DropDowns.empty())
        for (const auto &dropDown : this->_DropDowns)
            dropDown.DrawRlibDropDown();
}





















// ----------------------- ADDERS -----------------------

void RGui::AddButton(GButton button)
{
    this->_Buttons.push_back(button);
}

void RGui::AddWindBox(GWindBox windBox)
{
    this->_WindBoxes.push_back(windBox);
}

void RGui::AddText(RaylibText text)
{
    this->_Texts.push_back(text);
}

void RGui::AddCheckBox(GCheckBox checkBox)
{
    this->_CheckBoxes.push_back(checkBox);
}

void RGui::AddSlider(GSlider slider)
{
    this->_Sliders.push_back(slider);
}

void RGui::AddList(GList list)
{
    this->_Lists.push_back(list);
}

void RGui::AddListEx(GListEx listEx)
{
    this->_ListExs.push_back(listEx);
}

void RGui::addInputText(GTextInput inputText)
{
    this->_InputTexts.push_back(inputText);
}

void RGui::addInputTextBox(GTextInputBox inputText)
{
    this->_InputTextsBoxs.push_back(inputText);
}

void RGui::addSpinner(GSpinner spinner)
{
    this->_Spinners.push_back(spinner);
}

void RGui::AddValueBox(GValueBox valueBox)
{
    this->_ValueBoxes.push_back(valueBox);
}

void RGui::AddGroup(GGroup group)
{
    this->_Groups.push_back(group);
}

void RGui::AddToggleGroup(GToggleGroup toggleGroup)
{
    this->_ToggleGroups.push_back(toggleGroup);
}

void RGui::AddToggleSlider(GToggleSlider toggleSlider)
{
    this->_ToggleSliders.push_back(toggleSlider);
}

void RGui::AddPannel(GPannel pannel)
{
    this->_Pannels.push_back(pannel);
}

void RGui::AddColorPicker(GColorPicker colorPicker)
{
    this->_ColorPickers.push_back(colorPicker);
}

void RGui::AddProgressBar(GProgressBar progressBar)
{
    this->_ProgressBars.push_back(progressBar);
}

void RGui::AddDropDown(GDropDown dropDown)
{
    this->_DropDowns.push_back(dropDown);
}

















// ----------------------- SETTERS -----------------------

void RGui::SetButtons(std::vector<GButton> buttons)
{
    this->_Buttons = buttons;
}

void RGui::SetWindBoxes(std::vector<GWindBox> windBoxes)
{
    this->_WindBoxes = windBoxes;
}

void RGui::setTexts(std::vector<RaylibText> texts)
{
    this->_Texts = texts;
}

void RGui::setCheckBoxes(std::vector<GCheckBox> checkBoxes)
{
    this->_CheckBoxes = checkBoxes;
}

void RGui::setSliders(std::vector<GSlider> sliders)
{
    this->_Sliders = sliders;
}

void RGui::setLists(std::vector<GList> lists)
{
    this->_Lists = lists;
}

void RGui::setListExs(std::vector<GListEx> listExs)
{
    this->_ListExs = listExs;
}

void RGui::setInputTexts(std::vector<GTextInput> inputTexts)
{
    this->_InputTexts = inputTexts;
}

void RGui::setInputTextsBoxs(std::vector<GTextInputBox> inputTexts)
{
    this->_InputTextsBoxs = inputTexts;
}

void RGui::setSpinners(std::vector<GSpinner> spinners)
{
    this->_Spinners = spinners;
}

void RGui::setValueBoxes(std::vector<GValueBox> valueBoxes)
{
    this->_ValueBoxes = valueBoxes;
}

void RGui::setGroups(std::vector<GGroup> groups)
{
    this->_Groups = groups;
}

void RGui::setToggleGroups(std::vector<GToggleGroup> toggleGroups)
{
    this->_ToggleGroups = toggleGroups;
}

void RGui::setToggleSliders(std::vector<GToggleSlider> toggleSliders)
{
    this->_ToggleSliders = toggleSliders;
}

void RGui::setPannels(std::vector<GPannel> pannels)
{
    this->_Pannels = pannels;
}

void RGui::setColorPickers(std::vector<GColorPicker> colorPickers)
{
    this->_ColorPickers = colorPickers;
}

void RGui::setProgressBars(std::vector<GProgressBar> progressBars)
{
    this->_ProgressBars = progressBars;
}

void RGui::setDropDowns(std::vector<GDropDown> dropDowns)
{
    this->_DropDowns = dropDowns;
}

















// ----------------------- LIST ADDER -----------------------

void RGui::addListButton(std::vector<GButton> buttons)
{
    for (const auto &button : buttons)
        this->_Buttons.push_back(button);
}

void RGui::addListWindBox(std::vector<GWindBox> windBoxes)
{
    for (const auto &windBox : windBoxes)
        this->_WindBoxes.push_back(windBox);
}

void RGui::addListText(std::vector<RaylibText> texts)
{
    for (const auto &text : texts)
        this->_Texts.push_back(text);
}

void RGui::addListCheckBox(std::vector<GCheckBox> checkBoxes)
{
    for (const auto &checkBox : checkBoxes)
        this->_CheckBoxes.push_back(checkBox);
}

void RGui::addListSlider(std::vector<GSlider> sliders)
{
    for (const auto &slider : sliders)
        this->_Sliders.push_back(slider);
}

void RGui::addListList(std::vector<GList> lists)
{
    for (const auto &list : lists)
        this->_Lists.push_back(list);
}

void RGui::addListListEx(std::vector<GListEx> listExs)
{
    for (const auto &listEx : listExs)
        this->_ListExs.push_back(listEx);
}

void RGui::addListInputText(std::vector<GTextInput> inputTexts)
{
    for (const auto &inputText : inputTexts)
        this->_InputTexts.push_back(inputText);
}

void RGui::addListInputTextBox(std::vector<GTextInputBox> inputTexts)
{
    for (const auto &inputText : inputTexts)
        this->_InputTextsBoxs.push_back(inputText);
}

void RGui::addListSpinner(std::vector<GSpinner> spinners)
{
    for (const auto &spinner : spinners)
        this->_Spinners.push_back(spinner);
}

void RGui::addListValueBox(std::vector<GValueBox> valueBoxes)
{
    for (const auto &valueBox : valueBoxes)
        this->_ValueBoxes.push_back(valueBox);
}

void RGui::addListGroup(std::vector<GGroup> groups)
{
    for (const auto &group : groups)
        this->_Groups.push_back(group);
}

void RGui::addListToggleGroup(std::vector<GToggleGroup> toggleGroups)
{
    for (const auto &toggleGroup : toggleGroups)
        this->_ToggleGroups.push_back(toggleGroup);
}

void RGui::addListToggleSlider(std::vector<GToggleSlider> toggleSliders)
{
    for (const auto &toggleSlider : toggleSliders)
        this->_ToggleSliders.push_back(toggleSlider);
}

void RGui::addListPannel(std::vector<GPannel> pannels)
{
    for (const auto &pannel : pannels)
        this->_Pannels.push_back(pannel);
}

void RGui::addListColorPicker(std::vector<GColorPicker> colorPickers)
{
    for (const auto &colorPicker : colorPickers)
        this->_ColorPickers.push_back(colorPicker);
}

void RGui::addListProgressBar(std::vector<GProgressBar> progressBars)
{
    for (const auto &progressBar : progressBars)
        this->_ProgressBars.push_back(progressBar);
}

void RGui::addListDropDown(std::vector<GDropDown> dropDowns)
{
    for (const auto &dropDown : dropDowns)
        this->_DropDowns.push_back(dropDown);
}
