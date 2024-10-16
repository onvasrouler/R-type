/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GValueBox
*/

#include "GValueBox.hpp"

GValueBox::GValueBox(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, int value, int minValue, int maxValue, const bool editMode, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GValueBox::draw() const
{
    if (this->_Display) {
        int value = this->_Value;

        if (GuiValueBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode)) {
            const_cast<GValueBox*>(this)->setEditMode(!this->_EditMode);
        }
        
        const_cast<GValueBox*>(this)->setBoxValue(value);
    }

    
}

void GValueBox::setBoxValue(const int value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

void GValueBox::setMaxValue(const int value)
{
    this->_MaxValue = value;
}

void GValueBox::setMinValue(const int value)
{
    this->_MinValue = value;
}

void GValueBox::setEditMode(const bool editMode)
{
    this->_EditMode = editMode;
}

int GValueBox::getMaxValue() const
{
    return this->_MaxValue;
}

int GValueBox::getMinValue() const
{
    return this->_MinValue;
}

bool GValueBox::getEditMode() const
{
    return this->_EditMode;
}
