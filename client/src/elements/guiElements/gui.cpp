/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#include "gui.hpp"

RGui::~RGui()
{
    this->_Buttons.clear();
    this->_WindBoxes.clear();
    this->_Texts.clear();
    this->_CheckBoxes.clear();
    this->_Sliders.clear();
    this->_Lists.clear();
    this->_ListExs.clear();
    this->_InputTexts.clear();
    this->_InputTextBoxs.clear();
    this->_Spinners.clear();
    this->_ValueBoxes.clear();
    this->_Groups.clear();
    this->_ToggleGroups.clear();
    this->_ToggleSliders.clear();
    this->_Pannels.clear();
    this->_ColorPickers.clear();
    this->_ProgressBars.clear();
    this->_DropDowns.clear();
}

// ----------------------- DRAW GUI -----------------------
void RGui::DrawGui() const
{
    if (this->_Buttons.size() > 0)
        for (const auto &button : this->_Buttons)
            button->DrawRlibButton();
    if (this->_WindBoxes.size() > 0)
        for (const auto &windBox : this->_WindBoxes)
            windBox->DrawRlibWindBox();
    if (this->_Texts.size() > 0)
        for (const auto &text : this->_Texts)
            text->DrawRlibText();
    if (this->_CheckBoxes.size() > 0)
        for (const auto &checkBox : this->_CheckBoxes)
            checkBox->DrawRlibCheckBox();
    if (this->_Sliders.size() > 0)
        for (const auto &slider : this->_Sliders)
            slider->DrawRlibSlider();
    if (this->_Lists.size() > 0)
        for (const auto &list : this->_Lists)
            list->DrawRlibList();
    if (this->_ListExs.size() > 0)
        for (const auto &listEx : this->_ListExs)
            listEx->DrawRlibListEx();
    if (this->_InputTexts.size() > 0)
        for (const auto &inputText : this->_InputTexts)
            inputText->DrawRlibTextInput();
    if (this->_InputTextBoxs.size() > 0)
        for (const auto &inputTextBox : this->_InputTextBoxs)
            inputTextBox->DrawRlibTextInputBox();
    if (this->_Spinners.size() > 0)
        for (const auto &spinner : this->_Spinners)
            spinner->DrawRlibSpinner();
    if (this->_ValueBoxes.size() > 0)
        for (const auto &valueBox : this->_ValueBoxes)
            valueBox->DrawRlibValueBox();
    if (this->_Groups.size() > 0)
        for (const auto &group : this->_Groups)
            group->DrawRlibGroup();
    if (this->_ToggleGroups.size() > 0)
        for (const auto &toggleGroup : this->_ToggleGroups)
            toggleGroup->DrawRlibToggleGroup();
    if (this->_ToggleSliders.size() > 0)
        for (const auto &toggleSlider : this->_ToggleSliders)
            toggleSlider->DrawRlibToggleSlider();
    if (this->_Pannels.size() > 0)
        for (const auto &pannel : this->_Pannels)
            pannel->DrawRlibPannel();
    if (this->_ColorPickers.size() > 0)
        for (const auto &colorPicker : this->_ColorPickers)
            colorPicker->DrawRlibColorPicker();
    if (this->_ProgressBars.size() > 0)
        for (const auto &progressBar : this->_ProgressBars)
            progressBar->DrawRlibProgressBar();
    if (this->_DropDowns.size() > 0)
        for (const auto &dropDown : this->_DropDowns)
            dropDown->DrawRlibDropDown();
}

std::string RGui::GetValueById(std::string id) const
{
    for (const auto &button : this->_Buttons)
        if (button->getId() == id)
            return button->getValue();
    for (const auto &windBox : this->_WindBoxes)
        if (windBox->getId() == id)
            return windBox->getValue();
    for (const auto &text : this->_Texts)
        if (text->getId() == id)
            return text->getText();
    for (const auto &checkBox : this->_CheckBoxes)
        if (checkBox->getId() == id)
            return checkBox->getValue();
    for (const auto &slider : this->_Sliders)
        if (slider->getId() == id)
            return slider->getValue();
    for (const auto &list : this->_Lists)
        if (list->getId() == id)
            return list->getValue();
    for (const auto &listEx : this->_ListExs)
        if (listEx->getId() == id)
            return listEx->getValue();
    for (const auto &inputText : this->_InputTexts)
        if (inputText->getId() == id)
            return inputText->getValue();
    for (const auto &inputTextBox : this->_InputTextBoxs)
        if (inputTextBox->getId() == id)
            return inputTextBox->getValue();
    for (const auto &spinner : this->_Spinners)
        if (spinner->getId() == id)
            return spinner->getValue();
    for (const auto &valueBox : this->_ValueBoxes)
        if (valueBox->getId() == id)
            return valueBox->getValue();
    for (const auto &group : this->_Groups)
        if (group->getId() == id)
            return group->getValue();
    for (const auto &toggleGroup : this->_ToggleGroups)
        if (toggleGroup->getId() == id)
            return toggleGroup->getValue();
    for (const auto &toggleSlider : this->_ToggleSliders)
        if (toggleSlider->getId() == id)
            return toggleSlider->getValue();
    for (const auto &pannel : this->_Pannels)
        if (pannel->getId() == id)
            return pannel->getValue();
    for (const auto &colorPicker : this->_ColorPickers)
        if (colorPicker->getId() == id)
            return colorPicker->getValue();
    for (const auto &progressBar : this->_ProgressBars)
        if (progressBar->getId() == id)
            return progressBar->getValue();
    for (const auto &dropDown : this->_DropDowns)
        if (dropDown->getId() == id)
            return dropDown->getValue();
    return "";
}




