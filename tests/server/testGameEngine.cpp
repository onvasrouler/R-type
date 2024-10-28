/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Game tests
*/

#include <gtest/gtest.h>
#include <chrono>
#include "../../server/modules/gameModule/game_engine/src/game/Game.hpp"

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

// Test to verify the creation of multiple players and enemies
TEST_F(GameTest, CreateMultiplePlayersAndEnemies) {
    const int numPlayers = 4;
    const int numEnemies = 4;

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->create_player(playerId);
    }

    for (int i = 0; i < numEnemies; ++i) {
        game->create_enemy();
    }

    EXPECT_EQ(game->getPlayers().size(), numPlayers);
    EXPECT_EQ(game->getEnemies().size(), numEnemies);
}

// Test to verify the destruction of multiple players and enemies
TEST_F(GameTest, DestroyMultiplePlayersAndEnemies) {
    const int numPlayers = 4;
    const int numEnemies = 4;

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->create_player(playerId);
    }

    for (int i = 0; i < numEnemies; ++i) {
        game->create_enemy();
    }

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->destroy_player(playerId);
    }

    for (int i = 0; i < numEnemies; ++i) {
        std::string enemyId = game->getEnemies().at(0).get_id();
        game->destroy_enemy(enemyId);
    }

    EXPECT_EQ(game->getPlayers().size(), 0);
    EXPECT_EQ(game->getEnemies().size(), 0);
}

// Test to verify the creation and destruction of multiple bullets
TEST_F(GameTest, CreateAndDestroyMultipleBullets) {
    std::string playerId = "player1";
    game->create_player(playerId);
    Player player = game->getPlayers().at(0);

    const int numBullets = 1000;
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player);
    }

    for (int i = 0; i < numBullets; ++i) {
        std::string bulletId = game->getBullets().at(0).get_id();
        game->destroy_bullet(bulletId);
    }

    EXPECT_EQ(game->getBullets().size(), 0);
}

// Test to verify the creation and destruction of multiple players, enemies, and bullets
TEST_F(GameTest, CreateAndDestroyMultipleEntities) {
    const int numPlayers = 4;
    const int numEnemies = 4;
    const int numBullets = 1000;

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->create_player(playerId);
    }

    for (int i = 0; i < numEnemies; ++i) {
        game->create_enemy();
    }

    Player player = game->getPlayers().at(0);
    for (int i = 0; i < numBullets; ++i) {
        game->create_bullet(player);
    }

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerId = "player" + std::to_string(i);
        game->destroy_player(playerId);
    }

    for (int i = 0; i < numEnemies; ++i) {
        std::string enemyId = game->getEnemies().at(0).get_id();
        game->destroy_enemy(enemyId);
    }

    for (int i = 0; i < numBullets; ++i) {
        std::string bulletId = game->getBullets().at(0).get_id();
        game->destroy_bullet(bulletId);
    }

    EXPECT_EQ(game->getPlayers().size(), 0);
    EXPECT_EQ(game->getEnemies().size(), 0);
    EXPECT_EQ(game->getBullets().size(), 0);
}

// Test to verify the creation of multiple game instances with varying numbers of players
TEST(GameInstanceTest, MultipleGamesWithVaryingPlayers) {
    const int numGames = 10;
    std::vector<int> playerCounts = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    std::vector<Game*> games;

    for (int i = 0; i < numGames; ++i) {
        Game* game = new Game();
        for (int j = 0; j < playerCounts[i]; ++j) {
            std::string playerId = "game" + std::to_string(i) + "_player" + std::to_string(j);
            game->create_player(playerId);
        }
        games.push_back(game);
    }

    for (int i = 0; i < numGames; ++i) {
        EXPECT_EQ(games[i]->getPlayers().size(), playerCounts[i]);
        delete games[i];
    }
}

// Test to verify the creation of multiple game instances with varying numbers of enemies
TEST(GameInstanceTest, MultipleGamesWithVaryingEnemies) {
    const int numGames = 10;
    std::vector<int> enemyCounts = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    std::vector<Game*> games;

    for (int i = 0; i < numGames; ++i) {
        Game* game = new Game();
        for (int j = 0; j < enemyCounts[i]; ++j) {
            game->create_enemy();
        }
        games.push_back(game);
    }

    for (int i = 0; i < numGames; ++i) {
        EXPECT_EQ(games[i]->getEnemies().size(), enemyCounts[i]);
        delete games[i];
    }
}

// Test to verify the creation of multiple game instances with varying numbers of bullets
TEST(GameInstanceTest, MultipleGamesWithVaryingBullets) {
    const int numGames = 10;
    std::vector<int> bulletCounts = {100, 200, 300, 400, 100, 200, 300, 400, 100, 200};
    std::vector<Game*> games;

    for (int i = 0; i < numGames; ++i) {
        Game* game = new Game();
        game->create_player("player1");
        Player player = game->getPlayers().at(0);
        for (int j = 0; j < bulletCounts[i]; ++j) {
            game->create_bullet(player);
        }
        games.push_back(game);
    }

    for (int i = 0; i < numGames; ++i) {
        EXPECT_EQ(games[i]->getBullets().size(), bulletCounts[i]);
        delete games[i];
    }
}

