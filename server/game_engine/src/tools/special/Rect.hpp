/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Rect
*/

/**
 * @file Rect.hpp
 * @brief Declaration of the Rect class.
 */

#pragma once

/**
 * @class Rect
 * @brief Represents a rectangle with length and height.
 * 
 * The Rect class provides methods to set and get the dimensions of the rectangle.
 */
class Rect
{
public:
    /**
     * @brief Construct a new Rect object with default dimensions (0, 0).
     * 
     * This constructor initializes the length and height to 0.
     */
    Rect();

    /**
     * @brief Construct a new Rect object with specified dimensions.
     * 
     * @param l The length of the rectangle.
     * @param h The height of the rectangle.
     * 
     * This constructor initializes the length and height to the specified values.
     */
    Rect(const int l, const int h);

    /**
     * @brief Default destructor for Rect.
     */
    ~Rect() = default;

    /**
     * @brief Set the length of the rectangle.
     * 
     * @param l The new length to be set.
     */
    void set_l(const int l);

    /**
     * @brief Set the height of the rectangle.
     * 
     * @param h The new height to be set.
     */
    void set_h(const int h);

    /**
     * @brief Get the length of the rectangle.
     * 
     * @return int The current length of the rectangle.
     */
    int get_l() const;

    /**
     * @brief Get the height of the rectangle.
     * 
     * @return int The current height of the rectangle.
     */
    int get_h() const;

private:
    int _h; ///< The height of the rectangle.
    int _l; ///< The length of the rectangle.
};