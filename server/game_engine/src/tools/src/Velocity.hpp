/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Velocity
*/

#pragma once

#include "ATools.hpp"

class Velocity : public ATools
{
public:
    Velocity() = default;
    Velocity(const int value) : ATools(value) {}
    ~Velocity() = default;
};
