/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** Text
*/

#pragma once

#include "../../AGuiElem.hpp"

class RLText  : public AGuiElem {
public:
    RLText(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = "default button text", const int zindex = DEFAULT_Z_INDEX, const Color color = {0, 0, 0, 255}, const std::string id = DEFAULT_ID, const bool display = DEFAULT_DISPLAY);
    ~RLText() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _color;
};
