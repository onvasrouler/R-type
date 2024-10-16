/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GProgressBar
*/

#pragma once

#include "../../AGuiElem.hpp"

class GProgressBar : public AGuiElem {
public:
    GProgressBar(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const int zindex = 0, const std::string id = "default", const std::string textLeft = "default progress bar left text", const std::string textRight = "default progress bar right text", const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = false);
    ~GProgressBar() = default;

    void draw() const;

    void setProgress(const float value);
    void setMaxValue(const float value);
    void setMinValue(const float value);
    void setTextLeft(const std::string text);
    void setTextRight(const std::string text);

    std::string getTextLeft() const;
    std::string getTextRight() const;
    float getMaxValue() const;
    float getMinValue() const;
private:
    std::string _TextLeft;
    std::string _TextRight;
    float _Value;
    float _MaxValue;
    float _MinValue;
};
