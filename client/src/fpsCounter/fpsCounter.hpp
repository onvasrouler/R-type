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
    FpsCounter(const Vector2 pos = {0, 0}, const int fontSize = 10, const Color color = BLACK);
    ~FpsCounter() = default;

    void setPosX(const int posX) const;
    void setPosY(const int posY) const ;
    void setPos(const Vector2 pos) const ;
    void setFontSize(const int fontSize) const ;
    void setFps(const float fps);
    void setFpsText(const std::unique_ptr<RaylibText> fpsText);
    void setColor(const Color color) const;
    void setColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) const;

    int getPosX() const;
    int getPosY() const;
    Vector2 getPos() const;
    int getFontSize() const;
    float getFps() const;
    const std::unique_ptr<RaylibText>& getFpsText() const;
    Color getColor() const;

    void draw() const;

    void reset();
    void update();

    void setActive(const bool active);
    void toggleActive();

    bool isActive() const;

private:
    Vector2 _Position;

    float _Fps;
    float _FrameCount;
    float _ElapsedTime;
    bool _Active;

    std::unique_ptr<RaylibText> _FpsText;
};
