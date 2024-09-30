/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bullet
*/

#pragma once

#include "AEntity.hpp"

class Bullet : virtual public AEntity
{
public:
    Bullet(int x, int y, int l, int h);
    ~Bullet();

    void move_entity();
};
