/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** IGuiElem
*/

#pragma once

#include "IGuiElem.hpp"

class AGuiElem : public IGuiElem {
public:
    AGuiElem(const Vector2 pos = {0, 0}, const Vector2 size = {100, 50}, const std::string text = "default", const std::string id = "default", const bool display = false);
    virtual ~AGuiElem() = default;

    virtual void draw() const = 0;

    void setText(const std::string text);
    void setPos(const Vector2 pos);
    void setSize(const Vector2 size);
    void setValue(const std::string value);
    void setId(const std::string id);
    void setDisplay(const bool state);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    std::string getValue() const;
    std::string getId() const;
    bool getDisplay() const;

protected:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    std::string _Value;
    std::string _Id;
    bool _Display;
};
