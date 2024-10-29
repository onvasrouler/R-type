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
#include "AEntities.hpp"

class EntitiesFactory {
public:
    EntitiesFactory(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr);
    ~EntitiesFactory() = default;

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);
    void setDebugLogger(std::shared_ptr<DebugLogger> debugLogger);

    void loadEntities(const std::string filename);

    std::shared_ptr<AEntities> createEntity(nlohmann::json_abi_v3_11_3::json entityData);

private:
    std::shared_ptr<JsonParser> _JsonParser; /**< Shared pointer to a JsonParser object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */

    nlohmann::json_abi_v3_11_3::json _EntitiesData;

    std::map<std::string, std::shared_ptr<AEntities>> _Entities;


};
