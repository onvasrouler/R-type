/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#pragma once

#include "AEntity.hpp"

class Enemy : virtual public AEntity
{
public:
    Enemy(int x, int y, int l, int h);
    ~Enemy();

    void move_entity();
};
