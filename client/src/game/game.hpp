/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#pragma once

#include "entities/EntitiesFactory.hpp"
#include <mutex>

#define ASSETS_FILE_PATH "./assets/assets_settings.json"

class Game {
public:
    Game(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr, const int windowWidth = 800, const int windowHeight = 600);
    ~Game() = default;

    void setEntityFactoryJsonParser(std::shared_ptr<JsonParser> jsonParser);
    void setDebugLogger(std::shared_ptr<DebugLogger> debugLogger);

    void setWindowWidth(const int width);
    void setWindowHeight(const int height);
    void setWindowSize(const int width, const int height);

    void initGame();
    void start();
    void update();
    void handleData(std::vector<std::string> tokens);

    void handlePlayer(std::string UUID, std::vector<std::string> tokens);
    void handleEnemy(std::string UUID, std::vector<std::string> tokens);
    void handleBullet(std::string UUID, std::vector<std::string> tokens);

    void createPlayer(std::string UUID);
    void createEnemy(std::string UUID);
    void createBullet(std::string UUID);

    void destroyEntity(std::vector<std::string> tokens);

    void handleInput(int key, int pressedOrReleased);

    void draw();
    void clearEntities();
    void stop();

    void resetGame();

    bool isRunning() const;

    std::shared_ptr<EntitiesFactory> getEntitiesFactory() const;

    bool getShutDown();
    bool getGameOver();

    std::vector<std::string> _modif;
    std::mutex _modifMutex;

private:
    std::shared_ptr<EntitiesFactory> _EntitiesFactory; /**< Shared pointer to a EntitiesFactory object. */
    std::map<std::string, std::shared_ptr<Entities>> _EntitiesList; /**< Map of menu types to AEntities objects. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */
    std::shared_ptr<JsonParser> _JsonParser; /**< Shared pointer to a JsonParser object. */
    bool _Running; /**< Boolean to check if the game is running. */

    bool _GameOver;
    bool _ShutDown;

    int _WindowWidth; /**< The width of the window. */
    int _WindowHeight; /**< The height of the window. */

    std::string _PlayerId;

    std::string _DataBuffer;
};