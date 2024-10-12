/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

/**
 * @file Enemy.cpp
 * @brief Implementation of the Enemy class.
 */

#include "Enemy.hpp"
#include <iostream>

/**
 * @brief Construct a new Enemy object.
 * 
 * @param y The initial y-coordinate of the enemy.
 * 
 * This constructor initializes the enemy's position and dimensions.
 */
Enemy::Enemy(const int y) : ACharacter(uuid())
{
    int spawnY = y;
    if (spawnY - ENEMY_SIZE >= 1080)
        spawnY = 1080 - ENEMY_SIZE;
    this->_origin = Point(X_POSITION, spawnY);
    this->_dimension = Rect(ENEMY_SIZE, ENEMY_SIZE);
}

/**
 * @brief Move the enemy by updating its x-coordinate.
 * 
 * The enemy moves by a predefined distance along the x-axis.
 */
void Enemy::move()
{
    this->_origin.moveX(-ENEMY_MOVE_DISTANCE);
}