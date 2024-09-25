/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibText
*/

#pragma once

#include "../../include.hpp"

class RaylibText {
public:
    RaylibText();
    RaylibText(std::string text = "hello world", Vector2 pos = {0, 0}, int fontSize = 10, Color color = BLACK);
    RaylibText(std::string text = "hello world", Vector2 pos = {0, 0}, int fontSize = 10, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);

    ~RaylibText() = default;

    void setPosX(int posX);
    void setPosY(int posY);
    void setPos(Vector2 pos);
    void setFontSize(int fontSize);
    void setText(std::string text);

    int getPosX() const;
    int getPosY() const;
    Vector2 getPos() const;
    int getFontSize() const;
    std::string getText() const;

    void DrawRlibText() const;

private:
    Vector2 _Position;
    int _FontSize;
    std::string _Text;
    Color _Color;
};