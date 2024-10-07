/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ATools
*/

/**
 * @file ATools.hpp
 * @brief Declaration of the ATools class.
 */

#pragma once

#include "ITools.hpp"

/**
 * @class ATools
 * @brief Abstract base class for tools with a value.
 * 
 * The ATools class provides methods to set and get the value of the tool.
 * It inherits from the ITools interface.
 */
class ATools : public ITools
{
public:
    /**
     * @brief Construct a new ATools object with a default value.
     * 
     * This constructor initializes the value to 0.
     */
    ATools();

    /**
     * @brief Construct a new ATools object with a specified value.
     * 
     * @param value The value to be set.
     * 
     * This constructor initializes the value to the specified value.
     */
    ATools(const int value);

    /**
     * @brief Default virtual destructor for ATools.
     */
    virtual ~ATools() = default;

    /**
     * @brief Set the value of the tool.
     * 
     * @param value The new value to be set.
     * 
     * This method sets the value to the specified value.
     */
    void set_value(const int value);

    /**
     * @brief Get the value of the tool.
     * 
     * @return int The current value of the tool.
     * 
     * This method returns the current value of the tool.
     */
    int get_value();

protected:
    int _value; ///< The value of the tool.
};