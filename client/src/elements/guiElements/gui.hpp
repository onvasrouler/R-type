/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#pragma once

#include "guiElem.hpp"
#include "../raylibText/raylibText.hpp"

class RGui {
public:
    RGui() = default;
    ~RGui();

    void DrawGui() const;

    std::string GetValueById(std::string id);

    std::shared_ptr<GButton> GetButtonsById(std::string id);
    std::shared_ptr<GWindBox> GetWindBoxesById(std::string id);
    std::shared_ptr<RaylibText> GetTextsById(std::string id);
    std::shared_ptr<GCheckBox> GetCheckBoxesById(std::string id);
    std::shared_ptr<GSlider> GetSlidersById(std::string id);
    std::shared_ptr<GList> GetListsById(std::string id);
    std::shared_ptr<GListEx> GetListExsById(std::string id);
    std::shared_ptr<GTextInput> GetInputTextsById(std::string id);
    std::shared_ptr<GTextInputBox> GetInputTextBoxsById(std::string id);
    std::shared_ptr<GSpinner> GetSpinnersById(std::string id);
    std::shared_ptr<GValueBox> GetValueBoxesById(std::string id);
    std::shared_ptr<GGroup> GetGroupsById(std::string id);
    std::shared_ptr<GToggleGroup> GetToggleGroupsById(std::string id);
    std::shared_ptr<GToggleSlider> GetToggleSlidersById(std::string id);
    std::shared_ptr<GPannel> GetPannelsById(std::string id);
    std::shared_ptr<GColorPicker> GetColorPickersById(std::string id);
    std::shared_ptr<GProgressBar> GetProgressBarsById(std::string id);
    std::shared_ptr<GDropDown> GetDropDownsById(std::string id);

    void AddButton(std::shared_ptr<GButton> button);
    void AddWindBox(std::shared_ptr<GWindBox> windBox);
    void AddText(std::shared_ptr<RaylibText> text);
    void AddCheckBox(std::shared_ptr<GCheckBox> checkBox);
    void AddSlider(std::shared_ptr<GSlider> slider);
    void AddList(std::shared_ptr<GList> list);
    void AddListEx(std::shared_ptr<GListEx> listEx);
    void AddInputText(std::shared_ptr<GTextInput> inputText);
    void AddInputTextBox(std::shared_ptr<GTextInputBox> inputTextBox);
    void AddSpinner(std::shared_ptr<GSpinner> spinner);
    void AddValueBox(std::shared_ptr<GValueBox> valueBox);
    void AddGroup(std::shared_ptr<GGroup> group);
    void AddToggleGroup(std::shared_ptr<GToggleGroup> toggleGroup);
    void AddToggleSlider(std::shared_ptr<GToggleSlider> toggleSlider);
    void AddPannel(std::shared_ptr<GPannel> pannel);
    void AddColorPicker(std::shared_ptr<GColorPicker> colorPicker);
    void AddProgressBar(std::shared_ptr<GProgressBar> progressBar);
    void AddDropDown(std::shared_ptr<GDropDown> dropDown);

