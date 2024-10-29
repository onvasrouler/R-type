/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** EntitiesFactory
*/

#include "EntitiesFactory.hpp"

EntitiesFactory::EntitiesFactory(std::shared_ptr<JsonParser> jsonParser, std::shared_ptr<DebugLogger> debugLogger)
{
    _JsonParser = jsonParser;
    _DebugLogger = debugLogger;
    if (_DebugLogger)
        _DebugLogger->Log("EntitiesFactory created", 1);
}

void EntitiesFactory::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    _JsonParser = jsonParser;
}

void EntitiesFactory::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    _DebugLogger = debugLogger;
}

void EntitiesFactory::loadEntities(const std::string filename)
{
    if (_JsonParser) {
        _EntitiesData = _JsonParser->parseFile(filename);
        if (_EntitiesData.contains("entities"))
            for (auto &entity : _EntitiesData["entities"])
                _Entities[entity["id"]] = createEntity(entity);
    } else if (_DebugLogger)
        _DebugLogger->Log("JsonParser not setted", 0);
    else
        std::cerr << "JsonParser not setted" << std::endl;

    std::cout << "created nb of entities : " << _Entities.size() << std::endl;

    for (auto &entity : _Entities)
        std::cout << entity.first << std::endl;
}

std::shared_ptr<AEntities> EntitiesFactory::createEntity(nlohmann::json entityData)
{
    std::shared_ptr<AEntities> entity = std::make_shared<AEntities>();

    // entity->setPos(Vector2{entityData["pos"]["x"], entityData["pos"]["y"]});
    // entity->setSpeed(Vector2{entityData["speed"]["x"], entityData["speed"]["y"]});
    // entity->setHealth(entityData["health"]);
    // entity->setDamage(entityData["damage"]);
    // entity->setAlive(entityData["alive"]);
    std::string texturePath = entityData["sprite"].get<std::string>();

    entity->setTexturePath(texturePath);
    entity->setTexture(LoadTexture(texturePath.c_str()));
    // entity->setSize(Vector2{entityData["size"]["x"], entityData["size"]["y"]});
    // entity->setScale(entityData["scale"]);
    // entity->setRotation(entityData["rotation"]);
    entity->setId(entityData["id"].get<std::string>());
    return entity;
}