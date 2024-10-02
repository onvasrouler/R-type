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
    Bullet(int x, int y, int l, int h, int type, int id, int damage);
    ~Bullet();

    void move_entity();

    void set_damage(int damage);
    int get_damage(void);
private:
    std::unique_ptr<Damage> _damage;
};
