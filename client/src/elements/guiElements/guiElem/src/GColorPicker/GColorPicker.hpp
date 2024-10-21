/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GColorPicker
*/

#pragma once

#include "../../AGuiElem.hpp"

class GColorPicker : public AGuiElem {
public:
    GColorPicker(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const Color color = WHITE, const bool display = defaultDisplay);
    ~GColorPicker() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _Color;
};
