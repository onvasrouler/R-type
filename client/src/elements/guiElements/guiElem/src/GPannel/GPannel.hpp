/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GPannel
*/

#pragma once

#include "../../AGuiElem.hpp"

class GPannel : public AGuiElem {
public:
    GPannel(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool display = DEFAULT_DISPLAY);
    ~GPannel() = default;

    void draw() const;
};
