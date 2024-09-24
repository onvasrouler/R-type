/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** button
*/

#include "button.hpp"

/**
 * @brief Constructs a Button object with specified text, font, window ratio, and alignment.
 * 
 * @param text The text to display on the button.
 * @param font The font to use for the button text.
 * @param windowRatio The ratio of the window size, used to calculate button size and position.
 * @param left An integer flag to determine the horizontal alignment of the button. 
 *             If non-zero, the button is aligned to the left; otherwise, it is aligned to the right.
 */
Button::Button(const std::string& text, sf::Font& font, sf::Vector2i windowRatio, int left)
{
    sf::Vector2f size = {windowRatio.x / 6.0f, windowRatio.y / 8.0f};
    sf::Vector2f position = {0, windowRatio.y - (windowRatio.y * 0.4f)};

    // used to place the button either at the right or at the left
    if (left)
        position.x = windowRatio.x / 1.5f;
    else
        position.x = windowRatio.x / 6.0f;
    // button rectangle related
    buttonShape.setSize(size);
    buttonShape.setPosition(position);
    buttonShape.setFillColor(sf::Color::Blue);
    buttonShape.setOutlineThickness(2);
    buttonShape.setOutlineColor(sf::Color::Black);
    // button's text related
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setPosition(
        position.x + (size.x - textBounds.width) / 2 - textBounds.left,
        position.y + (size.y - textBounds.height) / 2 - textBounds.top
    );
}

/**
 * @brief Draws the button on the given render window.
 * 
 * This function renders the button's shape and text onto the specified
 * SFML render window.
 * 
 * @param window Reference to the SFML render window where the button will be drawn.
 */
void Button::draw(sf::RenderWindow& window)
{
    window.draw(buttonShape);
    window.draw(buttonText);
}

/**
 * @brief Checks if the button is clicked based on the mouse position.
 * 
 * This function determines whether the button has been clicked by checking
 * if the given mouse position falls within the bounds of the button shape.
 * 
 * @param mousePos The position of the mouse cursor as a 2D vector.
 * @return true if the button is clicked (i.e., the mouse position is within the button's bounds), false otherwise.
 */
bool Button::isClicked(sf::Vector2i mousePos)
{
    return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
