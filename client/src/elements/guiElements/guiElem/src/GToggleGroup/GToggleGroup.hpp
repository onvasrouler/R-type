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
    GToggleGroup(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = "default;toggle;group",const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const int active = 0, const bool display = DEFAULT_DISPLAY);
    ~GToggleGroup() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
private:
    int _Active;
};
