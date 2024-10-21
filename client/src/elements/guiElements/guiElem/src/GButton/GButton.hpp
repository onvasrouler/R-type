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
    GButton(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const bool display = defaultDisplay);
    ~GButton() = default;

    void draw() const;

    void setClicked(const bool state);
    
private:
    bool _isClicked = false;
};
