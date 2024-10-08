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
bool Game::create_player(const uuid id)
{
    _player_mutex.lock();
    if (this->_player.size() < 4) {
        Player player(500, id);
        this->_player.push_back(player);
        _player_mutex.unlock();
    } else {
        _player_mutex.unlock();
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
    _bullet_mutex.lock();
    this->_bullet.push_back(Bullet(player.get_x() + player.get_l(), player.get_y()));
    _bullet_mutex.unlock();
}

/**
 * @brief Create a new enemy in the game.
 *
 * This method adds a new enemy to the game at a predefined position.
 */
void Game::create_enemy()
{
    _enemy_mutex.lock();
    this->_enemy.push_back(Enemy(500));
    _enemy_mutex.unlock();
}

/**
 * @brief Destroy a player by their ID.
 *
 * @param player_id The ID of the player to be destroyed.
 *
 * This method removes a player from the game based on their ID.
 */
void Game::destroy_player(const uuid id)
{
    _player_mutex.lock();
    for (auto player = this->_player.begin(); player != this->_player.end(); ++player) {
        if (player->get_id() == id) {
            this->_player.erase(player);
            _player_mutex.unlock();
            return;
        }
    }
    _player_mutex.unlock();
}

/**
 * @brief Destroy a bullet by its ID.
 *
 * @param bullet_id The ID of the bullet to be destroyed.
 *
 * This method removes a bullet from the game based on its ID.
 */
void Game::destroy_bullet(const uuid bullet_id)
{
    _bullet_mutex.lock();
    for (auto it = this->_bullet.begin(); it != this->_bullet.end(); ++it) {
        if (it->get_id() == bullet_id) {
            this->_bullet.erase(it);
            _bullet_mutex.unlock();
            return;
        }
    }
    _bullet_mutex.unlock();
}

/**
 * @brief Destroy an enemy by their ID.
 *
 * @param enemy_id The ID of the enemy to be destroyed.
 *
 * This method removes an enemy from the game based on their ID.
 */
void Game::destroy_enemy(const uuid enemy_id)
{
    _enemy_mutex.lock();
    for (auto it = this->_enemy.begin(); it != this->_enemy.end(); ++it) {
        if (it->get_id() == enemy_id) {
            this->_enemy.erase(it);
            _enemy_mutex.unlock();
            return;
        }
    }
    _enemy_mutex.unlock();
}

/**
 * @brief Update the game world.
 *
 * This method updates the positions of all enemies, bullets, and players in the game.
 */
void Game::update_world()
{
    _enemy_mutex.lock();
    for (auto& enemy : this->_enemy) {
        enemy.move();
    }
    _enemy_mutex.unlock();
    _bullet_mutex.lock();
    for (auto& bullet : this->_bullet) {
        bullet.move();
    }
    _bullet_mutex.unlock();
    _player_mutex.lock();
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
    _player_mutex.unlock();
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
    std::vector<uuid> to_destroy;

    _player_mutex.lock();
    _enemy_mutex.lock();
    for (auto& player : this->_player) {
        for (auto& enemy : this->_enemy) {
            if (this->is_in_collision(player, enemy)) {
                to_destroy.push_back(player.get_id());
            }
        }
    }
    _player_mutex.unlock();

    for (auto id : to_destroy) {
        this->destroy_player(id);
    }

    to_destroy.clear();

    _bullet_mutex.lock();
    for (auto& enemy : this->_enemy) {
        for (auto& bullet : this->_bullet) {
            if (this->is_in_collision(enemy, bullet)) {
                to_destroy.push_back(enemy.get_id());
                this->destroy_bullet(bullet.get_id());
            }
        }
    }
    _bullet_mutex.unlock();
    _enemy_mutex.unlock();

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
    _thread = std::thread([this](void *_) -> void * {
        this->run();
        return nullptr;
    }, nullptr);
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
    _thread.join();
    if (_player_mutex.try_lock())
        _player_mutex.unlock();
    if (_bullet_mutex.try_lock())
        _bullet_mutex.unlock();
    if (_enemy_mutex.try_lock())
        _enemy_mutex.unlock();
    std::cout << "Game engine stopped" << std::endl;
}

/**
 * @brief Run the game loop.
 *
 * This method runs the main game loop, updating the game world and checking for collisions.
 */
void Game::run()
{
    std::clock_t cl = clock();

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