/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int l, int h, int type, int id, int hp, int level) : ACharacter(x, y, l, h, type, id, hp, level)
{

}

Enemy::~Enemy()
{

}

void Enemy::move_entity()
{
    this->_origin->set_x(this->_origin->get_x() - 2);
}
