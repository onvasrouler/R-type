/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Point
*/

/**
 * @file Point.hpp
 * @brief Declaration of the Point class.
 */

#pragma once

/**
 * @class Point
 * @brief Represents a point in 2D space.
 * 
 * The Point class provides methods to set and get the coordinates of the point,
 * as well as to move the point along the x and y axes.
 */
class Point
{
public:
    /**
     * @brief Construct a new Point object with default coordinates (0, 0).
     * 
     * This constructor initializes the x and y coordinates to 0.
     */
    Point();

    /**
     * @brief Construct a new Point object with specified coordinates.
     * 
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * 
     * This constructor initializes the x and y coordinates to the specified values.
     */
    Point(const int x, const int y);

    /**
     * @brief Default destructor for Point.
     */
    ~Point() = default;

    /**
     * @brief Set the x-coordinate of the point.
     * 
     * @param x The new x-coordinate to be set.
     */
    void set_x(const int x);

    /**
     * @brief Set the y-coordinate of the point.
     * 
     * @param y The new y-coordinate to be set.
     */
    void set_y(const int y);

    /**
     * @brief Get the x-coordinate of the point.
     * 
     * @return int The current x-coordinate of the point.
     */
    int get_x();

    /**
     * @brief Get the y-coordinate of the point.
     * 
     * @return int The current y-coordinate of the point.
     */
    int get_y();

    /**
     * @brief Move the point along the x-axis by a specified distance.
     * 
     * @param distance The distance to move the point along the x-axis.
     */
    void moveX(const int distance);

    /**
     * @brief Move the point along the y-axis by a specified distance.
     * 
     * @param distance The distance to move the point along the y-axis.
     */
    void moveY(const int distance);

private:
    int _x; ///< The x-coordinate of the point.
    int _y; ///< The y-coordinate of the point.
};