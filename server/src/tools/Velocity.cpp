/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Velocity
*/

#include "Velocity.hpp"

Velocity::Velocity()
{
    this->_value = 0;
}

Velocity::Velocity(int value)
{
    this->_value = value;
}

Velocity::~Velocity()
{

}

void Velocity::set_value(int value)
{
    this->_value = value;
}

int Velocity::get_value()
{
    return (this->_value);
}
