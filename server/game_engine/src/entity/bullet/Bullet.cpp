/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

/**
 * @file Bullet.cpp
 * @brief Implementation of the Bullet class.
 */

#include "Bullet.hpp"

/**
 * @brief Construct a new Bullet object.
 * 
 * @param x The initial x-coordinate of the bullet.
 * @param y The initial y-coordinate of the bullet.
 */
Bullet::Bullet(const int x, const int y) : AEntity()
{
    this->_origin = Point(x, y);
    this->_dimension = Rect(5, 5);
    this->_damage = Damage(1);
}

/**
 * @brief Move the bullet by updating its x-coordinate.
 * 
 * The bullet moves by 2 units along the x-axis.
 */
void Bullet::move()
{
    this->_origin.set_x(this->_origin.get_x() + 2);
}

/**
 * @brief Get the damage value of the bullet.
 * 
 * @return int The damage value of the bullet.
 */
int Bullet::get_damage()
{
    return this->_damage.get_value();
}

/**
 * @brief Set the damage value of the bullet.
 * 
 * @param damage The new damage value to be set.
 */
void Bullet::set_damage(const int damage)
{
    this->_damage.set_value(damage);
}