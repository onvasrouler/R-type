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
    GSlider(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default slider text",const int zindex = 0, const std::string id = "default", const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = false);
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
