/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game
*/

#pragma once

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

#include <vector>
#include <string>
#include <ctime>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init_game();
    void check_collisions();

    bool create_player();
    void create_bullet(Player first);
    void create_enemy();
    void destroy_player(int player_id);
    void destroy_bullet(int bullet_id);
    void destroy_enemy(int enemy_id);
    void update_word();
    bool is_in_collision(Player first, Enemy second);
    bool is_in_collision(Enemy first, Bullet second);

private:
    std::vector<Player> _player;
    std::vector<Enemy> _enemy;
    std::vector<Bullet> _bullet;
};
