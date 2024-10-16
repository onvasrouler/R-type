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
    GDropDown(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;drop;down;val", const std::string id = "default", const int active = 0, const bool editMode = false, const bool display = false);
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
