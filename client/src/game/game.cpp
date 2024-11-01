/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#include "game.hpp"

Game::Game(std::shared_ptr<JsonParser> jsonParser, std::shared_ptr<DebugLogger> debugLogger, const int windowWidth, const int windowHeight)
{
    _WindowWidth = windowWidth;
    _WindowHeight = windowHeight;
    _DataBuffer = "";
    _DebugLogger = debugLogger;
    _JsonParser = jsonParser;
    _EntitiesFactory = std::make_shared<EntitiesFactory>(jsonParser, debugLogger);
    _Running = false;
}

void Game::setEntityFactoryJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _EntitiesFactory->setJsonParser(jsonParser);
}

void Game::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    _DebugLogger = debugLogger;
    _EntitiesFactory->setDebugLogger(debugLogger);
}

void Game::setWindowWidth(const int width)
{
    _WindowWidth = width;
}

void Game::setWindowHeight(const int height)
{
    _WindowHeight = height;
}

void Game::setWindowSize(const int width, const int height)
{
    this->setWindowWidth(width);
    this->setWindowHeight(height);
}

void Game::initGame()
{
    _EntitiesFactory->loadEntities(ASSETS_FILE_PATH);
    if (_DebugLogger)
        _DebugLogger->Log("Game is initialized", 2);
}

void Game::start()
{
    _Running = true;
    if (_DebugLogger)
        _DebugLogger->Log("Game is running", 2);
}

void Game::update(std::string data)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game received data", 4);
    _DataBuffer = data;
}

void Game::draw()
{
    if (!_Running)
        return;

    // Assuming you have a method to draw text on the screen
    // and a method to get the screen dimensions

    std::string text = "server send " + _DataBuffer;
    int fontsize = 20;
    // Calculate the position to center the text
    int textWidth = text.length() * fontsize;
    int x = (_WindowWidth - textWidth) / 2;
    int y = (_WindowHeight - fontsize) / 2;

    DrawText(text.c_str(), x, y, fontsize, BLACK);

    if (_DebugLogger)
        _DebugLogger->Log("Game is drawing", 4);
}

void Game::stop()
{
    _Running = false;
    if (_DebugLogger)
        _DebugLogger->Log("Game is stopped", 2);
}

bool Game::isRunning() const
{
    return _Running;
}

void Game::handleInput(int key, int pressedOrReleased)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is handling input", 4);
    std::cout << "key : " << key << " pressedOrReleased : " << (pressedOrReleased == 0 ? "released" : "pressed") << std::endl;
}

std::shared_ptr<EntitiesFactory> Game::getEntitiesFactory() const
{
    return _EntitiesFactory;
}
