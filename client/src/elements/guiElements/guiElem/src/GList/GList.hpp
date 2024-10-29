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
    GList(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const std::string text = "default;list;text",const int zindex = defaultZIndex, const std::string id = defaultId, const bool display = defaultDisplay);
    ~GList() = default;

    void draw() const;

    void setScrollIndex(const int index);
    void setVal(const int value);

    int getScrollIndex() const;
private:
    int _ScrollIndex;
    int _Value;
};
