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
    GDropDown(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = "default;drop;down;val",const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const int active = 0, const bool editMode = false, const bool display = DEFAULT_DISPLAY);
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
