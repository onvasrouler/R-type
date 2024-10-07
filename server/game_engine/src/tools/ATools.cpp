/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ATools
*/

/**
 * @file ATools.cpp
 * @brief Implementation of the ATools class.
 */

#include "ATools.hpp"

/**
 * @brief Construct a new ATools object with a default value.
 * 
 * This constructor initializes the value to 0.
 */
ATools::ATools()
{
    this->_value = 0;
}

/**
 * @brief Construct a new ATools object with a specified value.
 * 
 * @param value The value to be set.
 * 
 * This constructor initializes the value to the specified value.
 */
ATools::ATools(const int value)
{
    this->_value = value;
}

/**
 * @brief Set the value.
 * 
 * @param value The new value to be set.
 * 
 * This method sets the value to the specified value.
 */
void ATools::set_value(const int value)
{
    this->_value = value;
}

/**
 * @brief Get the value.
 * 
 * @return int The current value.
 * 
 * This method returns the current value.
 */
int ATools::get_value()
{
    return this->_value;
}