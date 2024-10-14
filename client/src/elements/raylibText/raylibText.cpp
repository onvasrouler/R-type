/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibText
*/

#include "raylibText.hpp"

RaylibText::RaylibText()
{
    this->_Position = {0, 0};
    this->_FontSize = 10;
    this->_Text = "Hello, World!";
    this->_Color = BLACK;
    this->_Display = true;
    this->_Id = "default";
}

RaylibText::RaylibText(std::string text, Vector2 pos, int fontSize, Color color, std::string id, bool display)
{
    this->_Position = pos;
    this->_FontSize = fontSize;
    this->_Text = text;
    this->_Color = color;
    this->_Display = display;
    this->_Id = id;
}

RaylibText::RaylibText(std::string text, Vector2 pos, int fontSize, unsigned char r, unsigned char g, unsigned char b, unsigned char a, std::string id, bool display)
{
    this->_Position = pos;
    this->_FontSize = fontSize;
    this->_Text = text;
    this->_Color = {r, g, b, a};
    this->_Display = display;
    this->_Id = id;
}

void RaylibText::setPosX(int posX)
{
    this->_Position.x = posX;
}

void RaylibText::setPosY(int posY)
{
    this->_Position.y = posY;
}

void RaylibText::setPos(Vector2 pos)
{
    this->_Position = pos;
}

void RaylibText::setFontSize(int fontSize)
{
    this->_FontSize = fontSize;
}

void RaylibText::setText(std::string text)
{
    this->_Text = text;
}

void RaylibText::setColor(Color color)
{
    this->_Color = color;
}

void RaylibText::setDisplay(bool display)
{
    this->_Display = display;
}

void RaylibText::setId(std::string id)
{
    this->_Id = id;
}

int RaylibText::getPosX() const
{
    return this->_Position.x;
}

int RaylibText::getPosY() const
{
    return this->_Position.y;
}

Vector2 RaylibText::getPos() const
{
    return this->_Position;
}

int RaylibText::getFontSize() const
{
    return this->_FontSize;
}

std::string RaylibText::getText() const
{
    return this->_Text;
}

Color RaylibText::getColor() const
{
    return this->_Color;
}

bool RaylibText::getDisplay() const
{
    return this->_Display;
}

std::string RaylibText::getId() const
{
    return this->_Id;
}

void RaylibText::DrawRlibText() const
{
    if (!this->_Display)
        return;
    DrawText(_Text.c_str(), _Position.x, _Position.y, _FontSize, _Color);
}
