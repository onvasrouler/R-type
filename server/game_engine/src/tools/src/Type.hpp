/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Type
*/

/**
 * @file Type.hpp
 * @brief Declaration of the Type class.
 */

#pragma once

#include "ATools.hpp"

/**
 * @class Type
 * @brief Represents the type for an entity.
 * 
 * The Type class inherits from ATools and provides constructors to initialize the type value.
 */
class Type : public ATools
{
public:
    /**
     * @brief Construct a new Type object with a default value.
     * 
     * This constructor initializes the type value to a default value.
     */
    Type() = default;

    /**
     * @brief Construct a new Type object with a specified value.
     * 
     * @param value The type value to be set.
     * 
     * This constructor initializes the type value to the specified value.
     */
    Type(const int value) : ATools(value) {}

    /**
     * @brief Default destructor for Type.
     */
    ~Type() = default;
};