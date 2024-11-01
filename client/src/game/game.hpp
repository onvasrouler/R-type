/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#pragma once

#include "entities/EntitiesFactory.hpp"

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
    void update(std::string data);
    void handleInput(int key, int pressedOrReleased);

    void draw();

    void stop();

    bool isRunning() const;

    std::shared_ptr<EntitiesFactory> getEntitiesFactory() const;

private:
    std::shared_ptr<EntitiesFactory> _EntitiesFactory; /**< Shared pointer to a EntitiesFactory object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */
    std::shared_ptr<JsonParser> _JsonParser; /**< Shared pointer to a JsonParser object. */
    bool _Running; /**< Boolean to check if the game is running. */

    int _WindowWidth; /**< The width of the window. */
    int _WindowHeight; /**< The height of the window. */

    std::string _DataBuffer;
};