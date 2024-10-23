/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Level
*/

/**
 * @file Level.hpp
 * @brief Declaration of the Level class.
 */

#pragma once

#include "ATools.hpp"

/**
 * @class Level
 * @brief Represents the level for an entity.
 * 
 * The Level class inherits from ATools and provides constructors to initialize the level value.
 */
class Level : public ATools
{
public:
    /**
     * @brief Construct a new Level object with a default value.
     * 
     * This constructor initializes the level value to a default value.
     */
    Level() = default;

    /**
     * @brief Construct a new Level object with a specified value.
     * 
     * @param value The level value to be set.
     * 
     * This constructor initializes the level value to the specified value.
     */
    Level(const int value) : ATools(value) {}

    /**
     * @brief Default destructor for Level.
     */
    ~Level() = default;
};