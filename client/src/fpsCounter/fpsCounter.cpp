/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#include "fpsCounter.hpp"

FpsCounter::FpsCounter(const Vector2 pos, const int fontSize, const Color color)
{
    this-> _Position = pos;
    this->_Fps = 0;
    this->_FrameCount = 0;
    this->_ElapsedTime = 0;
    this->_FpsText = std::make_unique<RaylibText>("FPS: 0", pos, fontSize, color, "FpsTextCounter", true);
    this->_Active = true;
}

void FpsCounter::setPosX(const int posX) const
{
    this->_FpsText->setPosX(posX);
}

void FpsCounter::setPosY(const int posY) const
{
    this->_FpsText->setPosY(posY);
}

void FpsCounter::setPos(const Vector2 pos) const
{
    this->_FpsText->setPos(pos);
}

void FpsCounter::setFontSize(const int fontSize) const
{
    this->_FpsText->setFontSize(fontSize);
}

void FpsCounter::setFps(const float fps)
{
    this->_Fps = fps;
    this->_FpsText->setText("FPS: " + std::to_string(_Fps));
}

void FpsCounter::setFpsText(std::unique_ptr<RaylibText> fpsText)
{
    this->_FpsText = std::move(fpsText);
}

void FpsCounter::setColor(const Color color) const
{
    this->_FpsText->setColor(color);
}

void FpsCounter::setColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) const
{
    this->_FpsText->setColor(Color{r, g, b, a});
}

const int FpsCounter::getPosX() const
{
    return this->_FpsText->getPosX();
}

const int FpsCounter::getPosY() const
{
    return this->_FpsText->getPosY();
}

const Vector2 FpsCounter::getPos() const
{
    return this->_FpsText->getPos();
}

const int FpsCounter::getFontSize() const
{
    return this->_FpsText->getFontSize();
}

const float FpsCounter::getFps() const
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

void FpsCounter::setActive(const bool active)
{
    this->_Active = active;
}

void FpsCounter::toggleActive()
{
    this->_Active = !_Active;
}

const bool FpsCounter::isActive() const
{
    return this->_Active;
}
