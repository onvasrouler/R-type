/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Id
*/

/**
 * @file Id.hpp
 * @brief Declaration of the Id class.
 */

#pragma once

#include <string>
#include "ATools.hpp"
#include "../../../../lib/UUID.hpp"

/**
 * @class Id
 * @brief Represents a unique identifier for entities.
 * 
 * The Id class generates a unique identifier for each instance created.
 * It provides a method to retrieve the value of the identifier.
 */
class Id
{
public:
    /**
     * @brief Construct a new Id object.
     * 
     * This constructor initializes the ID value to a unique number.
     */
    Id();

    /**
     * @brief Default destructor for Id.
     */
    ~Id() = default;

    /**
     * @brief Get the value of the ID.
     * 
     * @return int The current value of the ID.
     * 
     * This method returns the value of the ID stored in the _value attribute.
     */
    std::string get_value() const;

private:
    std::string _value; ///< The value of the ID.
};