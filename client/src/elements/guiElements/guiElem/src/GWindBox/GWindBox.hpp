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
    GWindBox(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const bool isOpened = false, const bool display = defaultDisplay);
    ~GWindBox() = default;

    void draw() const;

    void setIsOpened(const bool isOpened);
private:
    bool _isOpened;
};
