/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

#pragma once

#include <ctime>

#include "ACharacter.hpp"

enum Direction {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player : public ACharacter
{
public:
    Player(const int y);
    ~Player() = default;

    void move();
    enum Direction get_dir();
    void set_dir(enum Direction dir);
    bool get_has_shot();
    void set_has_shot(bool has_shot);
    std::clock_t get_cl();
    void restart_cl();

private:
    bool _has_shot;
    enum Direction _dir;
    std::clock_t _cl;
};
