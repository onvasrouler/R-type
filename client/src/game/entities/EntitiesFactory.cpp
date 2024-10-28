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

void EntitiesFactory::loadEntities()
{
}