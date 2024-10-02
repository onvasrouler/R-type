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

void JsonParser::eraseCache(const std::string &filename)
{
    if (_jsons.find(filename) != _jsons.end())
        _jsons.erase(filename);
}

bool JsonParser::fileHasChanged(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    nlohmann::json currentJson;
    file >> currentJson;
    file.close();

    if (_jsons.find(filename) == _jsons.end())
        return true;

    return _jsons[filename] != currentJson;
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

