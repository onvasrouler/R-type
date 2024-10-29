/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#include "game.hpp"

Game::Game(std::shared_ptr<JsonParser> jsonParser, std::shared_ptr<DebugLogger> debugLogger)
{
    _DebugLogger = debugLogger;
    _EntitiesFactory = std::make_shared<EntitiesFactory>(jsonParser, debugLogger);
    _Running = false;
}

void Game::setEntityFactoryJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _EntitiesFactory->setJsonParser(jsonParser);
}

void Game::setServerInfos(const std::string ip, const std::string port)
{
    _Ip = ip;
    _Port = port;
}

void Game::setPort(const std::string port)
{
    _Port = port;
}

void Game::setIp(const std::string ip)
{
    _Ip = ip;
}

void Game::initGame()
{
    _EntitiesFactory->loadEntities(ASSETS_FILE_PATH);
    _DebugLogger->Log("Game is initialized", 2);
}

void Game::run()
{
    _Running = true;
    _DebugLogger->Log("Game is running", 2);
}

void Game::stop()
{
    _Running = false;
    _DebugLogger->Log("Game is stopped", 2);
}

bool Game::isRunning() const
{
    return _Running;
}

std::shared_ptr<EntitiesFactory> Game::getEntitiesFactory() const
{
    return _EntitiesFactory;
}

std::string Game::getIp() const
{
    return _Ip;
}

std::string Game::getPort() const
{
    return _Port;
}
