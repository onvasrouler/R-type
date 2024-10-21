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

// Charging tests

// Charge test to create many enemies
TEST_F(GameTest, LoadTestCreateManyEnemies) {
    const int numEnemies = 1000;
    for (int i = 0; i < numEnemies; ++i) {
        game->create_enemy();
    }

    EXPECT_EQ(game->getEnemies().size(), numEnemies);
}

// Charge test to create many bullets with one player
TEST_F(GameTest, LoadTestCreateManyBullets) {
    std::string playerId = "player1";
    game->create_player(playerId);
    Player player = game->getPlayers().at(0);

    const int numBullets = 1000;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player);
    }

    EXPECT_EQ(game->getBullets().size(), numBullets);
}

// Charge test to create many bullets with two players
TEST_F(GameTest, LoadTestCreateManyBulletsTwoPlayers) {
    game->create_player("player1");
    game->create_player("player2");
    Player player1 = game->getPlayers().at(0);
    Player player2 = game->getPlayers().at(1);

    const int numBullets = 1000;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player1);
        game->create_bullet(player2);
    }

    EXPECT_EQ(game->getBullets().size(), numBullets * 2);
}

// Charge test to create many bullets with three players
TEST_F(GameTest, LoadTestCreateManyBulletsThreePlayers) {
    game->create_player("player1");
    game->create_player("player2");
    game->create_player("player3");
    Player player1 = game->getPlayers().at(0);
    Player player2 = game->getPlayers().at(1);
    Player player3 = game->getPlayers().at(2);

    const int numBullets = 1000;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player1);
        game->create_bullet(player2);
        game->create_bullet(player3);
    }

    EXPECT_EQ(game->getBullets().size(), numBullets * 3);
}

// Charge test to create many bullets with four players
TEST_F(GameTest, LoadTestCreateManyBulletsFourPlayers) {
    game->create_player("player1");
    game->create_player("player2");
    game->create_player("player3");
    game->create_player("player4");
    Player player1 = game->getPlayers().at(0);
    Player player2 = game->getPlayers().at(1);
    Player player3 = game->getPlayers().at(2);
    Player player4 = game->getPlayers().at(3);

    const int numBullets = 1000;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player1);
        game->create_bullet(player2);
        game->create_bullet(player3);
        game->create_bullet(player4);
    }

    EXPECT_EQ(game->getBullets().size(), numBullets * 4);
}

// Test to create multiple game instances with the maximum number of players per game
TEST(GameInstanceTest, MultipleGamesWithMaxPlayers) {
    const int numGames = 100;
    const int maxPlayers = 4;
    std::vector<Game*> games;

    for (int i = 0; i < numGames; ++i) {
        Game* game = new Game();
        for (int j = 0; j < maxPlayers; ++j) {
            std::string playerId = "game" + std::to_string(i) + "_player" + std::to_string(j);
            game->create_player(playerId);
        }
        games.push_back(game);
    }

    for (auto game : games) {
        EXPECT_EQ(game->getPlayers().size(), maxPlayers);
        delete game;
    }
}