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
    GToggleSlider(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = "default;toggle",const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const int active = 0, const bool display = DEFAULT_DISPLAY);
    ~GToggleSlider() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
private:
    int _Active;
};
