/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** testGameEngine
*/

/**
 * @file testGameEngine.hpp
 * @brief Declaration of the testGameEngine class.
 */

#pragma once

#include <gtest/gtest.h>
#include <chrono>
#include "../../server/modules/gameModule/game_engine/src/game/Game.hpp"

#define MAX_PLAYERS 4 ///< The maximum number of players in the game.
#define NUM_ENEMIES 4 ///< The number of enemies in the game.
#define NUM_GAMES 10 ///< The number of games to create.
#define CREATE_MANY_ENEMIES_NUM_ENEMIES 1000 ///< The maximum number of enemies in the game.
#define CREATE_MANY_BULLETS_NUM_BULLETS 1000 ///< The maximum number of bullets in the game.