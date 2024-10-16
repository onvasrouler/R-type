/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GWindBox
*/

#pragma once

#include "../../AGuiElem.hpp"

class GWindBox : public AGuiElem {
public:
    GWindBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default window box text", const std::string id = "default", const bool isOpened = false, const bool display = false);
    ~GWindBox() = default;

    void draw() const;

    void setIsOpened(const bool isOpened);

private:
    bool _isOpened;
};
