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
    GToggleGroup(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = "default;toggle;group",const int zindex = defaultZIndex, const std::string id = defaultId, const int active = 0, const bool display = defaultDisplay);
    ~GToggleGroup() = default;

    void draw() const;

    void setActive(const int active);

    int getActive() const;
private:
    int _Active;
};
