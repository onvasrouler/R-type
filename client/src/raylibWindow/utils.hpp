/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** utils
*/

#pragma once

#include <string>
#include <ctime>
#include <ostream>
#include <iostream>
#include <regex>
#include <raylib.h>
#include <filesystem>

/**
 * @brief cleaner way to log messaged of raylib by
 * adding the date and time + the type of the message
 */
void CustomLog(int msgType, const char *text, va_list args);

/**
 * @brief Check if the config files are present
 * 
 * @return true if the files are present
 * @return false if the files are not present
 */
bool HealthCheck();

/**
 * @brief Check if the ip is valid
 * 
 * @param ip the ip to check
 * @return true if the ip is valid
 * @return false if the ip is not valid
 */
bool isIpValid(const std::string ip);

/**
 * @brief Check if the port is valid
 * 
 * @param port the port to check
 * @return true if the port is valid
 * @return false if the port is not valid
 */
bool isPortValid(const std::string port);

/**
 * @brief Split a string into tokens
 * 
 * @param str the string to split
 * @param delimiter the delimiter to split the string with
 * @param tokens the tokens to store the splitted string
 * @return std::vector<std::string> the splitted string
 */
std::vector<std::string> splitter(const std::string str, char delimiter);

/**
 * @class DebugLogger
 * @brief A class for logging debug messages with optional depth control.
 * 
 * This class provides functionality to log debug messages with an optional
 * depth parameter to control the importance wanted of the logs going from the
 * most important 0 to the less 5. It also allows enabling or
 * disabling the logging functionality.
 */
class DebugLogger {
    public:
    /**
     * @brief Constructs a DebugLogger object.
     * 
     * @param active A boolean indicating whether logging is active.
     * @param depth An integer specifying the initial log depth.
     */
    DebugLogger(const bool active = false, const int depth = 0);

    /**
     * @brief Destructs a DebugLogger object.
     *  
     * The destructor is the default destructor for the DebugLogger class.
     * It does not perform any specific operations.
     */
    ~DebugLogger() = default;

    /**
     * @brief Logs a message with an optional depth.
     * 
     * @param msg The message to log.
     * @param depth An integer specifying the depth of the log message.
     */
    void Log(const std::string &msg, const int depth = 0);

    /**
     * @brief Sets the active state of the logger.
     * 
     * @param active A boolean indicating whether logging should be active.
     */
    void SetActive(const bool active);

    /**
     * @brief Sets the log depth.
     * 
     * @param depth An integer specifying the new log depth.
     */
    void SetLogDepth(const int depth);

    /**
     * @brief Gets the active state of the logger.
     * 
     * @return A boolean indicating whether logging is active.
     */
    bool GetActive() const;

    /**
     * @brief Gets the current log depth.
     * 
     * @return An integer representing the current log depth.
     */
    int GetLogDepth() const;
private:
    bool _Active; /**< A boolean indicating whether logging is active. */
    int _LogDepth; /**< An integer specifying the current log depth. */
};
