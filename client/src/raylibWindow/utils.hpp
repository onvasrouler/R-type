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