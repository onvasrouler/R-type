/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GSlider
*/

#pragma once

#include "../../AGuiElem.hpp"

class GSlider : public AGuiElem {
public:
    GSlider(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = DEFAULT_DISPLAY);
    ~GSlider() = default;

    void draw() const;

    void setSliderValue(const float value);
    void setMaxValue(const float value);
    void setMinValue(const float value);

    float getMaxValue() const;
    float getMinValue() const;
private:
    float _Value;
    float _MaxValue;
    float _MinValue;
};
