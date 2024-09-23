/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** progressBar
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @class ProgressBar
 * @brief A class to represent and manage a progress bar in a graphical window.
 * 
 * The ProgressBar class provides functionalities to set the size, window ratio,
 * and progress of a progress bar, as well as to draw it on a window.
 * 
 * @note This class requires the SFML library for handling fonts and text rendering.
 */
class ProgressBar {
public:
    /**
     * @brief Constructs a new ProgressBar object.
     */
    ProgressBar();

    /**
     * @brief Destroys the ProgressBar object.
     */
    ~ProgressBar();

    /**
     * @brief Sets the window ratio for the progress bar.
     * 
     * @param windowRatio A vector representing the window ratio.
     */
    void setWindowRatio(sf::Vector2i windowRatio);

    /**
     * @brief Sets the progress of the progress bar
     *
     *  @param progress A float value representing the progress (0.0 to 1.0).
     */
    void setProgress(float progress);

    /**
     * @brief Draws the progress bar on the given window.
     * 
     * @param window A reference to the RenderWindow where the progress bar will be drawn.
     */
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape outline; ///< The outline shape of the progress bar.   
    sf::Vector2i _WindowRatio; ///< The window ratio for the progress bar.
    sf::RectangleShape bar; ///< The inner bar representing the progress.
};
