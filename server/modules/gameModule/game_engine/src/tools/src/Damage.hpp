/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Damage
*/

/**
 * @file Damage.hpp
 * @brief Declaration of the Damage class.
 */

#pragma once

#include "ATools.hpp"

/**
 * @class Damage
 * @brief Represents the damage value for an entity.
 * 
 * The Damage class inherits from ATools and provides constructors to initialize the damage value.
 */
class Damage : public ATools
{
public:
    /**
     * @brief Construct a new Damage object with a default value.
     * 
     * This constructor initializes the damage value to a default value.
     */
    Damage() = default;

    /**
     * @brief Construct a new Damage object with a specified value.
     * 
     * @param value The damage value to be set.
     * 
     * This constructor initializes the damage value to the specified value.
     */
    Damage(const int value) : ATools(value) {}

    /**
     * @brief Default destructor for Damage.
     */
    ~Damage() = default;
};