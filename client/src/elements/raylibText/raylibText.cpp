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
    this-> _Color = BLACK;
}

RaylibText::RaylibText(std::string text, Vector2 pos, int fontSize, Color color)
{
    this->_Position = pos;
    this->_FontSize = fontSize;
    this->_Text = text;
    this->_Color = color;
}

RaylibText::RaylibText(std::string text, Vector2 pos, int fontSize, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_Position = pos;
    this->_FontSize = fontSize;
    this->_Text = text;
    this->_Color = {r, g, b, a};
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

int RaylibText::getPosX() const
{
    return _Position.x;
}

int RaylibText::getPosY() const
{
    return _Position.y;
}

Vector2 RaylibText::getPos() const
{
    return _Position;
}

int RaylibText::getFontSize() const
{
    return _FontSize;
}

std::string RaylibText::getText() const
{
    return _Text;
}

void RaylibText::DrawRlibText() const
{
    DrawText(_Text.c_str(), _Position.x, _Position.y, _FontSize, BLACK);
}

