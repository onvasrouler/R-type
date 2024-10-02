/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ATools
*/

#include "ATools.hpp"

ATools::ATools()
{
    this->_value = 0;
}

ATools::ATools(int value)
{
    this->_value = value;
}

void ATools::set_value(int value)
{
    this->_value = value;
}

int ATools::get_value()
{
    return (this->_value);
}
