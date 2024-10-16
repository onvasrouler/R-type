/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GSpinner
*/

#pragma once

#include "../../AGuiElem.hpp"

class GSpinner : public AGuiElem {
public:
    GSpinner(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default spinner text", const std::string id = "default", const int value = 0, const int minValue = 0, const int maxValue = 100, const bool editMode = false, const bool display = false);
    ~GSpinner() = default;

    void draw() const;

    void setSpin(const int value);
    void setMaxValue(const int value);
    void setMinValue(const int value);
    void setEditMode(const bool editMode);

    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;

private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};