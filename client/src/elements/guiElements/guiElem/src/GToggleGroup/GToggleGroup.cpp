/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GToggleGroup
*/

#include "GToggleGroup.hpp"

GToggleGroup::GToggleGroup(const Vector2 pos, const Vector2 size, const std::string text, const std::string id, int active, const bool display) : AGuiElem(pos, size, text, id, display)
{
    this->_Active = active;
}

void GToggleGroup::draw() const
{
    if (this->_Display) {
        int active = this->_Active;

        GuiToggleGroup(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
        const_cast<GToggleGroup*>(this)->setActive(active);
    }
}

void GToggleGroup::setActive(const int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

int GToggleGroup::getActive() const
{
    return this->_Active;
}
