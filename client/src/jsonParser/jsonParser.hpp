/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** jsonParser
*/

#pragma once

#include "../include.hpp"

/**
 * @class JsonParser
 * @brief A class for parsing and managing JSON files.
 * 
 * The JsonParser class provides methods to parse JSON files, manage a cache of parsed JSON objects,
 * check if a file has changed, and write JSON data to files.
 */
class JsonParser {
    public:
    /**
     * @brief Default constructor for JsonParser.
     */
    JsonParser() = default;

    /**
     * @brief Default destructor for JsonParser.
     */
    ~JsonParser() = default;

    /**
     * @brief Parses a JSON file, cache it to avoid reloading it
     * and returns the parsed JSON object.
     * 
     * @param filename The path to the JSON file to be parsed.
     * @return nlohmann::json The parsed JSON object.
     */
    nlohmann::json parseFile(const std::string &filename);

    /**
     * @brief Erases the cached JSON object for a given file.
     * 
     * @param filename The path to the JSON file whose cache should be erased.
     */
    void eraseCache(const std::string &filename);

    /**
     * @brief Checks if a JSON file has changed since it was last parsed.
     * 
     * @param filename The path to the JSON file to be checked.
     * @return bool True if the file has changed, false otherwise.
     */
    bool fileHasChanged(const std::string &filename);

    /**
     * @brief Writes a JSON object to a file.
     * 
     * @param filename The path to the file where the JSON object should be written.
     * @param json The JSON object to be written to the file.
     */
    void writeFile(const std::string &filename, nlohmann::json &json);

    /**
     * @brief Writes a JSON object to a file with pretty formatting.
     * 
     * @param filename The path to the file where the JSON object should be written.
     * @param json The JSON object to be written to the file.
     */
    void writePrettyFile(const std::string &filename, nlohmann::json &json);

    /**
     * @brief Writes a JSON object to a file with pretty formatting and a specified indentation level.
     * 
     * @param filename The path to the file where the JSON object should be written.
     * @param json The JSON object to be written to the file.
     * @param indent The number of spaces to use for indentation in the pretty formatting.
     */
    void writePrettyFile(const std::string &filename, nlohmann::json &json, int indent);
    
private:
    /**
     * @brief A map to store cached JSON objects, keyed by file path.
     */
    std::map<std::string, nlohmann::json> _jsons;        
};
