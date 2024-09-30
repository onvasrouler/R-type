/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int l, int h) : AEntity(x, y, l, h)
{

}

Enemy::~Enemy()
{

}

void Enemy::move_entity()
{
    this->_origin->set_x(this->_origin->get_x() - 2);
}
