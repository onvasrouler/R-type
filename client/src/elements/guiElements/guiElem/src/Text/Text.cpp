/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** Text
*/

#include "Text.hpp"

RLText::RLText(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const Color color, const std::string id, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_color = color;
    this->_Value = text;
}

void RLText::draw() const
{
    if (this->_Display)
        DrawText(this->_Text.c_str(), this->_Pos.x, this->_Pos.y, this->_Size.y, this->_color);
}

void RLText::setColor(const Color color)
{
    this->_color = color;
}

Color RLText::getColor() const
{
    return this->_color;
}