// ----------------------- GETTERS BY ID -----------------------

const std::shared_ptr<GButton> RGui::GetButtonsById(std::string id) const
{
    for (const auto &button : this->_Buttons)
        if (button->getId() == id)
            return button;
    return nullptr;
}

const std::shared_ptr<GWindBox> RGui::GetWindBoxesById(std::string id) const
{
    for (const auto &windBox : this->_WindBoxes)
        if (windBox->getId() == id)
            return windBox;
    return nullptr;
}

const std::shared_ptr<RaylibText> RGui::GetTextsById(std::string id) const
{
    for (const auto &text : this->_Texts)
        if (text->getId() == id)
            return text;
    return nullptr;
}

const std::shared_ptr<GCheckBox> RGui::GetCheckBoxesById(std::string id) const
{
    for (const auto &checkBox : this->_CheckBoxes)
        if (checkBox->getId() == id)
            return checkBox;
    return nullptr;
}

const std::shared_ptr<GSlider> RGui::GetSlidersById(std::string id) const
{
    for (const auto &slider : this->_Sliders)
        if (slider->getId() == id)
            return slider;
    return nullptr;
}

const std::shared_ptr<GList> RGui::GetListsById(std::string id) const
{
    for (const auto &list : this->_Lists)
        if (list->getId() == id)
            return list;
    return nullptr;
}

const std::shared_ptr<GListEx> RGui::GetListExsById(std::string id) const
{
    for (const auto &listEx : this->_ListExs)
        if (listEx->getId() == id)
            return listEx;
    return nullptr;
}

const std::shared_ptr<GTextInput> RGui::GetInputTextsById(std::string id) const
{
    for (const auto &inputText : this->_InputTexts)
        if (inputText->getId() == id)
            return inputText;
    return nullptr;
}

const std::shared_ptr<GTextInputBox> RGui::GetInputTextBoxsById(std::string id) const
{
    for (const auto &inputTextBox : this->_InputTextBoxs)
        if (inputTextBox->getId() == id)
            return inputTextBox;
    return nullptr;
}

const std::shared_ptr<GSpinner> RGui::GetSpinnersById(std::string id) const
{
    for (const auto &spinner : this->_Spinners)
        if (spinner->getId() == id)
            return spinner;
    return nullptr;
}

const std::shared_ptr<GValueBox> RGui::GetValueBoxesById(std::string id) const
{
    for (const auto &valueBox : this->_ValueBoxes)
        if (valueBox->getId() == id)
            return valueBox;
    return nullptr;
}

const std::shared_ptr<GGroup> RGui::GetGroupsById(std::string id) const
{
    for (const auto &group : this->_Groups)
        if (group->getId() == id)
            return group;
    return nullptr;
}

const std::shared_ptr<GToggleGroup> RGui::GetToggleGroupsById(std::string id) const
{
    for (const auto &toggleGroup : this->_ToggleGroups)
        if (toggleGroup->getId() == id)
            return toggleGroup;
    return nullptr;
}

const std::shared_ptr<GToggleSlider> RGui::GetToggleSlidersById(std::string id) const
{
    for (const auto &toggleSlider : this->_ToggleSliders)
        if (toggleSlider->getId() == id)
            return toggleSlider;
    return nullptr;
}

const std::shared_ptr<GPannel> RGui::GetPannelsById(std::string id) const
{
    for (const auto &pannel : this->_Pannels)
        if (pannel->getId() == id)
            return pannel;
    return nullptr;
}

const std::shared_ptr<GColorPicker> RGui::GetColorPickersById(std::string id) const
{
    for (const auto &colorPicker : this->_ColorPickers)
        if (colorPicker->getId() == id)
            return colorPicker;
    return nullptr;
}

const std::shared_ptr<GProgressBar> RGui::GetProgressBarsById(std::string id) const
{
    for (const auto &progressBar : this->_ProgressBars)
        if (progressBar->getId() == id)
            return progressBar;
    return nullptr;
}

