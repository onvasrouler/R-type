/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GDropDown
*/

#pragma once

#include "../../AGuiElem.hpp"

class GDropDown : public AGuiElem {
public:
    GDropDown(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = "default;drop;down;val",const int zindex = defaultZIndex, const std::string id = defaultId, const int active = 0, const bool editMode = false, const bool display = defaultDisplay);
    ~GDropDown() = default;

    void draw() const;

    void setActive(const int active);
    void setEditMode(const bool editMode);

    int getActive() const;
    bool getEditMode() const;
private:
    int _Active;
    bool _EditMode;
};
