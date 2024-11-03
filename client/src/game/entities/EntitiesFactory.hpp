/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** EntitiesFactory
*/

#pragma once

#include <memory>

#include "../../jsonParser/jsonParser.hpp"
#include "../../raylibWindow/utils.hpp"
#include "Entities.hpp"

enum class EntityType {
    DEFAULTENT,
    PLAYER,
    ENEMY,
    BULLET
};

class EntitiesFactory {
public:
    EntitiesFactory(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr);
    ~EntitiesFactory() = default;

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);
    void setDebugLogger(std::shared_ptr<DebugLogger> debugLogger);

    void loadEntities(const std::string filename);

    std::shared_ptr<Entities> createEntity(nlohmann::json_abi_v3_11_3::json entityData);

    std::shared_ptr<Entities> getEntity(EntityType type);

private:
    std::shared_ptr<JsonParser> _JsonParser; /**< Shared pointer to a JsonParser object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */

    nlohmann::json_abi_v3_11_3::json _EntitiesData;

    std::map<int, std::shared_ptr<Entities>> _Entities;


};
