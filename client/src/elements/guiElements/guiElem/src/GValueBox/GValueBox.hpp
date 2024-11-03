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
    GValueBox(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const int value = DEFAULT_INT_VALUE, const int minValue = 0, const int maxValue = 100, const bool editMode = false, const bool display = DEFAULT_DISPLAY);
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
