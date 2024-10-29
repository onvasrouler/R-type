/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** fpsCounter
*/

#pragma once

#include <memory>
#include "../elements/guiElements/guiElem/Elem.hpp"

/**
 * @class FpsCounter
 * @brief A class to manage and display frames per second (FPS) in a graphical application.
 * 
 * The FpsCounter class provides functionality to calculate, update, and display the FPS
 * in a graphical application. It uses a position, z-index, font size, and color to render
 * the FPS text on the screen.
 * 
 * @param pos The position where the FPS counter will be displayed. Default is {0, 0}.
 * @param zindex The z-index for rendering order. Default is 0.
 * @param fontSize The font size of the FPS text. Default is 10.
 * @param color The color of the FPS text. Default is BLACK.
 */
class FpsCounter {
public:
    /**
     * @brief Constructs a new FpsCounter object.
     * 
     * @param pos The position where the FPS counter will be displayed. Default is {0, 0}.
     * @param zindex The z-index for rendering order. Default is 0.
     * @param fontSize The font size of the FPS text. Default is 10.
     * @param color The color of the FPS text. Default is BLACK.
     */
    FpsCounter(const Vector2 pos = defaultPos, const int zindex = defaultZIndex, const int fontSize = 10, const Color color = BLACK);

    /**
     * @brief Sets the current FPS value.
     * 
     * @param fps The current frames per second.
     */
    void setFps(const float fps);

    /**
     * @brief Gets the current FPS value.
     * 
     * @return The current frames per second.
     */
    float getFps() const;

    /**
     * @brief Gets the shared pointer to the RLText object representing the FPS text.
     * 
     * @return A shared pointer to the RLText object.
     */
    const std::shared_ptr<RLText>& getFpsText() const;

    /**
     * @brief Draws the FPS counter on the screen.
     */
    void drawFps();

    /**
     * @brief Resets the FPS counter.
     */
    void reset();

    /**
     * @brief Updates the FPS counter.
     */
    void update();

private:
    Vector2 _Position; ///< The position of the FPS counter.
    float _Fps; ///< The current frames per second.
    float _FrameCount; ///< The number of frames counted.
    float _ElapsedTime; ///< The elapsed time since the last FPS calculation.
    bool _Active; ///< Whether the FPS counter is active.
    std::shared_ptr<RLText> _FpsText; ///< The text object displaying the FPS.
};
