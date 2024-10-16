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
    GGroup(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default group text",const int zindex = 0, const std::string id = "default", const bool display = false);
    ~GGroup() = default;

    void draw() const;
};
