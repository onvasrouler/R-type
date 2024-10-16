/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GTextInput
*/

#pragma once

#include "../../AGuiElem.hpp"

class GTextInput : public AGuiElem {
public:
    GTextInput(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default text", const std::string id = "default", const int textMaxSize = 100, const bool editMode = false, const bool display = false);
    ~GTextInput() = default;

    void draw() const;

    void setTextMaxSize(const int textmaxSize);
    void setEditMode(const bool editMode);

    int getTextMaxSize() const;
    bool getEditMode() const;

private:
    int _TextMaxSize;
    bool _EditMode;
};
