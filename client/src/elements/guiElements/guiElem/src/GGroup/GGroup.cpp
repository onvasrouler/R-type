/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GGroup
*/

#include "GGroup.hpp"

GGroup::GGroup(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Pos = pos;
    this->_Size = size;
    this->_Text = text;
}

void GGroup::draw() const
{
    if (this->_Display) {
        GuiGroupBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
    }
}
