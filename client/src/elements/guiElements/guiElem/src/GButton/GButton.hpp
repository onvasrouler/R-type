/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GButton
*/

#pragma once

#include "../../AGuiElem.hpp"

class GButton : public AGuiElem {
public:
    GButton(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool display = DEFAULT_DISPLAY);
    ~GButton() = default;

    void draw() const;

    void setClicked(const bool state);
    
private:
    bool _isClicked = false;
};
