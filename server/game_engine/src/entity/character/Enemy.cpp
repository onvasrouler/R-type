/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(const int y) : ACharacter()
{
    this->_origin = Point(25, y);
    this->_dimension = Rect(10, 10);
}

void Enemy::move()
{
    this->_origin.set_x(this->_origin.get_x() - 2);
}
