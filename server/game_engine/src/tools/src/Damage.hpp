/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Damage
*/

#pragma once

#include "ATools.hpp"

class Damage : public ATools
{
public:
    Damage() = default;
    Damage(const int value) : ATools(value) {}
    ~Damage() = default;
};
