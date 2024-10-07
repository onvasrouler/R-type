/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Point
*/

#include "Point.hpp"

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
}

Point::Point(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

Point::~Point()
{

}

void Point::set_x(int x)
{
    this->_x = x;
}

void Point::set_y(int y)
{
    this->_y = y;
}

int Point::get_x() const
{
    return (this->_x);
}

int Point::get_y() const
{
    return (this->_y);
}
