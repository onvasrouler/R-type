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
    GGroup(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText, const int zindex = defaultZIndex, const std::string id = defaultId, const bool display = defaultDisplay);
    ~GGroup() = default;

    void draw() const;
};
