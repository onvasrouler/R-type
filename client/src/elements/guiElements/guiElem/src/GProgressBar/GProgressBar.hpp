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
    GProgressBar(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const std::string textLeft = "default progress bar left text", const std::string textRight = "default progress bar right text", const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = DEFAULT_DISPLAY);
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
