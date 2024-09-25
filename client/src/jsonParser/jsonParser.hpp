/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** jsonParser
*/

#pragma once

#include "../include.hpp"

class JsonParser {
    public:
        JsonParser() = default;
        ~JsonParser() = default;

        nlohmann::json parseFile(const std::string &filename);
        void writeFile(const std::string &filename, nlohmann::json &json);
        void writePrettyFile(const std::string &filename, nlohmann::json &json);
        void writePrettyFile(const std::string &filename, nlohmann::json &json, int indent);
        
    private:
        std::map<std::string, nlohmann::json> _jsons;
};