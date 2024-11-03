/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

/**
 * @file Player.cpp
 * @brief Implementation of the Player class.
 */

#include "Player.hpp"

/**
 * @brief Construct a new Player object.
 * 
 * @param y The initial y-coordinate of the player.
 * 
 * This constructor initializes the player's position, dimensions, shot status, direction, and clock.
 */
Player::Player(const int y, const std::string &id) : ACharacter(id)
{
    this->_origin = Point(INITIAL_X, y);
    this->_dimension = Rect(INITIAL_DIMENSION, INITIAL_DIMENSION);
    this->_has_shot = false;
    this->_dir = NONE;
    this->_cl = std::chrono::high_resolution_clock::now();
    this->_last_move = std::chrono::high_resolution_clock::now();
}

/**
 * @brief Move the player based on the current direction.
 * 
 * The player can move up, down, right, or left based on the value of the _dir attribute.
 */
void Player::move()
{
    if (this->_dir == UP) {
        this->set_y(this->get_y() - MOVE_DISTANCE);
    }
    if (this->_dir == DOWN) {
        this->set_y(this->get_y() + MOVE_DISTANCE);
    }
    if (this->_dir == RIGHT) {
        this->set_x(this->get_x() + MOVE_DISTANCE);
    }
    if (this->_dir == LEFT) {
        this->set_x(this->get_x() - MOVE_DISTANCE);
    }
    this->set_dir(NONE);
}

/**
 * @brief Get the shot status of the player.
 * 
 * @return bool The shot status of the player.
 */
bool Player::get_has_shot()
{
    return this->_has_shot;
}

/**
 * @brief Set the shot status of the player.
 * 
 * @param has_shot The new shot status to be set.
 */
void Player::set_has_shot(const bool has_shot)
{
    this->_has_shot = has_shot;

    this->_last_move = std::chrono::high_resolution_clock::now();
}

/**
 * @brief Get the current direction of the player.
 * 
 * @return enum Direction The current direction of the player.
 */
enum Direction Player::get_dir()
{
    return this->_dir;
}

/**
 * @brief Set the current direction of the player.
 * 
 * @param dir The new direction to be set.
 */
void Player::set_dir(const enum Direction dir)
{
    this->_dir = dir;

    this->_last_move = std::chrono::high_resolution_clock::now();
}

/**
 * @brief Get the clock value of the player.
 * 
 * @return std::clock_t The clock value of the player.
 */
std::chrono::high_resolution_clock::time_point Player::get_cl()
{
    return this->_cl;
}

/**
 * @brief Restart the clock of the player.
 */
void Player::restart_cl()
{
    this->_cl = std::chrono::high_resolution_clock::now();
}

/**
 * @brief Get the clock value of the player.
 * 
 * @return std::clock_t The clock value of the player.
 */
std::chrono::high_resolution_clock::time_point Player::get_last_move()
{
    return this->_cl;
}

/**
 * @brief Restart the clock of the player.
 */
void Player::restart_last_move()
{
    this->_cl = std::chrono::high_resolution_clock::now();
}

