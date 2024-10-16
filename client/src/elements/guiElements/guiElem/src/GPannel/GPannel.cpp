/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GPannel
*/

#include "GPannel.hpp"

GPannel::GPannel(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
}

void GPannel::draw() const
{
    if (this->_Display) {
        GuiPanel(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
    }
}
