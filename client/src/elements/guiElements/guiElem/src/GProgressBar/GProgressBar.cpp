/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GProgressBar
*/

#include "GProgressBar.hpp"

GProgressBar::GProgressBar(const Vector2 pos, const Vector2 size, const int zindex, const std::string id, const std::string textLeft, const std::string textRight, const float value,const float minvalue,const float maxvalue, const bool display) : AGuiElem(pos, size, "default", zindex, id, display)
{
    this->_TextLeft = textLeft;
    this->_TextRight = textRight;
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GProgressBar::draw() const
{
    float value;

    if (this->_Display) {
        value = this->_Value;
        GuiProgressBar(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_TextLeft.c_str(), this->_TextRight.c_str(), &value, this->_MinValue, this->_MaxValue);
        const_cast<GProgressBar*>(this)->setProgress(value);
    }
}

void GProgressBar::setProgress(const float value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

void GProgressBar::setMaxValue(const float value)
{
    this->_MaxValue = value;
}

void GProgressBar::setMinValue(const float value)
{
    this->_MinValue = value;
}

void GProgressBar::setTextLeft(std::string text)
{
    this->_TextLeft = text;
}

void GProgressBar::setTextRight(std::string text)
{
    this->_TextRight = text;
}

std::string GProgressBar::getTextLeft() const
{
    return this->_TextLeft;
}

std::string GProgressBar::getTextRight() const
{
    return this->_TextRight;
}

float GProgressBar::getMaxValue() const
{
    return this->_MaxValue;
}

float GProgressBar::getMinValue() const
{
    return this->_MinValue;
}
