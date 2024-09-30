/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Velocity
*/

#pragma once

class Velocity
{
public:
    Velocity();
    Velocity(int value);
    ~Velocity();

    void set_value(int value);

    int get_value();
private:
    int _value;
};
