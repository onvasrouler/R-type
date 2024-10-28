/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#pragma once
#include "entities/EntitiesFactory.hpp"

class Game {
public:
    Game(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr);
    ~Game() = default;

    void setEntityFactoryJsonParser(std::shared_ptr<JsonParser> jsonParser);

    void setServerInfos(const std::string ip, const std::string port);
    void setPort(const std::string port);
    void setIp(const std::string ip);

    void run();

    void stop();

    bool isRunning() const;
    std::shared_ptr<EntitiesFactory> getEntitiesFactory() const;
    std::string getIp() const;
    std::string getPort() const;

private:
    std::shared_ptr<EntitiesFactory> _EntitiesFactory; /**< Shared pointer to a EntitiesFactory object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */
    bool _Running; /**< Boolean to check if the game is running. */

    std::string _Ip;
    std::string _Port;
};