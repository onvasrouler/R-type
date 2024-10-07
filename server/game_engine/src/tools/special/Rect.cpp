/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Rect
*/

/**
 * @file Rect.cpp
 * @brief Implementation of the Rect class.
 */

#include "Rect.hpp"

/**
 * @brief Construct a new Rect object with default dimensions (0, 0).
 * 
 * This constructor initializes the length and height to 0.
 */
Rect::Rect()
{
    this->_l = 0;
    this->_h = 0;
}

/**
 * @brief Construct a new Rect object with specified dimensions.
 * 
 * @param l The length of the rectangle.
 * @param h The height of the rectangle.
 * 
 * This constructor initializes the length and height to the specified values.
 */
Rect::Rect(const int l, const int h)
{
    this->_l = l;
    this->_h = h;
}

/**
 * @brief Set the length of the rectangle.
 * 
 * @param l The new length to be set.
 */
void Rect::set_l(const int l)
{
    this->_l = l;
}

/**
 * @brief Set the height of the rectangle.
 * 
 * @param h The new height to be set.
 */
void Rect::set_h(const int h)
{
    this->_h = h;
}

/**
 * @brief Get the length of the rectangle.
 * 
 * @return int The current length of the rectangle.
 */
int Rect::get_l()
{
    return this->_l;
}

/**
 * @brief Get the height of the rectangle.
 * 
 * @return int The current height of the rectangle.
 */
int Rect::get_h()
{
    return this->_h;
}