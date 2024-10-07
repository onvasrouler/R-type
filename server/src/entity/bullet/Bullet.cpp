/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(int x, int y) : AEntity()
{
    this->_origin = Point(x, y);
    this->_dimension = Rect(5, 5);
    this->_damage = Damage(1);
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
    this->_origin.set_x(this->_origin.get_x() + 2);
}

int Bullet::get_damage() const
{
    return (this->_damage.get_value());
}

void Bullet::set_damage(int damage)
{
    this->_damage.set_value(damage);
}
