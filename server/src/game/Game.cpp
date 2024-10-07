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


Game::~Game()
{

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
    for (long unsigned int i = 0; i < this->_player.size(); i++) {
        if (this->_player[i].get_id() == player_id) {
            this->_player.erase(this->_player.begin() + i);
            return;
        }
    }
}

void Game::destroy_bullet(int bullet_id)
{
    for (long unsigned int i = 0; i < this->_bullet.size(); i++) {
        if (this->_bullet[i].get_id() == bullet_id) {
            this->_bullet.erase(this->_bullet.begin() + i);
            return;
        }
    }
}

void Game::destroy_enemy(int enemy_id)
{
    for (long unsigned int i = 0; i < this->_enemy.size(); i++) {
        if (this->_enemy[i].get_id() == enemy_id) {
            this->_enemy.erase(this->_enemy.begin() + i);
            return;
        }
    }
}

void Game::update_word()
{
    for (long unsigned int i = 0; i < this->_enemy.size(); i++) {
        this->_enemy[i].move();
    }
    for (long unsigned int i = 0; i < this->_bullet.size(); i++) {
        this->_bullet[i].move();
    }
    for (long unsigned int i = 0; i < this->_player.size(); i++) {
        if (this->_player[i].get_dir() != NONE) {
            this->_player[i].move();
        }
        if (this->_player[i].get_has_shot() == true && clock() - this->_player[i].get_cl() > 1000000) {
            this->create_bullet(this->_player[i]);
            this->_player[i].set_has_shot(false);
            this->_player[i].restart_cl();
        }
    }
}

bool Game::is_in_collision(Player first, Enemy second)
{
    int x1 = first.get_x();
    int y1 = first.get_y();
    int l1 = first.get_l();
    int h1 = first.get_h();
    int x2 = second.get_x();
    int y2 = second.get_y();
    int l2 = second.get_l();
    int h2 = second.get_h();

    if ((x1 <= x2 && x1 + l1 >= x2) || (x2 <= x1 && x2 + l2 >= x1)) {
        if ((y1 <= y2 && y1 + h1 >= y2) || (y2 <= y1 && y2 + h2 >= y1)) {
            return (true);
        }
    }

    return (false);
}

bool Game::is_in_collision(Enemy first, Bullet second)
{
    int x1 = first.get_x();
    int y1 = first.get_y();
    int l1 = first.get_l();
    int h1 = first.get_h();
    int x2 = second.get_x();
    int y2 = second.get_y();
    int l2 = second.get_l();
    int h2 = second.get_h();

    if ((x1 <= x2 && x1 + l1 >= x2) || (x2 <= x1 && x2 + l2 >= x1)) {
        if ((y1 <= y2 && y1 + h1 >= y2) || (y2 <= y1 && y2 + h2 >= y1)) {
            return (true);
            std::cout << "lol";
        }
    }

    return (false);
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


void Game::init_game()
{
    std::clock_t cl = clock();
    this->create_player();
    this->create_player();

    while (this->_player.size() > 0) {
        if (clock() - cl > 100000) { // 1000000 = 1 sec
            cl = clock();
            std::cout << "move" << std::endl;
            this->update_word();
        }
        this->check_collisions();
    }
}
