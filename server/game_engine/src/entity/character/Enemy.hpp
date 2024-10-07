/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Enemy
*/

#pragma once

#include "ACharacter.hpp"

#define ENEMY_MOVE_DISTANCE -2

class Enemy : public ACharacter
{
public:
    Enemy(const int y);
    ~Enemy() = default;

    void move();
};
