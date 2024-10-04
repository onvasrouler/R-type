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
    Enemy(int y);
    ~Enemy();

    void move();
};