const std::shared_ptr<GDropDown> RGui::GetDropDownsById(std::string id) const
{
    for (const auto &dropDown : this->_DropDowns)
        if (dropDown->getId() == id)
            return dropDown;
    return nullptr;
}
















// ----------------------- ADDERS -----------------------

void RGui::AddButton(const std::shared_ptr<GButton> button)
{
    this->_Buttons.push_back(button);
}
void RGui::AddWindBox(const std::shared_ptr<GWindBox> windBox)
{
    this->_WindBoxes.push_back(windBox);
}

void RGui::AddText(const std::shared_ptr<RaylibText> text)
{
    this->_Texts.push_back(text);
}

void RGui::AddCheckBox(const std::shared_ptr<GCheckBox> checkBox)
{
    this->_CheckBoxes.push_back(checkBox);
}

void RGui::AddSlider(const std::shared_ptr<GSlider> slider)
{
    this->_Sliders.push_back(slider);
}

void RGui::AddList(const std::shared_ptr<GList> list)
{
    this->_Lists.push_back(list);
}

void RGui::AddListEx(const std::shared_ptr<GListEx> listEx)
{
    this->_ListExs.push_back(listEx);
}

void RGui::AddInputText(const std::shared_ptr<GTextInput> inputText)
{
    this->_InputTexts.push_back(inputText);
}

void RGui::AddInputTextBox(const std::shared_ptr<GTextInputBox> inputTextBox)
{
    this->_InputTextBoxs.push_back(inputTextBox);
}

void RGui::AddSpinner(const std::shared_ptr<GSpinner> spinner)
{
    this->_Spinners.push_back(spinner);
}

void RGui::AddValueBox(const std::shared_ptr<GValueBox> valueBox)
{
    this->_ValueBoxes.push_back(valueBox);
}

void RGui::AddGroup(const std::shared_ptr<GGroup> group)
{
    this->_Groups.push_back(group);
}

void RGui::AddToggleGroup(const std::shared_ptr<GToggleGroup> toggleGroup)
{
    this->_ToggleGroups.push_back(toggleGroup);
}

void RGui::AddToggleSlider(const std::shared_ptr<GToggleSlider> toggleSlider)
{
    this->_ToggleSliders.push_back(toggleSlider);
}

void RGui::AddPannel(const std::shared_ptr<GPannel> pannel)
{
    this->_Pannels.push_back(pannel);
}

void RGui::AddColorPicker(const std::shared_ptr<GColorPicker> colorPicker)
{
    this->_ColorPickers.push_back(colorPicker);
}

void RGui::AddProgressBar(const std::shared_ptr<GProgressBar> progressBar)
{
    this->_ProgressBars.push_back(progressBar);
}

void RGui::AddDropDown(const std::shared_ptr<GDropDown> dropDown)
{
    this->_DropDowns.push_back(dropDown);
}

















// ----------------------- SETTERS -----------------------

void RGui::SetButtons(std::vector<std::shared_ptr<GButton>> buttons)
{
    this->_Buttons = buttons;
}

void RGui::SetWindBoxes(std::vector<std::shared_ptr<GWindBox>> windBoxes)
{
    this->_WindBoxes = windBoxes;
}

void RGui::SetTexts(std::vector<std::shared_ptr<RaylibText>> texts)
{
    this->_Texts = texts;
}

void RGui::SetCheckBoxes(std::vector<std::shared_ptr<GCheckBox>> checkBoxes)
{
    this->_CheckBoxes = checkBoxes;
}

void RGui::SetSliders(std::vector<std::shared_ptr<GSlider>> sliders)
{
    this->_Sliders = sliders;
}

void RGui::SetLists(std::vector<std::shared_ptr<GList>> lists)
{
    this->_Lists = lists;
}

void RGui::SetListExs(std::vector<std::shared_ptr<GListEx>> listExs)
{
    this->_ListExs = listExs;
}

void RGui::SetInputTexts(std::vector<std::shared_ptr<GTextInput>> inputTexts)
{
    this->_InputTexts = inputTexts;
}

void RGui::SetInputTextBoxs(std::vector<std::shared_ptr<GTextInputBox>> inputTextBoxs)
{
    this->_InputTextBoxs = inputTextBoxs;
}

void RGui::SetSpinners(std::vector<std::shared_ptr<GSpinner>> spinners)
{
    this->_Spinners = spinners;
}

void RGui::SetValueBoxes(std::vector<std::shared_ptr<GValueBox>> valueBoxes)
{
    this->_ValueBoxes = valueBoxes;
}

void RGui::SetGroups(std::vector<std::shared_ptr<GGroup>> groups)
{
    this->_Groups = groups;
}

void RGui::SetToggleGroups(std::vector<std::shared_ptr<GToggleGroup>> toggleGroups)
{
    this->_ToggleGroups = toggleGroups;
}

