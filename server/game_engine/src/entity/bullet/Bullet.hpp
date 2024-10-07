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
    ~Bullet() = default;

    void move();

    void set_damage(const int damage);
    int get_damage(void);
private:
    Damage _damage;
};
