/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** background
*/

#include "background.hpp"

Background::Background(const int width, const int height)
{ 
    _Width = width;
    _Height = height;
    _Count = 0;
}

void Background::draw()
{
    _Count -= 1;
    if (_Count <= -_BackgroundTextures.width) {
        _Count = 0;
    }
    DrawTexture(_BackgroundTextures, _Count, 0, WHITE);
    DrawTexture(_BackgroundTextures, _Count + _BackgroundTextures.width, 0, WHITE);
}

void Background::setWidth(const int width)
{
    _BackgroundTextures.width = width;
}

void Background::setHeight(const int height)
{
    _BackgroundTextures.height = height;
}

void Background::loadTextures(const std::string filename)
{
    if (_BackgroundTextures.id > 0)
        UnloadTexture(_BackgroundTextures);
    _BackgroundTextures = LoadTexture(filename.c_str());
    _BackgroundTextures.width = _Width;
    _BackgroundTextures.height = _Height;
}