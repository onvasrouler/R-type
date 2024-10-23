/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Hp
*/

/**
 * @file Hp.hpp
 * @brief Declaration of the Hp class.
 */

#pragma once

#include "ATools.hpp"

/**
 * @class Hp
 * @brief Represents the health points (HP) for an entity.
 * 
 * The Hp class inherits from ATools and provides constructors to initialize the HP value.
 */
class Hp : public ATools
{
public:
    /**
     * @brief Construct a new Hp object with a default value.
     * 
     * This constructor initializes the HP value to a default value.
     */
    Hp() = default;

    /**
     * @brief Construct a new Hp object with a specified value.
     * 
     * @param value The HP value to be set.
     * 
     * This constructor initializes the HP value to the specified value.
     */
    Hp(const int value) : ATools(value) {}

    /**
     * @brief Default destructor for Hp.
     */
    ~Hp() = default;
};