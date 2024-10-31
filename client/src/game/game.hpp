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
    Game(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr);
    ~Game() = default;

    void setEntityFactoryJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void setServerInfos(const std::string ip, const std::string port);

    void initGame();

    void run();

    void stop();

    bool isRunning() const;
    std::shared_ptr<EntitiesFactory> getEntitiesFactory() const;

private:
    std::shared_ptr<EntitiesFactory> _EntitiesFactory; /**< Shared pointer to a EntitiesFactory object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */
    bool _Running; /**< Boolean to check if the game is running. */
};