/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** jsonParser
*/

#include "jsonParser.hpp"

nlohmann::json JsonParser::parseFile(const std::string &filename)
{
    // If the file has already been parsed, return the json
    if (_jsons.find(filename) != _jsons.end())
        return _jsons[filename];

    std::ifstream file(filename);
    nlohmann::json json;

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    file >> json;
    // cache the json to avoid parsing the file again
    _jsons[filename] = json;
    file.close();
    return json;
}

void JsonParser::writeFile(const std::string &filename, nlohmann::json &json)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    file << json;
    _jsons[filename] = json;
    file.close();
}

void JsonParser::writePrettyFile(const std::string &filename, nlohmann::json &json)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    file << std::setw(4) << json;
    _jsons[filename] = json;
    file.close();
}

void JsonParser::writePrettyFile(const std::string &filename, nlohmann::json &json, int indent)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    file << std::setw(indent) << json;
    _jsons[filename] = json;
    file.close();
}

