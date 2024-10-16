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
    GCheckBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default checkbox text",const int zindex = 0, const std::string id = "default", const bool checked = false, const bool display = false);
    ~GCheckBox() = default;

    void draw() const;

    void setChecked(const bool state);

private:
    bool _isChecked;
    
};
