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
    std::cout << "Destroying game engine" << std::endl;
    if (_running)
        this->stop();
    std::cout << "Game engine destroyed" << std::endl;
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
    if (this->_player.size() < 4) {
        Player player(500, id);
        this->_player.push_back(player);
        std::string message = PLAYER_SPAWN_CODE + std::string("/") + player.get_id().toString() + std::string("/") + std::to_string(player.get_type()) + std::string("/") + std::to_string(player.get_level()) + std::string("/") + std::to_string(player.get_hp()) + std::string("/") + std::to_string(player.get_x()) + std::string("/") + std::to_string(player.get_y()) + END_MESSAGE_CODE;
        _sendMutex.lock();
        for (auto &player : _player) {
            if (player.get_id() == id) {
                continue;
            }
            _sendMessages.push_back(gameMessage(player.get_id(), message));
        }
        _sendMutex.unlock();
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
    this->_bullet.push_back(Bullet(player.get_x() + player.get_l(), player.get_y()));
    std::string message = BULLET_SPAWN_CODE + std::string("/") + this->_bullet.back().get_id().toString() + std::string("/") + std::to_string(this->_bullet.back().get_x()) + std::string("/") + std::to_string(this->_bullet.back().get_y()) + END_MESSAGE_CODE;
    _sendMutex.lock();
    for (auto &player : _player) {
        _sendMessages.push_back(gameMessage(player.get_id(), message));
    }
    _sendMutex.unlock();
}

/**
 * @brief Create a new enemy in the game.
 *
 * This method adds a new enemy to the game at a predefined position.
 */