    void SetButtons(std::vector<std::shared_ptr<GButton>> buttons);
    void SetWindBoxes(std::vector<std::shared_ptr<GWindBox>> windBoxes);
    void SetTexts(std::vector<std::shared_ptr<RaylibText>> texts);
    void SetCheckBoxes(std::vector<std::shared_ptr<GCheckBox>> checkBoxes);
    void SetSliders(std::vector<std::shared_ptr<GSlider>> sliders);
    void SetLists(std::vector<std::shared_ptr<GList>> lists);
    void SetListExs(std::vector<std::shared_ptr<GListEx>> listExs);
    void SetInputTexts(std::vector<std::shared_ptr<GTextInput>> inputTexts);
    void SetInputTextBoxs(std::vector<std::shared_ptr<GTextInputBox>> inputTextBoxs);
    void SetSpinners(std::vector<std::shared_ptr<GSpinner>> spinners);
    void SetValueBoxes(std::vector<std::shared_ptr<GValueBox>> valueBoxes);
    void SetGroups(std::vector<std::shared_ptr<GGroup>> groups);
    void SetToggleGroups(std::vector<std::shared_ptr<GToggleGroup>> toggleGroups);
    void SetToggleSliders(std::vector<std::shared_ptr<GToggleSlider>> toggleSliders);
    void SetPannels(std::vector<std::shared_ptr<GPannel>> pannels);
    void SetColorPickers(std::vector<std::shared_ptr<GColorPicker>> colorPickers);
    void SetProgressBars(std::vector<std::shared_ptr<GProgressBar>> progressBars);
    void SetDropDowns(std::vector<std::shared_ptr<GDropDown>> dropDowns);

    void addListButton(std::vector<std::shared_ptr<GButton>> buttons);
    void addListWindBox(std::vector<std::shared_ptr<GWindBox>> windBoxes);
    void addListText(std::vector<std::shared_ptr<RaylibText>> texts);
    void addListCheckBox(std::vector<std::shared_ptr<GCheckBox>> checkBoxes);
    void addListSlider(std::vector<std::shared_ptr<GSlider>> sliders);
    void addListList(std::vector<std::shared_ptr<GList>> lists);
    void addListListEx(std::vector<std::shared_ptr<GListEx>> listExs);
    void addListInputText(std::vector<std::shared_ptr<GTextInput>> inputTexts);
    void addListInputTextBox(std::vector<std::shared_ptr<GTextInputBox>> inputTextBoxs);
    void addListSpinner(std::vector<std::shared_ptr<GSpinner>> spinners);
    void addListValueBox(std::vector<std::shared_ptr<GValueBox>> valueBoxes);
    void addListGroup(std::vector<std::shared_ptr<GGroup>> groups);
    void addListToggleGroup(std::vector<std::shared_ptr<GToggleGroup>> toggleGroups);
    void addListToggleSlider(std::vector<std::shared_ptr<GToggleSlider>> toggleSliders);
    void addListPannel(std::vector<std::shared_ptr<GPannel>> pannels);
    void addListColorPicker(std::vector<std::shared_ptr<GColorPicker>> colorPickers);
    void addListProgressBar(std::vector<std::shared_ptr<GProgressBar>> progressBars);
    void addListDropDown(std::vector<std::shared_ptr<GDropDown>> dropDowns);
private:
    std::vector<std::shared_ptr<GButton>> _Buttons;
    std::vector<std::shared_ptr<GWindBox>> _WindBoxes;
    std::vector<std::shared_ptr<RaylibText>> _Texts;
    std::vector<std::shared_ptr<GCheckBox>> _CheckBoxes;
    std::vector<std::shared_ptr<GSlider>> _Sliders;
    std::vector<std::shared_ptr<GList>> _Lists;
    std::vector<std::shared_ptr<GListEx>> _ListExs;
    std::vector<std::shared_ptr<GTextInput>> _InputTexts;
    std::vector<std::shared_ptr<GTextInputBox>> _InputTextBoxs;
    std::vector<std::shared_ptr<GSpinner>> _Spinners;
    std::vector<std::shared_ptr<GValueBox>> _ValueBoxes;
    std::vector<std::shared_ptr<GGroup>> _Groups;
    std::vector<std::shared_ptr<GToggleGroup>> _ToggleGroups;
    std::vector<std::shared_ptr<GToggleSlider>> _ToggleSliders;
    std::vector<std::shared_ptr<GPannel>> _Pannels;
    std::vector<std::shared_ptr<GColorPicker>> _ColorPickers;
    std::vector<std::shared_ptr<GProgressBar>> _ProgressBars;
    std::vector<std::shared_ptr<GDropDown>> _DropDowns;
};
