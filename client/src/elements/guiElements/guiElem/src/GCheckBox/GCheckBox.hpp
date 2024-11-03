/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GCheckBox
*/

#pragma once

#include "../../AGuiElem.hpp"

class GCheckBox : public AGuiElem {
public:
    GCheckBox(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool checked = false, const bool display = DEFAULT_DISPLAY);
    ~GCheckBox() = default;

    void draw() const;

    void setChecked(const bool state);
private:
    bool _isChecked;  
};
