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
    RGui();
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

    void SetButtons(std::vector<GButton> buttons);
    void SetWindBoxes(std::vector<GWindBox> windBoxes);
    void setTexts(std::vector<RaylibText> texts);
    void setCheckBoxes(std::vector<GCheckBox> checkBoxes);
    void setSliders(std::vector<GSlider> sliders);
    void setLists(std::vector<GList> lists);
    void setListExs(std::vector<GListEx> listExs);
    void setInputTexts(std::vector<GTextInput> inputTexts);
    void setInputTextsBoxs(std::vector<GTextInputBox> inputTexts);
private:
    std::vector<GButton> _buttons;
    std::vector<GWindBox> _windBoxes;
    std::vector<RaylibText> _texts;
    std::vector<GCheckBox> _checkBoxes;
    std::vector<GSlider> _sliders;
    std::vector<GList> _lists;
    std::vector<GListEx> _listExs;
    std::vector<GTextInput> _inputTexts;
    std::vector<GTextInputBox> _inputTextsBoxs;
};
