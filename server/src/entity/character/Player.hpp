/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

#pragma once

#include "ACharacter.hpp"

class Player : public ACharacter
{
public:
    Player(int x, int y, int l, int h, int type, int id, int hp, int level);
    ~Player();

    void move_entity();
};
