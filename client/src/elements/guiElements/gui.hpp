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
    ~RGui() = default;

    void DrawGui() const;

    void AddButton(GButton button);
    void AddWindBox(GWindBox windBox);
    void AddText(RaylibText text);
    void AddCheckBox(GCheckBox checkBox);
    void AddSlider(GSlider slider);
    void AddList(GList list);
    void AddListEx(GListEx listEx);
    void addInputText(GTextInput inputText);
    void addInputTextBox(GTextInputBox inputText);
    void addSpinner(GSpinner spinner);
    void AddValueBox(GValueBox valueBox);
    void AddGroup(GGroup group);
    void AddToggleGroup(GToggleGroup toggleGroup);
    void AddToggleSlider(GToggleSlider toggleSlider);
    void AddPannel(GPannel pannel);
    void AddColorPicker(GColorPicker colorPicker);
    void AddProgressBar(GProgressBar progressBar);
    void AddDropDown(GDropDown dropDown);

    void SetButtons(std::vector<GButton> buttons);
    void SetWindBoxes(std::vector<GWindBox> windBoxes);
    void setTexts(std::vector<RaylibText> texts);
    void setCheckBoxes(std::vector<GCheckBox> checkBoxes);
    void setSliders(std::vector<GSlider> sliders);
    void setLists(std::vector<GList> lists);
    void setListExs(std::vector<GListEx> listExs);
    void setInputTexts(std::vector<GTextInput> inputTexts);
    void setInputTextsBoxs(std::vector<GTextInputBox> inputTexts);
    void setSpinners(std::vector<GSpinner> spinners);
    void setValueBoxes(std::vector<GValueBox> valueBoxes);
    void setGroups(std::vector<GGroup> groups);
    void setToggleGroups(std::vector<GToggleGroup> toggleGroups);
    void setToggleSliders(std::vector<GToggleSlider> toggleSliders);
    void setPannels(std::vector<GPannel> pannels);
    void setColorPickers(std::vector<GColorPicker> colorPickers);
    void setProgressBars(std::vector<GProgressBar> progressBars);
    void setDropDowns(std::vector<GDropDown> dropDowns);


    void addListButton(std::vector<GButton> buttons);
    void addListWindBox(std::vector<GWindBox> windBoxes);
    void addListText(std::vector<RaylibText> texts);
    void addListCheckBox(std::vector<GCheckBox> checkBoxes);
    void addListSlider(std::vector<GSlider> sliders);
    void addListList(std::vector<GList> lists);
    void addListListEx(std::vector<GListEx> listExs);
    void addListInputText(std::vector<GTextInput> inputTexts);
    void addListInputTextBox(std::vector<GTextInputBox> inputTexts);
    void addListSpinner(std::vector<GSpinner> spinners);
    void addListValueBox(std::vector<GValueBox> valueBoxes);
    void addListGroup(std::vector<GGroup> groups);
    void addListToggleGroup(std::vector<GToggleGroup> toggleGroups);
    void addListToggleSlider(std::vector<GToggleSlider> toggleSliders);
    void addListPannel(std::vector<GPannel> pannels);
    void addListColorPicker(std::vector<GColorPicker> colorPickers);
    void addListProgressBar(std::vector<GProgressBar> progressBars);
    void addListDropDown(std::vector<GDropDown> dropDowns);
private:
    std::vector<GButton> _Buttons;
    std::vector<GWindBox> _WindBoxes;
    std::vector<RaylibText> _Texts;
    std::vector<GCheckBox> _CheckBoxes;
    std::vector<GSlider> _Sliders;
    std::vector<GList> _Lists;
    std::vector<GListEx> _ListExs;
    std::vector<GTextInput> _InputTexts;
    std::vector<GTextInputBox> _InputTextsBoxs;
    std::vector<GSpinner> _Spinners;
    std::vector<GValueBox> _ValueBoxes;
    std::vector<GGroup> _Groups;
    std::vector<GToggleGroup> _ToggleGroups;
    std::vector<GToggleSlider> _ToggleSliders;
    std::vector<GPannel> _Pannels;
    std::vector<GColorPicker> _ColorPickers;
    std::vector<GProgressBar> _ProgressBars;
    std::vector<GDropDown> _DropDowns;
};
