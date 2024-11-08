/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Player
*/

/**
 * @file Player.hpp
 * @brief Declaration of the Player class.
 */

#pragma once

#include <ctime>
#include <chrono>
#include "../ACharacter.hpp"

#define INITIAL_X 100 ///< The initial x-coordinate of the player in pixels.
#define INITIAL_DIMENSION 70 ///< The initial dimensions of the player in pixels.
#define MOVE_DISTANCE 10 ///< The distance to move the player in one step in pixels.
#define PLAYER_HP 1 ///< The health points of the player.

/**
 * @enum Direction
 * @brief Represents the possible movement directions for the player.
 */
enum Direction {
    NONE, ///< No movement.
    UP,   ///< Move up.
    DOWN, ///< Move down.
    LEFT, ///< Move left.
    RIGHT ///< Move right.
};

/**
 * @class Player
 * @brief Represents a player character in the game.
 * 
 * The Player class inherits from ACharacter and adds specific attributes and methods
 * related to players, such as movement and shooting status.
 */
class Player : public ACharacter
{
public:
    /**
     * @brief Construct a new Player object.
     * 
     * @param y The initial y-coordinate of the player.
     * 
     * This constructor initializes the player's position, dimensions, shot status, direction, and clock.
     */
    Player(const int y, const std::string &id);

    /**
     * @brief Default destructor for Player.
     */
    ~Player() = default;

    /**
     * @brief Move the player based on the current direction.
     * 
     * The player can move up, down, right, or left based on the value of the _dir attribute.
     */
    void move();

    /**
     * @brief Get the current direction of the player.
     * 
     * @return enum Direction The current direction of the player.
     */
    enum Direction get_dir();

    /**
     * @brief Set the current direction of the player.
     * 
     * @param dir The new direction to be set.
     */
    void set_dir(const enum Direction dir);

    /**
     * @brief Get the shot status of the player.
     * 
     * @return bool The shot status of the player.
     */
    bool get_has_shot();

    /**
     * @brief Set the shot status of the player.
     * 
     * @param has_shot The new shot status to be set.
     */
    void set_has_shot(const bool has_shot);

    /**
     * @brief Get the clock value of the player.
     * 
     * @return std::clock_t The clock value of the player.
     */
    std::chrono::high_resolution_clock::time_point get_cl();

    /**
     * @brief Restart the clock of the player.
     */
    void restart_cl();

    /**
     * @brief Get the clock value of the player.
     * 
     * @return std::clock_t The clock value of the player.
     */
    std::chrono::high_resolution_clock::time_point get_last_move();

    /**
     * @brief Restart the clock of the player.
     */
    void restart_last_move();

private:
    bool _has_shot;
    enum Direction _dir;
    std::chrono::high_resolution_clock::time_point _cl;
    std::chrono::high_resolution_clock::time_point _last_move;
};
