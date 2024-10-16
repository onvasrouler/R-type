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
    GPannel(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default pannel text", const std::string id = "default", const bool display = false);
    ~GPannel() = default;

    void draw() const;
};
