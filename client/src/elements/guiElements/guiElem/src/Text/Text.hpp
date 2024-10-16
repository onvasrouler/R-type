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
    RLText(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default button text", const int zindex = 0, const Color color = {0, 0, 0, 255}, const std::string id = "default", const bool display = false);
    ~RLText() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _color;
};
