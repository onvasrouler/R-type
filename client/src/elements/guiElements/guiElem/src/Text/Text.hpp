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
    RLText(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = "default button text", const int zindex = defaultZIndex, const Color color = {0, 0, 0, 255}, const std::string id = defaultId, const bool display = defaultDisplay);
    ~RLText() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _color;
};
