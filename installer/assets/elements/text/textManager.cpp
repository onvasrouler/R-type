/**
 * @file textManager.cpp
 * @brief Implementation of the TextManager class for managing text elements in the R-type project.
 * 
 * This file contains the implementation of the TextManager class, which is responsible for
 * loading fonts, setting window ratios, and creating text objects with specified properties.
 * 
 * @details The TextManager class provides functionalities to:
 * - Load a font from a specified file path.
 * - Set the window size ratio for text positioning and sizing.
 * - Create and configure an sf::Text object with a given string and window size.
 * 
 * The class ensures that the font is loaded before creating text objects and uses the stored
 * window size if it has been set previously.
 * 
 * @note This file is part of the R-type project developed by EPITECH in 2024.
 * 
 * @author ciremiardk
 * @date 2024
 */
/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** textManager
*/

#include "textManager.hpp"

/**
 * @brief Constructs a new TextManager object.
 * 
 * Initializes the TextManager with the _FontLoaded flag set to false.
 */
TextManager::TextManager() :
    _FontLoaded(false),
    _WindowSizeLoaded(false)
{   
}

/**
 * @brief Loads a font from the specified file path.
 * 
 * This function attempts to load a font from the given file path. If the font
 * cannot be loaded, it throws a runtime error.
 * 
 * @param path The file path to the font to be loaded.
 * @throws std::runtime_error If the font cannot be loaded from the specified path.
 */
void TextManager::loadFont(std::string path)
{
    if (!font.loadFromFile(path)) {
        throw std::runtime_error("Could not load font");
    }
    _FontLoaded = true;
}

/**
 * @brief Retrieves the default font used by the TextManager.
 * 
 * This function returns a reference to the default sf::Font object
 * managed by the TextManager. The font can be used for rendering text
 * within the application.
 * 
 * @return sf::Font& Reference to the default font.
 */
sf::Font &TextManager::getDefaultFont()
{
    return font;
}

/**
 * @brief Sets the window ratio for the TextManager.
 * 
 * This function updates the internal window size and marks the window size as loaded.
 * 
 * @param windowsSize A sf::Vector2i representing the size of the window.
 */
void TextManager::setWindowRatio(sf::Vector2i windowsSize)
{
    _WindowsSize = windowsSize;
    _WindowSizeLoaded = true;
}

/**
 * @brief Creates an sf::Text object with the specified text and window size.
 * 
 * This function initializes an sf::Text object with the provided text string.
 * It sets the font, character size, fill color, and position of the text based
 * on the given window size. If the font is not loaded, it loads the font from
 * a specified file. If the window size is already loaded, it uses the stored
 * window size instead of the provided one.
 * 
 * @param text The string to be displayed as text.
 * @param windowsSize The size of the window, used to calculate character size and position.
 * @return sf::Text The configured sf::Text object.
 */
sf::Text TextManager::createText(const std::string& text, sf::Vector2i windowsSize)
{
    if (!_FontLoaded)
        loadFont("assets/font/arial/arial.ttf");
    if (_WindowSizeLoaded)
        windowsSize = _WindowsSize;

    int charsize = windowsSize.x / 30;
    float posX = (windowsSize.x / 2.0f) - ((charsize * text.length()) / 4.5);
    float posY = windowsSize.y - (windowsSize.y * 0.8f);
    sf::Text newText;

    newText.setFont(font);
    newText.setString(text);
    newText.setCharacterSize(charsize);
    newText.setFillColor(sf::Color::Black);
    newText.setPosition(sf::Vector2f(posX, posY));
    return newText;
}
