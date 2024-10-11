/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#include "fpsCounter.hpp"

FpsCounter::FpsCounter(Vector2 pos, int fontSize, Color color)
{
    this-> _Position = pos;
    this->_Fps = 0;
    this->_FrameCount = 0;
    this->_ElapsedTime = 0;
    this->_FpsText = std::make_unique<RaylibText>("FPS: 0", pos, fontSize, color);
    this->_Active = true;
}

void FpsCounter::setPosX(int posX)
{
    this->_FpsText->setPosX(posX);
}

void FpsCounter::setPosY(int posY)
{
    this->_FpsText->setPosY(posY);
}

void FpsCounter::setPos(Vector2 pos)
{
    this->_FpsText->setPos(pos);
}

void FpsCounter::setFontSize(int fontSize)
{
    this->_FpsText->setFontSize(fontSize);
}

void FpsCounter::setFps(float fps)
{
    this->_Fps = fps;
    this->_FpsText->setText("FPS: " + std::to_string(_Fps));
}

void FpsCounter::setFpsText(std::unique_ptr<RaylibText> fpsText)
{
    this->_FpsText = std::move(fpsText);
}

int FpsCounter::getPosX() const
{
    return this->_FpsText->getPosX();
}

int FpsCounter::getPosY() const
{
    return this->_FpsText->getPosY();
}

Vector2 FpsCounter::getPos() const
{
    return this->_FpsText->getPos();
}

int FpsCounter::getFontSize() const
{
    return this->_FpsText->getFontSize();
}

float FpsCounter::getFps() const
{
    return this->_Fps;
}

const std::unique_ptr<RaylibText>& FpsCounter::getFpsText() const
{
    return this->_FpsText;
}

void FpsCounter::draw() const
{
    if (this->_Active)
        this->_FpsText->DrawRlibText();
}

void FpsCounter::reset()
{
    this->_Fps = 0;
    this->_FrameCount = 0;
    this->_ElapsedTime = 0;
}

void FpsCounter::update()
{
    int roundedFps;

    this->_FrameCount++;
    this->_ElapsedTime += GetFrameTime();
    if (_ElapsedTime >= 1) {
        this->_Fps = _FrameCount;
        this->_FrameCount = 0;
        this->_ElapsedTime = 0;
        roundedFps = static_cast<int>(_Fps);
        this->_FpsText->setText("FPS: " + std::to_string(roundedFps));
    }
}

void FpsCounter::setActive(bool active)
{
    this->_Active = active;
}

void FpsCounter::toggleActive()
{
    this->_Active = !_Active;
}

bool FpsCounter::isActive() const
{
    return this->_Active;
}
