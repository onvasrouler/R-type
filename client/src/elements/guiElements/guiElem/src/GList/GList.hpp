/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GList
*/

#pragma once

#include "../../AGuiElem.hpp"

class GList : public AGuiElem {
public:
    GList(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const std::string text = "default;list;text",const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const bool display = DEFAULT_DISPLAY);
    ~GList() = default;

    void draw() const;

    void setScrollIndex(const int index);
    void setVal(const int value);

    int getScrollIndex() const;
private:
    int _ScrollIndex;
    int _Value;
};
