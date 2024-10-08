/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game
*/

/**
 * @file Game.cpp
 * @brief Implementation of the Game class.
 */

#include "Game.hpp"

/**
 * @brief Construct a new Game object.
 * 
 * This constructor initializes the game state.
 */
Game::Game()
{
    std::cout << "Creating game engine" << std::endl;
    _running = false;
    std::cout << "Game engine created" << std::endl;
}

Game::~Game()
{
    std::cout << "Deleting game engine" << std::endl;
    if (_running)
        this->stop();
    std::cout << "Game engine deleted" << std::endl;
}

/**
 * @brief Create a new player in the game.
 * 
 * @return true if the player was successfully created, false otherwise.
 * 
 * This method adds a new player to the game if the number of players is less than 4.
 */
bool Game::create_player(const UUID id)
{
    std::lock_guard<std::mutex> lock(_player_mutex);
    if (this->_player.size() < 4) {
        Player player(500);
        player.set_id(id);
        this->_player.push_back(player);
    } else {
        return false;
    }

    return true;
}

/**
 * @brief Create a new bullet for a given player.
 * 
 * @param player The player for whom the bullet is created.
 * 
 * This method adds a new bullet to the game at the player's current position.
 */
void Game::create_bullet(const Player player)
{
    std::lock_guard<std::mutex> lock(_bullet_mutex);
    this->_bullet.push_back(Bullet(player.get_x() + player.get_l(), player.get_y()));
}

/**
 * @brief Create a new enemy in the game.
 * 
 * This method adds a new enemy to the game at a predefined position.
 */
void Game::create_enemy()
{
    std::lock_guard<std::mutex> lock(_enemy_mutex);
    this->_enemy.push_back(Enemy(500));
}

/**
 * @brief Destroy a player by their ID.
 * 
 * @param player_id The ID of the player to be destroyed.
 * 
 * This method removes a player from the game based on their ID.
 */
void Game::destroy_player(const UUID id)
{
    std::lock_guard<std::mutex> lock(_player_mutex);
    for (auto player = this->_player.begin(); player != this->_player.end(); ++player) {
        if (player->get_id() == id) {
            this->_player.erase(player);
            return;
        }
    }
}

/**
 * @brief Destroy a bullet by its ID.
 * 
 * @param bullet_id The ID of the bullet to be destroyed.
 * 
 * This method removes a bullet from the game based on its ID.
 */
void Game::destroy_bullet(const UUID bullet_id)
{
    std::lock_guard<std::mutex> lock(_bullet_mutex);
    for (auto it = this->_bullet.begin(); it != this->_bullet.end(); ++it) {
        if (it->get_id() == bullet_id) {
            this->_bullet.erase(it);
            return;
        }
    }
}

/**
 * @brief Destroy an enemy by their ID.
 * 
 * @param enemy_id The ID of the enemy to be destroyed.
 * 
 * This method removes an enemy from the game based on their ID.
 */
void Game::destroy_enemy(const UUID enemy_id)
{
    std::lock_guard<std::mutex> lock(_enemy_mutex);
    for (auto it = this->_enemy.begin(); it != this->_enemy.end(); ++it) {
        if (it->get_id() == enemy_id) {
            this->_enemy.erase(it);
            return;
        }
    }
}

/**
 * @brief Update the game world.
 * 
 * This method updates the positions of all enemies, bullets, and players in the game.
 */
void Game::update_world()
{
    std::lock_guard<std::mutex> lock_player(_player_mutex);
    std::lock_guard<std::mutex> lock_enemy(_enemy_mutex);
    std::lock_guard<std::mutex> lock_bullet(_bullet_mutex);
    for (auto& enemy : this->_enemy) {
        enemy.move();
    }
    for (auto& bullet : this->_bullet) {
        bullet.move();
    }
    for (auto& player : this->_player) {
        if (player.get_dir() != NONE) {
            player.move();
        }
        if (player.get_has_shot() == true && clock() - player.get_cl() > 1000000) {
            this->create_bullet(player);
            player.set_has_shot(false);
            player.restart_cl();
        }
    }
}

/**
 * @brief Check if two entities are in collision.
 * 
 * @param entity1 The first entity.
 * @param entity2 The second entity.
 * @return true if the entities are in collision, false otherwise.
 * 
 * This method checks if two entities are colliding based on their positions and dimensions.
 */
bool Game::is_in_collision(AEntity& entity1, AEntity& entity2)
{
    int x1 = entity1.get_x();
    int y1 = entity1.get_y();
    int l1 = entity1.get_l();
    int h1 = entity1.get_h();
    int x2 = entity2.get_x();
    int y2 = entity2.get_y();
    int l2 = entity2.get_l();
    int h2 = entity2.get_h();

    if ((x1 <= x2 && x1 + l1 >= x2) || (x2 <= x1 && x2 + l2 >= x1)) {
        if ((y1 <= y2 && y1 + h1 >= y2) || (y2 <= y1 && y2 + h2 >= y1)) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Check for collisions between entities.
 * 
 * This method checks for collisions between players and enemies, and between bullets and enemies.
 * It destroys the entities involved in collisions.
 */
void Game::check_collisions()
{
    std::vector<std::string> to_destroy;

    for (auto& player : this->_player) {
        for (auto& enemy : this->_enemy) {
            if (this->is_in_collision(player, enemy)) {
                to_destroy.push_back(player.get_id());
            }
        }
    }

    for (auto id : to_destroy) {
        this->destroy_player(id);
    }

    to_destroy.clear();

    for (auto& enemy : this->_enemy) {
        for (auto& bullet : this->_bullet) {
            if (this->is_in_collision(enemy, bullet)) {
                to_destroy.push_back(enemy.get_id());
                this->destroy_bullet(bullet.get_id());
            }
        }
    }

    for (auto id : to_destroy) {
        this->destroy_enemy(id);
    }
}

/**
 * @brief Start the game.
 * 
 * This method initializes the game by creating initial players.
 */
void Game::start()
{
    std::cout << "Starting game engine" << std::endl;
    std::clock_t cl = clock();
    _running = true;
    std::cout << "Game engine started" << std::endl;
}

/**
 * @brief Stop the game.
 * 
 * This method stops the game. (Currently not implemented)
 */
void Game::stop()
{
    std::cout << "Stopping game engine" << std::endl;
    _running = false;
    std::cout << "Game engine stopped" << std::endl;
}

/**
 * @brief Run the game loop.
 * 
 * This method runs the main game loop, updating the game world and checking for collisions.
 */
void Game::run()
{
    std::cout << "Running game engine" << std::endl;
    while (_running) {
        if (clock() - cl > 100000) { // 1000000 = 1 sec
            cl = clock();
            std::cout << "move" << std::endl;
            this->update_world();
        }
        this->check_collisions();
    }
    std::cout << "Game engine stop run" << std::endl;
}