/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ITools
*/

#pragma once

class ITools
{
public:
    virtual ~ITools() = default;

    virtual void set_value(int value) = 0;

    virtual int get_value() const = 0;
};
