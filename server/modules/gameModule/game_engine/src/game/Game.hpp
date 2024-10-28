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

#include "../entity/character/Player.hpp"
#include "../entity/character/Enemy.hpp"
#include "../entity/bullet/Bullet.hpp"
#include "UUID.hpp"

#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>

#define MAX_PLAYERS 4 ///< The maximum number of players in the game.
#define MAX_ENEMIES 2 ///< The maximum number of enemies in the game.
#define END_MESSAGE_CODE "\r\n"

//new Player 0:
    #define NEW_PLAYER_REQUEST_CODE "00"
    #define NEW_PLAYER_ACCEPTED_CODE "01"
    #define NEW_PLAYER_REJECTED_CODE "02"
// input 1:
    #define MOVE_UP "up"
    #define MOVE_DOWN "down"
    #define MOVE_LEFT "left"
    #define MOVE_RIGHT "right"
    #define SHOOT "shoot"
//data 2:
    //player 0:
        #define PLAYER_SPAWN_CODE "200"
        #define PLAYER_DAMAGE_CODE "201"
        #define PLAYER_POSITION_CODE "202"
        #define PLAYER_DEATH_CODE "203"
    //Enemy 1:
        #define ENEMY_SPAWN_CODE "210"
        #define ENEMY_DAMAGE_CODE "211"
        #define ENEMY_POSITION_CODE "212"
        #define ENEMY_DEATH_CODE "213"
    //Bullet 2:
        #define BULLET_SPAWN_CODE "220"
        #define BULLET_POSITION_CODE "221"
        #define BULLET_DEATH_CODE "222"

class gameMessage {
    public :
        gameMessage(const std::string &id, const std::string message);
        ~gameMessage() = default;
        std::string &getId();
        const std::string getMessage();
    private:
        std::string _id;
        const std::string _message;
};

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
    bool create_player(const std::string id);

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
    void destroy_player(const std::string id);

    /**
     * @brief Destroy a bullet by its ID.
     * 
     * @param bullet_id The ID of the bullet to be destroyed.
     * 
     * This method removes a bullet from the game based on its ID.
     */
    void destroy_bullet(const std::string bullet_id);

    /**
     * @brief Destroy an enemy by their ID.
     * 
     * @param enemy_id The ID of the enemy to be destroyed.
     * 
     * This method removes an enemy from the game based on their ID.
     */
    void destroy_enemy(const std::string enemy_id);

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

    bool isPlayer(const std::string id);

    void handleMessages();
    void addSendMessage();
    std::vector<gameMessage> &getSendMessages();
    std::vector<gameMessage> &getReadMessages();
    std::mutex &getSendMutex();
    std::mutex &getReadMutex();

    std::vector<Player> &getPlayers();
    std::vector<Enemy> &getEnemies();
    std::vector<Bullet> &getBullets();
    bool isRunning();

private:
    std::vector<Player> _player; ///< List of players in the game.
    std::vector<Enemy> _enemy; ///< List of enemies in the game.
    std::vector<Bullet> _bullet; ///< List of bullets in the game.
    bool _running; ///< Flag indicating if the game is running.

    std::mutex _sendMutex;
    std::vector<gameMessage> _sendMessages;
    std::mutex _readMutex;
    std::vector<gameMessage> _readMessages;
    std::thread _thread; ///< Thread for running the game loop.
};