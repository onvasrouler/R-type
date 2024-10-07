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

Rect::Rect(int l, int h)
{
    this->_l = l;
    this->_h = h;
}

Rect::~Rect()
{

}

void Rect::set_l(int l)
{
    this->_l = l;
}

void Rect::set_h(int h)
{
    this->_h = h;
}

int Rect::get_l() const
{
    return (this->_l);
}

int Rect::get_h() const
{
    return (this->_h);
}
