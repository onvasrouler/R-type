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
    GCheckBox(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const bool checked = false, const bool display = defaultDisplay);
    ~GCheckBox() = default;

    void draw() const;

    void setChecked(const bool state);
private:
    bool _isChecked;  
};
