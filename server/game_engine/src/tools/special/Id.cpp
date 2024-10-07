/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Id
*/

/**
 * @file Id.cpp
 * @brief Implementation of the Id class.
 */

#include <Id.hpp>

/**
 * @brief Construct a new Id object.
 * 
 * This constructor initializes the ID value to the current value of ID_nb
 * and then increments ID_nb for the next ID.
 */
Id::Id()
{
    this->_value = uuid().toString();
}

/**
 * @brief Get the value of the ID.
 * 
 * @return int The current value of the ID.
 * 
 * This method returns the value of the ID stored in the _value attribute.
 */
std::string Id::get_value() const
{
    return this->_value;
}