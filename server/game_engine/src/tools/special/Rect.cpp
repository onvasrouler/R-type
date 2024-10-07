/*
** EPITECH PROJECT, 2024
** R-Thpe
** File description:
** Rect
*/

#include "Rect.hpp"

Rect::Rect()
{
    this->_l = 0;
    this->_h = 0;
}

Rect::Rect(const int l, const int h)
{
    this->_l = l;
    this->_h = h;
}

void Rect::set_l(const int l)
{
    this->_l = l;
}

void Rect::set_h(const int h)
{
    this->_h = h;
}

int Rect::get_l()
{
    return this->_l;
}

int Rect::get_h()
{
    return this->_h;
}
