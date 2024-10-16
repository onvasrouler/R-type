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
    GList(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;list;text",const int zindex = 0, const std::string id = "default", const bool display = false);
    ~GList() = default;

    void draw() const;

    void setScrollIndex(const int index);
    void setVal(const int value);

    int getScrollIndex() const;
    
private:
    int _ScrollIndex;
    int _Value;
};
