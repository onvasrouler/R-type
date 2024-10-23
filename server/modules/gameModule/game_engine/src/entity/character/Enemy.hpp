/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

/**
 * @file Enemy.hpp
 * @brief Declaration of the Enemy class.
 */

#pragma once

#include "../ACharacter.hpp"

#define ENEMY_MOVE_DISTANCE 3 ///< The distance in pixels an enemy moves per update.
#define ENEMY_SIZE 70 ///< The size of the enemy in pixels.
#define X_POSITION 1900 ///< The initial x-coordinate of the enemy in pixels.

/**
 * @class Enemy
 * @brief Represents an enemy character in the game.
 * 
 * The Enemy class inherits from ACharacter and adds specific attributes and methods
 * related to enemies, such as movement.
 */
class Enemy : public ACharacter
{
public:
    /**
     * @brief Construct a new Enemy object.
     * 
     * @param y The initial y-coordinate of the enemy.
     * 
     * This constructor initializes the enemy's position and dimensions.
     */
    Enemy(const int y);

    /**
     * @brief Default destructor for Enemy.
     */
    ~Enemy() = default;

    /**
     * @brief Move the enemy by updating its x-coordinate.
     * 
     * The enemy moves by a predefined distance along the x-axis.
     */
    void move();
};