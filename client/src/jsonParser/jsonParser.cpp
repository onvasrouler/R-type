/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** jsonParser
*/

#include "jsonParser.hpp"

nlohmann::json JsonParser::parseFile(const std::string &filename)
{
    nlohmann::json json;

    if (_jsons.find(filename) != _jsons.end())
        return _jsons[filename];
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    file >> json;
    _jsons[filename] = json;
    file.close();
    return json;
}

void JsonParser::eraseCache(const std::string &filename)
{
    if (this->_jsons.find(filename) != this->_jsons.end())
        this->_jsons.erase(filename);
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
    return this->_jsons[filename] != currentJson;
}

void JsonParser::writeFile(const std::string &filename, nlohmann::json &json)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    file << json;
    this->_jsons[filename] = json;
    file.close();
}

void JsonParser::writePrettyFile(const std::string &filename, nlohmann::json &json)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    file << std::setw(4) << json;
    this->_jsons[filename] = json;
    file.close();
}

void JsonParser::writePrettyFile(const std::string &filename, nlohmann::json &json, int indent)
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    file << std::setw(indent) << json;
    this->_jsons[filename] = json;
    file.close();
}
