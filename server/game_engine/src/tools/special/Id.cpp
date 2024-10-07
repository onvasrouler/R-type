/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Point
*/

#include <Id.hpp>

int ID_nb = 0;

Id::Id()
{
    this->_value = ID_nb;
    ID_nb = ID_nb + 1;
}

int Id::get_value() const
{
    return (this->_value);
}
