/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    this->init_game();
}

bool Game::create_player()
{
    if (this->_player.size() < 4) {
        this->_player.push_back(Player(50));
    } else {
        return (false);
    }

    return (true);
}

void Game::create_bullet(Player player)
{
    this->_bullet.push_back(Bullet(player.get_x() + player.get_l(), player.get_y()));
}


void Game::create_enemy()
{
    this->_enemy.push_back(Enemy(50));
}

void Game::destroy_player(int player_id)
{
    for (auto player = this->_player.begin(); player != this->_player.end(); ++player) {
        if (player->get_id() == player_id) {
            this->_player.erase(player);
            return;
        }
    }
}

void Game::destroy_bullet(int bullet_id)
{
    for (auto it = this->_bullet.begin(); it != this->_bullet.end(); ++it) {
        if (it->get_id() == bullet_id) {
            this->_bullet.erase(it);
            return;
        }
    }
}

void Game::destroy_enemy(int enemy_id)
{
    for (auto it = this->_enemy.begin(); it != this->_enemy.end(); ++it) {
        if (it->get_id() == enemy_id) {
            this->_enemy.erase(it);
            return;
        }
    }
}

void Game::update_word()
{
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

void Game::check_collisions()
{
    std::vector<int> to_destroy;

    for (long unsigned int i = 0; i < this->_player.size(); i++) {
        for (long unsigned int u = 0; u < this->_enemy.size(); u++) {
            if (this->is_in_collision(this->_player[i], this->_enemy[u])) {
                to_destroy.push_back(this->_player[i].get_id());
            }
        }
    }

    for (long unsigned int i = 0; i < to_destroy.size(); i++) {
        this->destroy_player(to_destroy[i]);
    }

    to_destroy.clear();

    for (long unsigned int i = 0; i < this->_enemy.size(); i++) {
        for (long unsigned int u = 0; i < this->_bullet.size(); u++) {
            if (this->is_in_collision(this->_enemy[i], this->_bullet[u])) {
                to_destroy.push_back(this->_enemy[i].get_id());
                this->destroy_bullet(this->_bullet[u].get_id());
            }
        }
    }

    for (long unsigned int i = 0; i < to_destroy.size(); i++) {
        this->destroy_enemy(to_destroy[i]);
    }
}

void Game::start()
{
    std::clock_t cl = clock();
    this->create_player();
    this->create_player();
}

void Game::stop()
{
    
}

void Game::run()
{
    while (this->_player.size() > 0) {
        if (clock() - cl > 100000) { // 1000000 = 1 sec
            cl = clock();
            std::cout << "move" << std::endl;
            this->update_word();
        }
        this->check_collisions();
    }
}
