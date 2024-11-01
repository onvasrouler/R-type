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
                _Entities[std::stoi(entity["id"].get<std::string>())] = createEntity(entity);
    } else if (_DebugLogger)
            _DebugLogger->Log("JsonParser not setted", 0);
        else
            std::cerr << "JsonParser not setted" << std::endl;
}

std::shared_ptr<Entities> EntitiesFactory::createEntity(nlohmann::json entityData)
{
    std::shared_ptr<Entities> entity = std::make_shared<Entities>();

    // entity->setPos(Vector2{entityData["pos"]["x"], entityData["pos"]["y"]});
    // entity->setSpeed(Vector2{entityData["speed"]["x"], entityData["speed"]["y"]});
    // entity->setHealth(entityData["health"]);
    // entity->setDamage(entityData["damage"]);
    // entity->setAlive(entityData["alive"]);
    std::string texturePath = entityData["sprite"].get<std::string>();

    entity->setTexturePath(texturePath);
    entity->setImage(LoadImage(texturePath.c_str()));
    entity->setTexture(LoadTextureFromImage(entity->getImage()));
    // entity->setSize(Vector2{entityData["size"]["x"], entityData["size"]["y"]});
    // entity->setScale(entityData["scale"]);
    // entity->setRotation(entityData["rotation"]);
    entity->setId(entityData["id"].get<std::string>());
    return entity;
}

std::shared_ptr<Entities> EntitiesFactory::getEntity(EntityType type)
{
   int entityType = static_cast<int>(type);
   std::shared_ptr<Entities> newEntity = std::make_shared<Entities>();
   newEntity->setTexturePath(_Entities[entityType]->getTexturePath());
    newEntity->setImage(_Entities[entityType]->getImage());
    newEntity->setTexture(_Entities[entityType]->getTexture());
    newEntity->setId(_Entities[entityType]->getId());
    return newEntity;
}
