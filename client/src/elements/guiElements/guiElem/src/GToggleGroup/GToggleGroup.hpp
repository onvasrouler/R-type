/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GToggleGroup
*/

#pragma once

#include "../../AGuiElem.hpp"

class GToggleGroup : public AGuiElem {
public:
    GToggleGroup(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;toggle;group",const int zindex = 0, const std::string id = "default", const int active = 0, const bool display = false);
    ~GToggleGroup() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
private:
    int _Active;
};