void Game::create_enemy()
{
    this->_enemy.push_back(Enemy(500));
    std::string message = ENEMY_SPAWN_CODE + std::string("/") + this->_enemy.back().get_id().toString() + std::string("/") + std::to_string(this->_enemy.back().get_type()) + std::string("/") + std::to_string(this->_enemy.back().get_level()) + std::string("/") + std::to_string(this->_enemy.back().get_hp()) + std::string("/") + std::to_string(this->_enemy.back().get_x()) + std::string("/") + std::to_string(this->_enemy.back().get_y()) + END_MESSAGE_CODE;
    _sendMutex.lock();
    for (auto &player : _player) {
        _sendMessages.push_back(gameMessage(player.get_id(), message));
    }
    _sendMutex.unlock();
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
    for (auto player = this->_player.begin(); player != this->_player.end(); ++player) {
        if (player->get_id() == id) {
            this->_player.erase(player);
            std::string message = PLAYER_DEATH_CODE + std::string("/") + player->get_id().toString() + END_MESSAGE_CODE;
            _sendMutex.lock();
            for (auto &player : _player) {
                _sendMessages.push_back(gameMessage(player.get_id(), message));
            }
            _sendMutex.unlock();
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
void Game::destroy_bullet(const uuid bullet_id)
{
    for (auto it = this->_bullet.begin(); it != this->_bullet.end(); ++it) {
        if (it->get_id() == bullet_id) {
            std::string message = BULLET_DEATH_CODE + std::string("/") + it->get_id().toString() + END_MESSAGE_CODE;
            _sendMutex.lock();
            for (auto &player : _player) {
                _sendMessages.push_back(gameMessage(player.get_id(), message));
            }
            _sendMutex.unlock();
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
void Game::destroy_enemy(const uuid enemy_id)
{
    for (auto it = this->_enemy.begin(); it != this->_enemy.end(); ++it) {
        if (it->get_id() == enemy_id) {
            std::string message = ENEMY_DEATH_CODE + std::string("/") + it->get_id().toString() + END_MESSAGE_CODE;
            _sendMutex.lock();
            for (auto &player : _player) {
                _sendMessages.push_back(gameMessage(player.get_id(), message));
            }
            _sendMutex.unlock();
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
    int i = 0;
    std::vector<uuid> to_destroy;
    for (auto& enemy : this->_enemy) {
        enemy.move();
        std::string message = ENEMY_POSITION_CODE + std::string("/") + enemy.get_id().toString() + std::string("/") + std::to_string(enemy.get_x()) + std::string("/") + std::to_string(enemy.get_y()) + END_MESSAGE_CODE;
        _sendMutex.lock();
        for (auto &player : _player) {
            _sendMessages.push_back(gameMessage(player.get_id(), message));
        }
        _sendMutex.unlock();
        if (enemy.get_x() < 0) {
            to_destroy.push_back(enemy.get_id());
        }
        i++;
    }
    for (auto id : to_destroy) {
        this->destroy_enemy(id);
    }
    to_destroy.clear();
    for (auto& bullet : this->_bullet) {
        bullet.move();
        std::string message = BULLET_POSITION_CODE + std::string("/") + bullet.get_id().toString() + std::string("/") + std::to_string(bullet.get_x()) + std::string("/") + std::to_string(bullet.get_y()) + END_MESSAGE_CODE;
        _sendMutex.lock();
        for (auto &player : _player) {
            _sendMessages.push_back(gameMessage(player.get_id(), message));
        }
        _sendMutex.unlock();
        if (bullet.get_x() > 1920) {
            to_destroy.push_back(bullet.get_id());
        }
    }
    for (auto id : to_destroy) {
        this->destroy_bullet(id);
    }
    for (auto& player : this->_player) {
        if (player.get_dir() != NONE) {
            player.move();
            std::string message = PLAYER_POSITION_CODE + std::string("/") + player.get_id().toString() + std::string("/") + std::to_string(player.get_x()) + std::string("/") + std::to_string(player.get_y()) + END_MESSAGE_CODE;
            _sendMutex.lock();
            for (auto &player : _player) {
                _sendMessages.push_back(gameMessage(player.get_id(), message));
            }
            _sendMutex.unlock();
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
    std::vector<uuid> to_destroy;

    for (auto& player : this->_player) {
        for (auto& enemy : this->_enemy) {
            if (this->is_in_collision(player, enemy)) {
                std::string message = PLAYER_DAMAGE_CODE + std::string("/") + player.get_id().toString() + std::string("/") + "1" + END_MESSAGE_CODE;
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
    if (!_running)
        return;
    std::cout << "Stopping game engine" << std::endl;
    _running = false;
    _thread.join();
    if (_sendMutex.try_lock()) {
        _sendMutex.unlock();
    }
    if (_readMutex.try_lock()) {
        _readMutex.unlock();
    }
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
    std::clock_t cl2 = clock();

    std::cout << "Running game engine" << std::endl;
    while (_running) {
        handleMessages();
        if (clock() - cl > 100000) { // 1000000 = 1 sec
            cl = clock();
            this->update_world();
        }
        if (clock() - cl2 > 2000000 && this->_enemy.size() < MAX_ENEMIES) { // 2000000 = 2 sec
            cl2 = clock();
            this->create_enemy();
        }
        this->check_collisions();
    }
}

void Game::handleMessages() {
    _readMutex.lock();
    for (auto &receivedMessage : _readMessages) {
        std::cout << "Game handle Message Received message: " << receivedMessage.getMessage() << std::endl;
        std::cout << "Game handle Message Received id: " << receivedMessage.getId().toString() << std::endl;
        if (receivedMessage.getMessage() == NEW_PLAYER_REQUEST_CODE && _player.size() < MAX_PLAYERS) {
            create_player(receivedMessage.getId());
            std::string message = NEW_PLAYER_ACCEPTED_CODE + std::string("/") + receivedMessage.getId().toString() + std::string("/") + std::to_string(_player.back().get_type()) + std::string("/") + std::to_string(_player.back().get_level()) + std::string("/") + std::to_string(_player.back().get_hp()) + std::string("/") + std::to_string(_player.back().get_x()) + std::string("/") + std::to_string(_player.back().get_y()) + END_MESSAGE_CODE;
            _sendMutex.lock();
            _sendMessages.push_back(gameMessage(receivedMessage.getId(), message));
            _sendMutex.unlock();
        } else {
            std::string message = NEW_PLAYER_REJECTED_CODE + std::string("/") + receivedMessage.getId().toString() + END_MESSAGE_CODE;
            _sendMutex.lock();
            _sendMessages.push_back(gameMessage(receivedMessage.getId(), message));
            _sendMutex.unlock();
        }
    }
    _readMessages.clear();
    _readMutex.unlock();
}

void Game::addSendMessage() {
    _sendMutex.lock();
    for (auto &gameMessage : _sendMessages) {
        //implement whith the protocol
    }
    _sendMutex.unlock();
}

std::vector<gameMessage> &Game::getSendMessages() {
    return _sendMessages;
}

std::vector<gameMessage> &Game::getReadMessages() {
    return _readMessages;
}

std::mutex &Game::getSendMutex() {
    return _sendMutex;
}

std::mutex &Game::getReadMutex() {
    return _readMutex;
}

gameMessage::gameMessage(const uuid &id, const std::string message) : _id(id), _message(message) {};

const uuid &gameMessage::getId() {
    return _id;
}

const std::string gameMessage::getMessage() {
    return _message;
}
