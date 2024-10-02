/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(int x, int y, int l, int h, int type, int id, int damage) : AEntity(x, y, l, h, type, id)
{
    this->_damage = std::make_unique<Damage>(damage);
}

Bullet::~Bullet()
{

}

void Bullet::move_entity()
{
    this->_origin->set_x(this->_origin->get_x() + 2);
}

int Bullet::get_damage()
{
    return (this->_damage->get_value());
}

void Bullet::set_damage(int damage)
{
    this->_damage->set_value(damage);
}
