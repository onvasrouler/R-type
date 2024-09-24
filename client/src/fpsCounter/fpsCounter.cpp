/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#include "fpsCounter.hpp"

FpsCounter::FpsCounter(int posX, int posY, int fontSize, Color color)
{
    _fps = 0;
    _frameCount = 0;
    _elapsedTime = 0;
    _fpsText = std::make_unique<RaylibText>("FPS: 0", posX, posY, fontSize, color);
}

void FpsCounter::setPosX(int posX)
{
    _fpsText->setPosX(posX);
}

void FpsCounter::setPosY(int posY)
{
    _fpsText->setPosY(posY);
}

void FpsCounter::setFontSize(int fontSize)
{
    _fpsText->setFontSize(fontSize);
}

void FpsCounter::setFps(float fps)
{
    _fps = fps;
    _fpsText->setText("FPS: " + std::to_string(_fps));
}

void FpsCounter::setFpsText(std::unique_ptr<RaylibText> fpsText)
{
    _fpsText = std::move(fpsText);
}

int FpsCounter::getPosX() const
{
    return _fpsText->getPosX();
}

int FpsCounter::getPosY() const
{
    return _fpsText->getPosY();
}

int FpsCounter::getFontSize() const
{
    return _fpsText->getFontSize();
}

float FpsCounter::getFps() const
{
    return _fps;
}

const std::unique_ptr<RaylibText>& FpsCounter::getFpsText() const
{
    return _fpsText;
}

void FpsCounter::draw() const
{
    _fpsText->DrawRlibText();
}

void FpsCounter::reset()
{
    _fps = 0;
    _frameCount = 0;
    _elapsedTime = 0;
}

void FpsCounter::update()
{
    int roundedFps;

    _frameCount++;
    _elapsedTime += GetFrameTime();
    if (_elapsedTime >= 1) {
        _fps = _frameCount;
        _frameCount = 0;
        _elapsedTime = 0;
        roundedFps = static_cast<int>(_fps);
        _fpsText->setText("FPS: " + std::to_string(roundedFps));
    }
}
