/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(int x, int y, int l, int h) : AEntity(x, y, l, h)
{

}

Bullet::~Bullet()
{

}

void Bullet::move_entity()
{
    this->_origin->set_x(this->_origin->get_x() + 2);
}
