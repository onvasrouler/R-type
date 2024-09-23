/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** button
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @class Button
 * @brief A class representing a clickable button in a graphical user interface.
 *
 * The Button class encapsulates the properties and behaviors of a button element,
 * including its text, font, and position within a window. It provides methods to
 * draw the button and check if it has been clicked.
 */
class Button
{
public:
    /**
     * @brief Default constructor for the Button class.
     *
     * Initializes a Button object with default properties.
     */
    Button();

    /**
     * @brief Parameterized constructor for the Button class.
     *
     * @param text The text to be displayed on the button.
     * @param font The font used for the button text.
     * @param windowRatio The ratio of the button's position relative to the window size.
     * @param left Optional parameter to specify the button's alignment (default is 1).
     *
     * Initializes a Button object with specified text, font, and position.
     */
    Button(const std::string &text, sf::Font &font, sf::Vector2i windowRatio, int left = 1);

    /**
     * @brief Draws the button on the specified render window.
     *
     * @param window The render window where the button will be drawn.
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Checks if the button has been clicked based on the mouse position.
     *
     * @param mousePos The current position of the mouse cursor.
     * @return True if the button is clicked, false otherwise.
     */
    bool isClicked(sf::Vector2i mousePos);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
};
