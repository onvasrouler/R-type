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
    GButton(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default button text", const std::string id = "default", const bool display = false);
    ~GButton() = default;

    void draw() const;

    void setClicked(const bool state);
    
private:
    bool _isClicked = false;
};
