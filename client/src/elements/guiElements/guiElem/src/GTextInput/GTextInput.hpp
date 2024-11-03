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
    GTextInput(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = DEFAULT_TEXT,const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const int textMaxSize = 100, const bool editMode = false, const bool display = DEFAULT_DISPLAY);
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
