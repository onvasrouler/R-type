/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#include "fpsCounter.hpp"

FpsCounter::FpsCounter(const Vector2 pos, const int zindex, const int fontSize, const Color color)
{
   this-> _Position = pos;
   this->_Fps = 0;
   this->_FrameCount = 0;
   this->_ElapsedTime = 0;
   this->_FpsText = std::make_shared<RLText>(pos, Vector2{0, static_cast<float>(fontSize)}, "FPS: 0", zindex, color);
   this->_Active = true;
}

void FpsCounter::setFps(const float fps)
{
   this->_Fps = fps;
   this->_FpsText->setText("FPS: " + std::to_string(_Fps));
}

float FpsCounter::getFps() const
{
   return this->_Fps;
}

const std::shared_ptr<RLText>& FpsCounter::getFpsText() const
{
   return this->_FpsText;
}

void FpsCounter::drawFps()
{
   this->_FpsText->draw();
   this->update();
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
