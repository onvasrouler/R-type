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
    GListEx(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string id = "default", const std::vector<std::string> list = {"default", "list", "text"}, const int active = 0, const bool display = false);
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
