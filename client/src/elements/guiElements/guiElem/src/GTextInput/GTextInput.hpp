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
    GTextInput(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = defaultText,const int zindex = defaultZIndex, const std::string id = defaultId, const int textMaxSize = 100, const bool editMode = false, const bool display = defaultDisplay);
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
