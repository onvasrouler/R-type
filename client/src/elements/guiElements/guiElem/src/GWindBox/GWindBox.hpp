/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GWindBox
*/

#pragma once

#include "../../AGuiElem.hpp"

class GWindBox : public AGuiElem {
public:
    GWindBox(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool isOpened = false, const bool display = DEFAULT_DISPLAY);
    ~GWindBox() = default;

    void draw() const;

    void setIsOpened(const bool isOpened);
private:
    bool _isOpened;
};
