/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GButton
*/

#include "GButton.hpp"

GButton::GButton(const Vector2 pos, const Vector2 size, const std::string text, const std::string id, const bool display) : AGuiElem(pos, size, text, id, display)
{
    this->_isClicked = false;
}

void GButton::draw() const
{
    if (this->_Display) {
        if (GuiButton(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str())) {
            const_cast<GButton*>(this)->setClicked(true);
        } else {
            const_cast<GButton*>(this)->setClicked(false);
        }
    }
}

void GButton::setClicked(const bool state)
{
    this->_isClicked = state;
    this->setValue(state ? "true" : "false");
}
