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
    GColorPicker(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const Color color = WHITE, const bool display = DEFAULT_DISPLAY);
    ~GColorPicker() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _Color;
};
