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
    GToggleSlider(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = "default;toggle",const int zindex = defaultZIndex, const std::string id = defaultId, const int active = 0, const bool display = defaultDisplay);
    ~GToggleSlider() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
private:
    int _Active;
};
