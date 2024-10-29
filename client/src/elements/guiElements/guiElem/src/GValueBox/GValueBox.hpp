/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GValueBox
*/

#pragma once

#include "../../AGuiElem.hpp"

class GValueBox : public AGuiElem {
public:
    GValueBox(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const int value = defaultIntvalue, const int minValue = 0, const int maxValue = 100, const bool editMode = false, const bool display = defaultDisplay);
    ~GValueBox() = default;

    void draw() const;

    void setBoxValue(const int value);
    void setMaxValue(const int value);
    void setMinValue(const int value);
    void setEditMode(const bool editMode);

    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;
private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};
