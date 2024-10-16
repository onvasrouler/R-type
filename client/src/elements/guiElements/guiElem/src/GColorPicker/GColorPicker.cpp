/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GColorPicker
*/

#include "GColorPicker.hpp"

GColorPicker::GColorPicker(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const Color color, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Color = color;
}

void GColorPicker::draw() const
{
    if (this->_Display) {
        Color color = this->_Color;

        GuiColorPicker(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &color);
        const_cast<GColorPicker*>(this)->setColor(color);
    }
}

void GColorPicker::setColor(Color color)
{
    this->_Color = color;
    this->setValue(std::to_string(color.r) + " " + std::to_string(color.g) + " " + std::to_string(color.b) + " " + std::to_string(color.a));
}

Color GColorPicker::getColor() const
{
    return this->_Color;
}
