/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

/**
 * @file Bullet.hpp
 * @brief Declaration of the Bullet class.
 */

#pragma once

#include "../AEntity.hpp"
#include "../../tools/src/Damage.hpp"

#define BULLET_SIZE 15 ///< The size of the bullet in pixels.
#define BULLET_MOVE_DISTANCE 2 ///< The distance in pixels to move the bullet in one step.

/**
 * @class Bullet
 * @brief Represents a bullet entity in the game.
 * 
 * The Bullet class inherits from AEntity and adds specific attributes and methods
 * related to bullets, such as damage and movement.
 */
class Bullet : virtual public AEntity
{
public:
    /**
     * @brief Construct a new Bullet object.
     * 
     * @param x The initial x-coordinate of the bullet.
     * @param y The initial y-coordinate of the bullet.
     */
    Bullet(const int x, const int y);

    /**
     * @brief Default destructor for Bullet.
     */
    ~Bullet() = default;

    /**
     * @brief Move the bullet by updating its x-coordinate.
     * 
     * The bullet moves by 2 units along the x-axis.
     */
    void move();

    /**
     * @brief Set the damage value of the bullet.
     * 
     * @param damage The new damage value to be set.
     */
    void set_damage(const int damage);

    /**
     * @brief Get the damage value of the bullet.
     * 
     * @return int The damage value of the bullet.
     */
    int get_damage(void);

private:
    Damage _damage; ///< The damage value of the bullet.
};