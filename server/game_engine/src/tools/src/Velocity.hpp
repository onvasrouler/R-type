/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Velocity
*/

/**
 * @file Velocity.hpp
 * @brief Declaration of the Velocity class.
 */

#pragma once

#include "ATools.hpp"

/**
 * @class Velocity
 * @brief Represents the velocity for an entity.
 * 
 * The Velocity class inherits from ATools and provides constructors to initialize the velocity value.
 */
class Velocity : public ATools
{
public:
    /**
     * @brief Construct a new Velocity object with a default value.
     * 
     * This constructor initializes the velocity value to a default value.
     */
    Velocity() = default;

    /**
     * @brief Construct a new Velocity object with a specified value.
     * 
     * @param value The velocity value to be set.
     * 
     * This constructor initializes the velocity value to the specified value.
     */
    Velocity(const int value) : ATools(value) {}

    /**
     * @brief Default destructor for Velocity.
     */
    ~Velocity() = default;
};