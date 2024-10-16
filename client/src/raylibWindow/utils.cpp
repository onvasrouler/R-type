/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** utils
*/

#include "../include.hpp"

void CustomLog(int msgType, const char *text, va_list args)
{
    char timeStr[64] = { 0 };
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("[%s] ", timeStr);

    switch (msgType)
    {
        case LOG_INFO: printf("[INFO] : "); break;
        case LOG_ERROR: printf("[ERROR]: "); break;
        case LOG_WARNING: printf("[WARN] : "); break;
        case LOG_DEBUG: printf("[DEBUG]: "); break;
        default: break;
    }

    vprintf(text, args);
    printf("\n");
}

bool HealthCheck()
{
    bool settingsFile = std::filesystem::exists("./config/window_settings.json");
    bool menuFile = std::filesystem::exists("./config/menu_settings.json");
    if (!settingsFile)
        std::cerr << "settings.json not found" << std::endl;
    if (!menuFile)
        std::cerr << "menu_settings.json not found" << std::endl;
    return settingsFile && menuFile;
}

bool isIpValid(const std::string ip)
{
    std::regex ipPattern("^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}$");
    return std::regex_match(ip, ipPattern);
}

bool isPortValid(const std::string port)
{
    std::regex portPattern("^[0-9]{1,5}$");
    return std::regex_match(port, portPattern);
}

DebugLogger::DebugLogger(const bool active, const int depth)
{
    this->_Active = active;
    this->_LogDepth = depth;
}

void DebugLogger::Log(const std::string &msg, const int depth)
{
    if (this->_Active && depth <= this->_LogDepth)
        std::cout << "Logger : " << msg << std::endl;
}

void DebugLogger::SetActive(const bool active)
{
    std::cout << "Logger : Active set to " << active << std::endl;
    this->_Active = active;
}

void DebugLogger::SetLogDepth(const int depth)
{
    std::cout << "Logger : Log depth set to " << depth << std::endl;
    this->_LogDepth = depth;
}

bool DebugLogger::GetActive() const
{
    return this->_Active;
}

int DebugLogger::GetLogDepth() const
{
    return this->_LogDepth;
}
