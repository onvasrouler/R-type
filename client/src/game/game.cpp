/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** game
*/

#include "game.hpp"
#include <thread>

static int getThreadCount() {
    std::ifstream file("/proc/self/status");
    std::string line;
    while (std::getline(file, line)) {
        if (line.rfind("Threads:", 0) == 0) { // Cherche la ligne qui commence par "Threads:"
            return std::stoi(line.substr(8)); // Récupère le nombre de threads
        }
    }
    return -1; // Retourne -1 si l'information n'est pas trouvée
}

Game::Game(std::shared_ptr<JsonParser> jsonParser, std::shared_ptr<DebugLogger> debugLogger, const int windowWidth, const int windowHeight)
{
    _WindowWidth = windowWidth;
    _WindowHeight = windowHeight;
    _DataBuffer = "";
    _DebugLogger = debugLogger;
    _JsonParser = jsonParser;
    _EntitiesFactory = std::make_shared<EntitiesFactory>(jsonParser, debugLogger);
    _Running = false;
    _GameOver = false;
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
    if (_EntitiesFactory)
        _EntitiesFactory->loadEntities(ASSETS_FILE_PATH);
    else
        if (_DebugLogger)
            _DebugLogger->Log("EntitiesFactory not setted", 0);
    if (_DebugLogger)
        _DebugLogger->Log("Game is initialized", 2);
}

void Game::start()
{
    _Running = true;
    _ShutDown = false;
    if (_DebugLogger)
        _DebugLogger->Log("Game is running", 2);
}

void Game::update()
{
    _modifMutex.lock();
    for (auto& data : _modif) {
        if (data.find("202") != std::string::npos)
            std::cerr << "update: " << data << std::endl;
        if (!_Running) 
            return;
        if (_DebugLogger)
            _DebugLogger->Log("Game received data", 4);
        for (char c : data) {
           if (!isalnum(c) && c != '/' && c != '-' && c != '\n' && c != '\r') {
               if (_DebugLogger)
                   _DebugLogger->Log("Invalid character in data", 0);
               _modifMutex.unlock();
               return;
           }
        }
        if (data == "500\r\n") {
            _ShutDown = true;
            resetGame();
        }
        try {

            std::vector<std::string> tokens = splitter(data, '/');
            int maxThreads = std::thread::hardware_concurrency();
            int threadCount = getThreadCount();
            if (maxThreads < threadCount) {
                std::thread thread = std::thread(
                    [this, tokens](void* _) -> void* {
                        (void)_;
                        handleData(tokens);
                        return nullptr;
                    },
                    nullptr);
                    thread.detach();
            } else {
                handleData(tokens);
            }

        } catch (std::exception &e) {
            if (_DebugLogger)
                _DebugLogger->Log("Error while updating game", 0);
            _modifMutex.unlock();
        }
    }
    _modif.clear();
    _modifMutex.unlock();
}

void Game::handleData(std::vector<std::string> tokens)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is handling data", 4);

    try {
        std::string instruction = tokens[0];
        if (instruction == "202") {
            std::cerr << "handle 202" << std::endl;
        }
        std::string uuid = tokens[1];
    if (instruction == "01" || instruction == "200" || instruction == "201" )
        handlePlayer(uuid, tokens);
    else if (instruction == "210" || instruction == "211" ) 
        handleEnemy(uuid, tokens);
    else if (instruction == "220")
        handleBullet(uuid, tokens);

    if (instruction == "203" || instruction == "213" || instruction == "222")
        destroyEntity(tokens);
    
    if (instruction == "202" || instruction == "212" || instruction == "221") {
        if (_EntitiesList.find(uuid) != _EntitiesList.end()) {
            _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[2]), _WindowWidth);
            _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[3]), _WindowHeight);
        } else {
            #ifdef _WIN32
            #else
            if (uuid.length() != 36)
                return;
            #endif
            if (tokens[0] == "202")
                createPlayer(uuid);
            if (tokens[0] == "212")
                createEnemy(uuid);
            if (tokens[0] == "221")
                createBullet(uuid);
            _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[2]), _WindowWidth);
            _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[3]), _WindowHeight);
        }
    }
    } catch (std::exception &e) {
        if (_DebugLogger)
            _DebugLogger->Log("Error while handling data", 0);
    }
        
}

