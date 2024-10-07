/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ATools
*/

#pragma once

#include "ITools.hpp"

class ATools : public ITools
{
public:
    ATools();
    ATools(const int value);
    virtual ~ATools() = default;

    void set_value(const int value);

    int get_value();
protected:
    int _value;
};
