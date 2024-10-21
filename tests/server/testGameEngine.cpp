/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game tests
*/

#include <gtest/gtest.h>
#include <chrono>
#include "../../server/game_engine/src/game/Game.hpp"

class GameTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Init the Game object
        game = new Game();
        start = std::chrono::high_resolution_clock::now(); // Start the chrono
    }

    void TearDown() override {
        // Stop the chrono and print the duration
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Test duration: " << duration.count() << " ms" << std::endl;

        // Delete the game entity at the end of the test
        delete game;
    }

    Game* game;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

// Test to verify the player creation
TEST_F(GameTest, CreatePlayerSuccess) {
    std::string playerId = "player1";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the player creation limit
TEST_F(GameTest, CreatePlayerLimit) {
    for (int i = 0; i < 4; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->create_player(playerId);
    }

    std::string extraPlayerId = "player4";
    bool result = game->create_player(extraPlayerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 4);
}

// Test to verify the creation of a bullet
TEST_F(GameTest, CreateBullet) {
    std::string playerId = "player1";
    game->create_player(playerId);
    Player player = game->getPlayers().at(0);

    game->create_bullet(player);
    EXPECT_EQ(game->getBullets().size(), 1);
}

// Test to verify the creation of an ennemy
TEST_F(GameTest, CreateEnemy) {
    game->create_enemy();
    EXPECT_EQ(game->getEnemies().size(), 1);
}

// Test to verify the destroy of a player
TEST_F(GameTest, DestroyPlayer) {
    std::string playerId = "player1";
    game->create_player(playerId);
    game->destroy_player(playerId);

    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the destroy of a bullet
TEST_F(GameTest, DestroyBullet) {
    std::string playerId = "player1";
    game->create_player(playerId);
    Player player = game->getPlayers().at(0);
    game->create_bullet(player);
    std::string bulletId = game->getBullets().at(0).get_id();

    game->destroy_bullet(bulletId);
    EXPECT_EQ(game->getBullets().size(), 0);
}

// Test to verify the destroy of an ennemy
TEST_F(GameTest, DestroyEnemy) {
    game->create_enemy();
    std::string enemyId = game->getEnemies().at(0).get_id();

    game->destroy_enemy(enemyId);
    EXPECT_EQ(game->getEnemies().size(), 0);
}

// Test to verify the world update
TEST_F(GameTest, UpdateWorld) {
    game->create_player("player1");
    game->create_enemy();
    game->update_world();

    // Ensure entity's positions have been updated
    EXPECT_GT(game->getEnemies().at(0).get_x(), 0);
}

// Test to verify the server start
TEST_F(GameTest, StartGame) {
    game->start();
    EXPECT_TRUE(game->isRunning());
}

// Test to verify the server stop
TEST_F(GameTest, StopGame) {
    game->start();
    game->stop();
    EXPECT_FALSE(game->isRunning());
}