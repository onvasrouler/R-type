/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GToggleSlider
*/

#include "GToggleSlider.hpp"

GToggleSlider::GToggleSlider(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, int active, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Active = active;
}

void GToggleSlider::draw() const
{
    int active;

    if (this->_Display) {
        active = this->_Active;
        GuiToggleSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
        const_cast<GToggleSlider*>(this)->setActive(active);
    }

}

void GToggleSlider::setActive(const int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

int GToggleSlider::getActive() const
{
    return this->_Active;
}
