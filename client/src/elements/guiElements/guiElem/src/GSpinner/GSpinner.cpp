/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GSpinner
*/

#include "GSpinner.hpp"

GSpinner::GSpinner(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, int value, int minValue, int maxValue, const bool editMode, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GSpinner::draw() const
{
    if (this->_Display) {
        int value = this->_Value;
        
        if (GuiSpinner(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode))
            const_cast<GSpinner*>(this)->setEditMode(!this->_EditMode);
        const_cast<GSpinner*>(this)->setSpin(value);
    }
}

void GSpinner::setSpin(const int value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

void GSpinner::setMaxValue(const int value)
{
    this->_MaxValue = value;
}

void GSpinner::setMinValue(const int value)
{
    this->_MinValue = value;
}

void GSpinner::setEditMode(const bool editMode)
{
    this->_EditMode = editMode;
}

int GSpinner::getMaxValue() const
{
    return this->_MaxValue;
}

int GSpinner::getMinValue() const
{
    return this->_MinValue;
}

bool GSpinner::getEditMode() const
{
    return this->_EditMode;
}
