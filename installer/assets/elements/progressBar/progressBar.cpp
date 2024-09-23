/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** progressBar
*/

#include "progressBar.hpp"

/**
 * @brief Default constructor for the ProgressBar class.
 * 
 * Initializes a new instance of the ProgressBar class with default values.
 */
ProgressBar::ProgressBar()
{
}

/**
 * @brief Destructor for the ProgressBar class.
 *
 * This destructor is responsible for cleaning up any resources
 * that the ProgressBar object may have acquired during its lifetime.
 */
ProgressBar::~ProgressBar()
{
}

/**
 * @brief Sets the position of the progress bar and its outline based on the window ratio.
 * 
 * This function calculates the position of the progress bar and its outline
 * such that it is centered horizontally and positioned at half the height of the window.
 * 
 * @param windowRatio A vector representing the width and height of the window.
 */
void ProgressBar::setWindowRatio(sf::Vector2i windowRatio)
{
    sf::Vector2f _ProgressBarSize = {windowRatio.x / 1.5f, windowRatio.y / 7.0f };
    float posX = (windowRatio.x / 2.0f) - (_ProgressBarSize.x / 2);
    float posY = windowRatio.y - (windowRatio.y * 0.5f);

    outline = sf::RectangleShape(sf::Vector2f(_ProgressBarSize.x, _ProgressBarSize.y));
    bar = sf::RectangleShape(sf::Vector2f(0, _ProgressBarSize.y));
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineThickness(2);
    outline.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Green);
    bar.setPosition(sf::Vector2f(posX, posY));
    outline.setPosition(sf::Vector2f(posX, posY));
}

/**
 * @brief Sets the progress of the progress bar.
 * 
 * This function updates the size of the progress bar based on the given progress value.
 * The width of the progress bar is calculated as a proportion of the outline's width.
 * 
 * @param progress A float value representing the progress, where 0.0 means no progress and 1.0 means full progress.
 */
void ProgressBar::setProgress(float progress)
{
    bar.setSize(sf::Vector2f(outline.getSize().x * progress, outline.getSize().y));
}

/**
 * @brief Draws the progress bar on the given render window.
 * 
 * This function renders the outline and the bar of the progress bar
 * onto the specified SFML render window.
 * 
 * @param window Reference to the SFML render window where the progress bar will be drawn.
 */
void ProgressBar::draw(sf::RenderWindow& window)
{
    window.draw(outline);
    window.draw(bar);
}
