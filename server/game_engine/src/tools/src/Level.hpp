/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Level
*/

#pragma once

#include "ATools.hpp"

class Level : public ATools
{
public:
    Level() = default;
    Level(const int value) : ATools(value) {}
    ~Level() = default;
};
