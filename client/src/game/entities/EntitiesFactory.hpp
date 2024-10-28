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

class EntitiesFactory {
public:
    EntitiesFactory(std::shared_ptr<JsonParser> jsonParser = nullptr, std::shared_ptr<DebugLogger> debugLogger = nullptr);
    ~EntitiesFactory() = default;

    void setJsonParser(std::shared_ptr<JsonParser> jsonParser);
    void setDebugLogger(std::shared_ptr<DebugLogger> debugLogger);

    void loadEntities();

private:
    std::shared_ptr<JsonParser> _JsonParser; /**< Shared pointer to a JsonParser object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */

};
