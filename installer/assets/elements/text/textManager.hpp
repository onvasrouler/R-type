/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** textManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>
#include <iostream>

/**
 * @class TextManager
 * @brief Manages text rendering, including loading fonts and setting window ratios.
 *
 * The TextManager class provides functionalities to load fonts, set window ratios,
 * and create text objects for rendering in a window.
 *
 * @note This class requires the SFML library for handling fonts and text rendering.
 *
 * @var sf::Font TextManager::font
 * The font used for rendering text.
 *
 * @var sf::Vector2i TextManager::_WindowsSize
 * The size of the window, used for calculating window ratios.
 *
 * @var bool TextManager::_FontLoaded
 * Indicates whether a font has been successfully loaded.
 *
 * @var bool TextManager::_WindowSizeLoaded
 * Indicates whether the window size has been successfully set.
 */
class TextManager
{
public:
    /**
     * @brief Constructs a new TextManager object.
     */
    TextManager();

    /**
     * @brief Loads a font from the specified file path.
     *
     * @param path The file path to the font file.
     */
    void loadFont(std::string path);

    /**
     * @brief Sets the window ratio based on the given window size.
     *
     * @param windowsSize The size of the window.
     */
    void setWindowRatio(sf::Vector2i windowsSize);

    /**
     * @brief Retrieves the default font used by the application.
     * 
     * This function returns an sf::Font object that represents the default font.
     * It can be used for rendering text elements consistently across the application.
     * 
     * @return sf::Font The default font used by the application.
     */
    sf::Font &getDefaultFont();

    /**
     * @brief Creates a text object with the specified string and window size.
     *
     * @param text The string to be displayed.
     * @param windowsSize The size of the window (optional).
     * @return sf::Text The created text object.
     */
    sf::Text createText(const std::string &text, sf::Vector2i windowsSize = {0, 0});

private:
    sf::Font font;
    sf::Vector2i _WindowsSize;

    bool _FontLoaded;
    bool _WindowSizeLoaded;
};
