/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibText
*/

#include "raylibText.hpp"

RaylibText::RaylibText()
{
    posX = 0;
    posY = 0;
    fontSize = 10;
    text = "Hello, World!";
    color = BLACK;
}

RaylibText::RaylibText(std::string text, int posX, int posY, int fontSize, Color color)
{
    this->posX = posX;
    this->posY = posY;
    this->fontSize = fontSize;
    this->text = text;
    this->color = color;
}

void RaylibText::setPosX(int posX)
{
    this->posX = posX;
}

void RaylibText::setPosY(int posY)
{
    this->posY = posY;
}

void RaylibText::setFontSize(int fontSize)
{
    this->fontSize = fontSize;
}

void RaylibText::setText(std::string text)
{
    this->text = text;
}

int RaylibText::getPosX() const
{
    return posX;
}

int RaylibText::getPosY() const
{
    return posY;
}

int RaylibText::getFontSize() const
{
    return fontSize;
}

std::string RaylibText::getText() const
{
    return text;
}

void RaylibText::DrawRlibText() const
{
    DrawText(text.c_str(), posX, posY, fontSize, BLACK);
}

