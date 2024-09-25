/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#pragma once

#include <memory>
#include "../elements/raylibText/raylibText.hpp"

class FpsCounter {
public:
    FpsCounter() = default;
    FpsCounter(Vector2 pos = {0, 0}, int fontSize = 10, Color color = BLACK);
    ~FpsCounter() = default;

    void setPosX(int posX);
    void setPosY(int posY);
    void setPos(Vector2 pos);
    void setFontSize(int fontSize);
    void setFps(float fps);
    void setFpsText(std::unique_ptr<RaylibText> fpsText);

    int getPosX() const;
    int getPosY() const;
    Vector2 getPos() const;
    int getFontSize() const;
    float getFps() const;
    const std::unique_ptr<RaylibText>& getFpsText() const;

    void draw() const;

    void reset();
    void update();

private:
    Vector2 _Position;

    float _fps;
    float _frameCount;
    float _elapsedTime;

    std::unique_ptr<RaylibText> _fpsText;
    
};