/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game
*/

/**
 * @file Game.hpp
 * @brief Declaration of the Game class.
 */

#pragma once

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "UUID.hpp" // Ensure this path is correct and the uuid class is defined in this header

#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>

/**
 * @class Game
 * @brief Manages the game state, including players, enemies, and bullets.
 *
 * The Game class handles the creation, destruction, and updating of game entities,
 * as well as checking for collisions and running the main game loop.
 */
class Game
{
public:
    /**
     * @brief Construct a new Game object.
     *
     * This constructor initializes the game state.
     */
    Game();

    /**
     * @brief Default destructor for Game.
     */
    ~Game();

    /**
     * @brief Check for collisions between entities.
     *
     * This method checks for collisions between players and enemies, and between bullets and enemies.
     * It destroys the entities involved in collisions.
     */
    void check_collisions();

    /**
     * @brief Start the game.
     * 
     * This method initializes the game by creating initial players.
     */
    void start();

    /**
     * @brief Run the game loop.
     * 
     * This method runs the main game loop, updating the game world and checking for collisions.
     */
    void run();

    /**
     * @brief Stop the game.
     * 
     * This method stops the game. (Currently not implemented)
     */
    void stop();

    /**
     * @brief Create a new player in the game.
     * 
     * @param id The ID of the player to be created.
     * 
     * @return true if the player was successfully created, false otherwise.
     * 
     * This method adds a new player to the game if the number of players is less than 4.
     */
    bool create_player(const uuid id);

    /**
     * @brief Create a new bullet for a given player.
     * 
     * @param player The player for whom the bullet is created.
     * 
     * This method adds a new bullet to the game at the player's current position.
     */
    void create_bullet(const Player player);

    /**
     * @brief Create a new enemy in the game.
     * 
     * This method adds a new enemy to the game at a predefined position.
     */
    void create_enemy();

    /**
     * @brief Destroy a player by their ID.
     * 
     * @param player_id The ID of the player to be destroyed.
     * 
     * This method removes a player from the game based on their ID.
     */
    void destroy_player(const uuid id);

    /**
     * @brief Destroy a bullet by its ID.
     * 
     * @param bullet_id The ID of the bullet to be destroyed.
     * 
     * This method removes a bullet from the game based on its ID.
     */
    void destroy_bullet(const uuid bullet_id);

    /**
     * @brief Destroy an enemy by their ID.
     * 
     * @param enemy_id The ID of the enemy to be destroyed.
     * 
     * This method removes an enemy from the game based on their ID.
     */
    void destroy_enemy(const uuid enemy_id);

    /**
     * @brief Update the game world.
     * 
     * This method updates the positions of all enemies, bullets, and players in the game.
     */
    void update_world();

    /**
     * @brief Check if two entities are in collision.
     * 
     * @param entity1 The first entity.
     * @param entity2 The second entity.
     * @return true if the entities are in collision, false otherwise.
     * 
     * This method checks if two entities are colliding based on their positions and dimensions.
     */
    bool is_in_collision(AEntity& entity1, AEntity& entity2);

private:
    std::vector<Player> _player; ///< List of players in the game.
    std::vector<Enemy> _enemy; ///< List of enemies in the game.
    std::vector<Bullet> _bullet; ///< List of bullets in the game.
    bool _running; ///< Flag indicating if the game is running.

    std::mutex _player_mutex; ///< Mutex for protecting the player vector.
    std::mutex _enemy_mutex; ///< Mutex for protecting the enemy vector.
    std::mutex _bullet_mutex; ///< Mutex for protecting the bullet vector.
    std::thread _thread; ///< Thread for running the game loop.
};