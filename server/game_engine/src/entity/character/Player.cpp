/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

#include "Player.hpp"

Player::Player (const int y) : ACharacter()
{
    this->_origin = Point(10, y);
    this->_dimension = Rect(10, 10);
    this->_has_shot = false;
    this->_dir = NONE;
    this->_cl = clock();
}

void Player::move()
{
    if (this->_dir == UP) {
        this->set_y(this->get_y() - 1);
    }
    if (this->_dir == DOWN) {
        this->set_y(this->get_y() + 1);
    }
    if (this->_dir == RIGHT) {
        this->set_x(this->get_x() + 1);
    }
    if (this->_dir == LEFT) {
        this->set_x(this->get_x() - 1);
    }
}

bool Player::get_has_shot()
{
    return this->_has_shot;
}

void Player::set_has_shot(const bool has_shot)
{
    this->_has_shot = has_shot;
}

enum Direction Player::get_dir()
{
    return this->_dir;
}
void Player::set_dir(const enum Direction dir)
{
    this->_dir = dir;
}

std::clock_t Player::get_cl()
{
    return this->_cl;
}

void Player::restart_cl()
{
    this->_cl = clock();
}
