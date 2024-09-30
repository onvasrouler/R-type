/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

#pragma once

#include "AEntity.hpp"

class Player : virtual public AEntity
{
public:
    Player(int x, int y, int l, int h);
    ~Player();

    void move_entity();
};
