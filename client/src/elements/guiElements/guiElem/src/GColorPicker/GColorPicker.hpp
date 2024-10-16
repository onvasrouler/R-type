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
    GColorPicker(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default color picker text", const std::string id = "default", const Color color = WHITE, const bool display = false);
    ~GColorPicker() = default;

    void draw() const;

    void setColor(const Color color);

    Color getColor() const;
private:
    Color _Color;
};
