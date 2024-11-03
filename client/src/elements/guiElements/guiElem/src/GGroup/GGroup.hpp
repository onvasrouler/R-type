/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GGroup
*/

#pragma once

#include "../../AGuiElem.hpp"

class GGroup : public AGuiElem {
public:
    GGroup(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool display = DEFAULT_DISPLAY);
    ~GGroup() = default;

    void draw() const;
};
