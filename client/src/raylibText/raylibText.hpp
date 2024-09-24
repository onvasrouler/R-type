/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibText
*/

#pragma once

#include <string>
#include <raylib.h>

class RaylibText {
public:
    RaylibText();
    RaylibText(std::string text = "hello world", int posX = 0, int posY = 0, int fontSize = 10, Color color = BLACK);
    ~RaylibText() = default;

    void setPosX(int posX);
    void setPosY(int posY);
    void setFontSize(int fontSize);
    void setText(std::string text);

    int getPosX() const;
    int getPosY() const;
    int getFontSize() const;
    std::string getText() const;

    void DrawRlibText() const;

private:
    int posX;
    int posY;
    int fontSize;
    std::string text;
    Color color;
};