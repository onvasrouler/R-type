/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GDropDown
*/

#include "GDropDown.hpp"

GDropDown::GDropDown(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, int active, const bool editMode, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Active = active;
    this->_EditMode = editMode;
}

void GDropDown::draw() const
{
    int active;

    if (this->_Display) {
        active = this->_Active;
        if (GuiDropdownBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active, this->_EditMode))
            const_cast<GDropDown*>(this)->setEditMode(!this->_EditMode);
        const_cast<GDropDown*>(this)->setActive(active);
    }
}

void GDropDown::setActive(const int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

void GDropDown::setEditMode(const bool editMode)
{
    this->_EditMode = editMode;
}

int GDropDown::getActive() const
{
    return this->_Active;
}

bool GDropDown::getEditMode() const
{
    return this->_EditMode;
}
