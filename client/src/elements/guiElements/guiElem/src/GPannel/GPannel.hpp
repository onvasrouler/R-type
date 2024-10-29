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
    GPannel(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const bool display = defaultDisplay);
    ~GPannel() = default;

    void draw() const;
};