void Game::handlePlayer(std::string uuid, std::vector<std::string> tokens)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is handling player", 4);
    if (tokens[0] == "01") {
        createPlayer(uuid);
        _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[5]), _WindowWidth);
        _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[6]), _WindowHeight);
        _PlayerId = uuid;
    }
    if (tokens[0] == "200") {
        createPlayer(uuid);
        _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[5]), _WindowWidth);
        _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[6]), _WindowHeight);
    }
}

void Game::handleEnemy(std::string uuid, std::vector<std::string> tokens)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is handling enemy", 4);
    if (tokens[0] == "210") {
        createEnemy(uuid);
        _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[5]), _WindowWidth);
        _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[6]), _WindowHeight);
    }
}

void Game::handleBullet(std::string uuid, std::vector<std::string> tokens)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is handling bullet", 4);
    if (tokens[0] == "220") {
        createBullet(uuid);
        _EntitiesList[uuid]->setRelativePosX(std::stoi(tokens[2]), _WindowWidth);
        _EntitiesList[uuid]->setRelativePosY(std::stoi(tokens[3]), _WindowHeight);
    }
}

void Game::createPlayer(std::string UUID)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is creating player", 4);
    if (this->_EntitiesList.find(UUID) != this->_EntitiesList.end())
        return;
    else {
        _EntitiesList[UUID] = _EntitiesFactory->getEntity(EntityType::PLAYER);
    }
}

void Game::createEnemy(std::string UUID)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is creating enemy", 4);
    if (this->_EntitiesList.find(UUID) != this->_EntitiesList.end())
        return;
    else {
        _EntitiesList[UUID] = _EntitiesFactory->getEntity(EntityType::ENEMY);
    }
}

void Game::createBullet(std::string UUID)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is creating bullet", 4);
    if (this->_EntitiesList.find(UUID) != this->_EntitiesList.end())
        return;
    else {
        _EntitiesList[UUID] = _EntitiesFactory->getEntity(EntityType::BULLET);
    }
}

void Game::destroyEntity(std::vector<std::string> tokens)
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is destroying entity", 4);
    if (_EntitiesList.find(tokens[1]) != _EntitiesList.end()) {
        if(tokens[1] == _PlayerId) {
            _Running = false;
            _GameOver = true;
        }
        _EntitiesList.erase(tokens[1]);
    }
}

void Game::draw()
{

    
    if (!_Running && !_GameOver)
        return;

    if (_GameOver) {
        DrawText("Game Over", _WindowWidth / 2 - 50, _WindowHeight / 2 - 50, 20, RED);
        return;
    }

    for (const auto &entity : _EntitiesList)
        entity.second->draw();

    if (_DebugLogger)
        _DebugLogger->Log("Game is drawing", 4);
}

void Game::resetGame()
{
    if (_DebugLogger)
        _DebugLogger->Log("Game is resetting", 4);
    _Running = false;
    _GameOver = false;
    _EntitiesList.clear();
}

void Game::clearEntities()
{
    if (!_Running)
        return;
    if (_DebugLogger)
        _DebugLogger->Log("Game is clearing entities", 4);
    _EntitiesList.clear();
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
    (void)key;
    (void)pressedOrReleased;
}

std::shared_ptr<EntitiesFactory> Game::getEntitiesFactory() const
{
    return _EntitiesFactory;
}

bool Game::getShutDown()
{
    return _ShutDown;
}

bool Game::getGameOver()
{
    return _GameOver;
}