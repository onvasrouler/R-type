/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

#pragma once

#include "AEntity.hpp"
#include "Damage.hpp"

class Bullet : virtual public AEntity
{
public:
    Bullet(int x, int y);
    ~Bullet();

    void move();

    void set_damage(int damage);
    int get_damage(void) const;
private:
    std::shared_ptr<Damage> _damage;
};
