/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GToggleSlider
*/

#pragma once

#include "../../AGuiElem.hpp"

class GToggleSlider : public AGuiElem {
public:
    GToggleSlider(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;toggle", const std::string id = "default", const int active = 0, const bool display = false);
    ~GToggleSlider() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
    
private:
    int _Active;
};
