/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GListEx
*/

#pragma once

#include "../../AGuiElem.hpp"

class GListEx : public AGuiElem {
public:
    GListEx(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const int zindex = defaultZIndex, const std::string id = defaultId, const std::vector<std::string> list = {"default", "list", "text"}, const int active = 0, const bool display = defaultDisplay);
    ~GListEx() = default;

    void draw() const;

    void setList(const std::vector<std::string> list);
    void setActive(const int active);
    void setFocus(const int focus);
    void setScrollIndex(const int index);

    int getScrollIndex() const;
    int getFocus() const;
    int getActive() const;
    std::vector<std::string> getList() const;
    
private:
    std::vector<std::string> _List;
    int _active;
    int _ScrollIndex;
    int _Active;
    int _Focus;
};
