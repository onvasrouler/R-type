/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#pragma once

#include "ACharacter.hpp"

class Enemy : public ACharacter
{
public:
    Enemy(int x, int y, int l, int h, int type, int id, int hp, int level);
    ~Enemy();

    void move_entity();
};
