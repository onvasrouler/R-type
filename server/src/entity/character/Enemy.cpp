/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(int y) : ACharacter()
{
    this->_origin = std::make_shared<Point>(25, y);
    this->_dimension = std::make_shared<Rect>(10, 10);
}

Enemy::~Enemy()
{

}

void Enemy::move()
{
    this->_origin->set_x(this->_origin->get_x() - 2);
}
