/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#pragma once

#include <memory>
#include "../raylibText/raylibText.hpp"

class FpsCounter {
public:
    FpsCounter() = default;
    FpsCounter(int posX = 0, int posY = 0, int fontSize = 10, Color color = BLACK);
    ~FpsCounter() = default;

    void setPosX(int posX);
    void setPosY(int posY);
    void setFontSize(int fontSize);
    void setFps(float fps);
    void setFpsText(std::unique_ptr<RaylibText> fpsText);

    int getPosX() const;
    int getPosY() const;
    int getFontSize() const;
    float getFps() const;
    const std::unique_ptr<RaylibText>& getFpsText() const;

    void draw() const;

    void reset();
    void update();

private:
    float _fps;
    float _frameCount;
    float _elapsedTime;

    std::unique_ptr<RaylibText> _fpsText;
    
};