// Test to verify the creation of multiple game instances with varying numbers of players and enemies
TEST(GameInstanceTest, MultipleGamesWithVaryingPlayersAndEnemies) {
    const int numGames = 10;
    std::vector<int> playerCounts = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    std::vector<int> enemyCounts = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    std::vector<Game*> games;

    for (int i = 0; i < numGames; ++i) {
        Game* game = new Game();
        for (int j = 0; j < playerCounts[i]; ++j) {
            std::string playerId = "game" + std::to_string(i) + "_player" + std::to_string(j);
            game->create_player(playerId);
        }
        for (int j = 0; j < enemyCounts[i]; ++j) {
            game->create_enemy();
        }
        games.push_back(game);
    }

    for (int i = 0; i < numGames; ++i) {
        EXPECT_EQ(games[i]->getPlayers().size(), playerCounts[i]);
        EXPECT_EQ(games[i]->getEnemies().size(), enemyCounts[i]);
        delete games[i];
    }
}

// Player creation tests

// Test to verify the creation of a player with an empty ID
TEST_F(GameTest, CreatePlayerEmptyID) {
    std::string playerId = "";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a long ID
TEST_F(GameTest, CreatePlayerLongID) {
    std::string playerId = std::string(256, 'a');
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with special characters in the ID
TEST_F(GameTest, CreatePlayerSpecialCharsID) {
    std::string playerId = "player!@#$%^&*()";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a numeric ID
TEST_F(GameTest, CreatePlayerNumericID) {
    std::string playerId = "123456";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a mixed alphanumeric ID
TEST_F(GameTest, CreatePlayerAlphanumericID) {
    std::string playerId = "player123";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a whitespace ID
TEST_F(GameTest, CreatePlayerWhitespaceID) {
    std::string playerId = " ";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a tab character in the ID
TEST_F(GameTest, CreatePlayerTabID) {
    std::string playerId = "\t";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a newline character in the ID
TEST_F(GameTest, CreatePlayerNewlineID) {
    std::string playerId = "\n";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a carriage return character in the ID
TEST_F(GameTest, CreatePlayerCarriageReturnID) {
    std::string playerId = "\r";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a null character in the ID
TEST_F(GameTest, CreatePlayerNullID) {
    std::string playerId = "\0";
    bool result = game->create_player(playerId);

    EXPECT_FALSE(result);
    EXPECT_EQ(game->getPlayers().size(), 0);
}

// Test to verify the creation of a player with a very long ID
TEST_F(GameTest, CreatePlayerVeryLongID) {
    std::string playerId = std::string(1024, 'a');
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a negative ID
TEST_F(GameTest, CreatePlayerNegativeID) {
    std::string playerId = "-1";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a zero ID
TEST_F(GameTest, CreatePlayerZeroID) {
    std::string playerId = "0";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a floating-point ID
TEST_F(GameTest, CreatePlayerFloatingPointID) {
    std::string playerId = "1.23";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a hexadecimal ID
TEST_F(GameTest, CreatePlayerHexadecimalID) {
    std::string playerId = "0x1A";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with an octal ID
TEST_F(GameTest, CreatePlayerOctalID) {
    std::string playerId = "0123";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a binary ID
TEST_F(GameTest, CreatePlayerBinaryID) {
    std::string playerId = "0b1010";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a mixed case ID
TEST_F(GameTest, CreatePlayerMixedCaseID) {
    std::string playerId = "PlayerID";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a single character ID
TEST_F(GameTest, CreatePlayerSingleCharID) {
    std::string playerId = "a";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a double character ID
TEST_F(GameTest, CreatePlayerDoubleCharID) {
    std::string playerId = "aa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a triple character ID
TEST_F(GameTest, CreatePlayerTripleCharID) {
    std::string playerId = "aaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a quadruple character ID
TEST_F(GameTest, CreatePlayerQuadrupleCharID) {
    std::string playerId = "aaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a quintuple character ID
TEST_F(GameTest, CreatePlayerQuintupleCharID) {
    std::string playerId = "aaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a sextuple character ID
TEST_F(GameTest, CreatePlayerSextupleCharID) {
    std::string playerId = "aaaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a septuple character ID
TEST_F(GameTest, CreatePlayerSeptupleCharID) {
    std::string playerId = "aaaaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with an octuple character ID
TEST_F(GameTest, CreatePlayerOctupleCharID) {
    std::string playerId = "aaaaaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a nonuple character ID
TEST_F(GameTest, CreatePlayerNonupleCharID) {
    std::string playerId = "aaaaaaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a decuple character ID
TEST_F(GameTest, CreatePlayerDecupleCharID) {
    std::string playerId = "aaaaaaaaaa";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a mixed character ID
TEST_F(GameTest, CreatePlayerMixedCharID) {
    std::string playerId = "a1!@#";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}

// Test to verify the creation of a player with a mixed character and whitespace ID
TEST_F(GameTest, CreatePlayerMixedCharWhitespaceID) {
    std::string playerId = "a1 !@#";
    bool result = game->create_player(playerId);

    EXPECT_TRUE(result);
    EXPECT_EQ(game->getPlayers().size(), 1);
    EXPECT_EQ(game->getPlayers().at(0).get_id(), playerId);
}