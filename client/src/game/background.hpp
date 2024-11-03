/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** background
*/

#pragma once
#include <vector>
#include <raylib.h>
#include <string>

class Background {
public:
    Background(const int width = 1920, const int height = 1080);
    ~Background() = default;

    void loadTextures(const std::string filename = "./assets/background.png");

    void draw();

    void setWidth(const int width);
    void setHeight(const int height);
private:
    Texture2D _BackgroundTextures;
    int _Width;
    int _Height;
    int _Count;
};