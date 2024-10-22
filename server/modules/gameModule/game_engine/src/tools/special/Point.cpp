/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Point
*/

/**
 * @file Point.cpp
 * @brief Implementation of the Point class.
 */

#include "Point.hpp"

/**
 * @brief Construct a new Point object with default coordinates (0, 0).
 * 
 * This constructor initializes the x and y coordinates to 0.
 */
Point::Point()
{
    this->_x = 0;
    this->_y = 0;
}

/**
 * @brief Construct a new Point object with specified coordinates.
 * 
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * 
 * This constructor initializes the x and y coordinates to the specified values.
 */
Point::Point(const int x, const int y)
{
    this->_x = x;
    this->_y = y;
}

/**
 * @brief Set the x-coordinate of the point.
 * 
 * @param x The new x-coordinate to be set.
 */
void Point::set_x(const int x)
{
    this->_x = x;
}

/**
 * @brief Set the y-coordinate of the point.
 * 
 * @param y The new y-coordinate to be set.
 */
void Point::set_y(const int y)
{
    this->_y = y;
}

/**
 * @brief Get the x-coordinate of the point.
 * 
 * @return int The current x-coordinate of the point.
 */
int Point::get_x() const
{
    return this->_x;
}

/**
 * @brief Get the y-coordinate of the point.
 * 
 * @return int The current y-coordinate of the point.
 */
int Point::get_y() const
{
    return this->_y;
}

/**
 * @brief Move the point along the x-axis by a specified distance.
 * 
 * @param distance The distance to move the point along the x-axis.
 */
void Point::moveX(const int distance) {
    _x += distance;
}

/**
 * @brief Move the point along the y-axis by a specified distance.
 * 
 * @param distance The distance to move the point along the y-axis.
 */
void Point::moveY(const int distance) {
    _y += distance;
}