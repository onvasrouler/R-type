/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GCheckBox
*/

#include "GCheckBox.hpp"

GCheckBox::GCheckBox(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool checked, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_isChecked = checked;
}

void GCheckBox::draw() const
{
    bool isChecked;

    if (this->_Display) {
        isChecked = this->_isChecked;
        if (GuiCheckBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &isChecked))
            const_cast<GCheckBox*>(this)->setChecked(isChecked);
    }
}

void GCheckBox::setChecked(const bool state)
{
    this->_isChecked = state;
    this->setValue(state ? "true" : "false");
}
