/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GSlider
*/

#include "GSlider.hpp"

GSlider::GSlider(const Vector2 pos, const Vector2 size, const std::string text, const std::string id,const float value,const float minvalue,const float maxvalue, const bool display) : AGuiElem(pos, size, text, id, display)
{
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GSlider::draw() const
{
    if (this->_Display) {
        float value = this->_Value;

        if (GuiSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), TextFormat("%2.2f", value), &value, this->_MinValue, this->_MaxValue)) {
            const_cast<GSlider*>(this)->setSliderValue(value);
        }
    }
}

void GSlider::setSliderValue(const float value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

void GSlider::setMaxValue(const float value)
{
    this->_MaxValue = value;
}

void GSlider::setMinValue(const float value)
{
    this->_MinValue = value;
}

float GSlider::getMaxValue() const
{
    return this->_MaxValue;
}

float GSlider::getMinValue() const
{
    return this->_MinValue;
}
