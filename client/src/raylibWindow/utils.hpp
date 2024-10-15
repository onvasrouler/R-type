/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** utils
*/

#pragma once

void CustomLog(int msgType, const char *text, va_list args);
bool HealthCheck();
bool isIpValid(std::string ip);
bool isPortValid(std::string port);

class DebugLogger {
    public:
    DebugLogger(const bool active = false, const int depth = 0);
    ~DebugLogger() = default;

    void Log(const std::string &msg, const int depth = 0);

    void SetActive(const bool active);
    void SetLogDepth(const int depth);

    bool GetActive() const;
    int GetLogDepth() const;
    private:
    bool _Active;
    int _LogDepth;
};
