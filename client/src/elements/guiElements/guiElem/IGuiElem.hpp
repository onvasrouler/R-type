/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** IGuiElem
*/

#pragma once

#include "../../../include.hpp"

class IGuiElem {
public:
    virtual ~IGuiElem() = default;

    virtual void setText(const std::string text) = 0;
    virtual void setPos(const Vector2 pos) = 0;
    virtual void setSize(const Vector2 size) = 0;
    virtual void setValue(const std::string value) = 0;
    virtual void setId(const std::string id) = 0;
    virtual void toggleDisplay() = 0;
    virtual void setDisplay(const bool state) = 0;
    virtual void setZIndex(const int zIndex) = 0;

    virtual void draw() const = 0;

    virtual std::string getText() const = 0;
    virtual Vector2 getPos() const = 0;
    virtual Vector2 getSize() const = 0;
    virtual std::string getValue() const = 0;
    virtual std::string getId() const = 0;
    virtual bool getDisplay() const = 0;
    virtual int getZIndex() const = 0;
};