void RGui::SetToggleSliders(std::vector<std::shared_ptr<GToggleSlider>> toggleSliders)
{
    this->_ToggleSliders = toggleSliders;
}

void RGui::SetPannels(std::vector<std::shared_ptr<GPannel>> pannels)
{
    this->_Pannels = pannels;
}

void RGui::SetColorPickers(std::vector<std::shared_ptr<GColorPicker>> colorPickers)
{
    this->_ColorPickers = colorPickers;
}

void RGui::SetProgressBars(std::vector<std::shared_ptr<GProgressBar>> progressBars)
{
    this->_ProgressBars = progressBars;
}

void RGui::SetDropDowns(std::vector<std::shared_ptr<GDropDown>> dropDowns)
{
    this->_DropDowns = dropDowns;
}

















// ----------------------- LIST ADDER -----------------------

void RGui::addListButton(std::vector<std::shared_ptr<GButton>> buttons)
{
    this->_Buttons.insert(this->_Buttons.end(), buttons.begin(), buttons.end());
}

void RGui::addListWindBox(std::vector<std::shared_ptr<GWindBox>> windBoxes)
{
    this->_WindBoxes.insert(this->_WindBoxes.end(), windBoxes.begin(), windBoxes.end());
}

void RGui::addListText(std::vector<std::shared_ptr<RaylibText>> texts)
{
    this->_Texts.insert(this->_Texts.end(), texts.begin(), texts.end());
}

void RGui::addListCheckBox(std::vector<std::shared_ptr<GCheckBox>> checkBoxes)
{
    this->_CheckBoxes.insert(this->_CheckBoxes.end(), checkBoxes.begin(), checkBoxes.end());
}

void RGui::addListSlider(std::vector<std::shared_ptr<GSlider>> sliders)
{
    this->_Sliders.insert(this->_Sliders.end(), sliders.begin(), sliders.end());
}

void RGui::addListList(std::vector<std::shared_ptr<GList>> lists)
{
    this->_Lists.insert(this->_Lists.end(), lists.begin(), lists.end());
}

void RGui::addListListEx(std::vector<std::shared_ptr<GListEx>> listExs)
{
    this->_ListExs.insert(this->_ListExs.end(), listExs.begin(), listExs.end());
}

void RGui::addListInputText(std::vector<std::shared_ptr<GTextInput>> inputTexts)
{
    this->_InputTexts.insert(this->_InputTexts.end(), inputTexts.begin(), inputTexts.end());
}

void RGui::addListInputTextBox(std::vector<std::shared_ptr<GTextInputBox>> inputTextBoxs)
{
    this->_InputTextBoxs.insert(this->_InputTextBoxs.end(), inputTextBoxs.begin(), inputTextBoxs.end());
}

void RGui::addListSpinner(std::vector<std::shared_ptr<GSpinner>> spinners)
{
    this->_Spinners.insert(this->_Spinners.end(), spinners.begin(), spinners.end());
}

void RGui::addListValueBox(std::vector<std::shared_ptr<GValueBox>> valueBoxes)
{
    this->_ValueBoxes.insert(this->_ValueBoxes.end(), valueBoxes.begin(), valueBoxes.end());
}

void RGui::addListGroup(std::vector<std::shared_ptr<GGroup>> groups)
{
    this->_Groups.insert(this->_Groups.end(), groups.begin(), groups.end());
}

void RGui::addListToggleGroup(std::vector<std::shared_ptr<GToggleGroup>> toggleGroups)
{
    this->_ToggleGroups.insert(this->_ToggleGroups.end(), toggleGroups.begin(), toggleGroups.end());
}

void RGui::addListToggleSlider(std::vector<std::shared_ptr<GToggleSlider>> toggleSliders)
{
    this->_ToggleSliders.insert(this->_ToggleSliders.end(), toggleSliders.begin(), toggleSliders.end());
}

void RGui::addListPannel(std::vector<std::shared_ptr<GPannel>> pannels)
{
    this->_Pannels.insert(this->_Pannels.end(), pannels.begin(), pannels.end());
}

void RGui::addListColorPicker(std::vector<std::shared_ptr<GColorPicker>> colorPickers)
{
    this->_ColorPickers.insert(this->_ColorPickers.end(), colorPickers.begin(), colorPickers.end());
}

void RGui::addListProgressBar(std::vector<std::shared_ptr<GProgressBar>> progressBars)
{
    this->_ProgressBars.insert(this->_ProgressBars.end(), progressBars.begin(), progressBars.end());
}

void RGui::addListDropDown(std::vector<std::shared_ptr<GDropDown>> dropDowns)
{
    this->_DropDowns.insert(this->_DropDowns.end(), dropDowns.begin(), dropDowns.end());
}