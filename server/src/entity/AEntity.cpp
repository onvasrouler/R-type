/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/
 
#include "AEntity.hpp"

AEntity::AEntity(int x, int y, int l, int h)
{
    this->_origin = std::make_unique<Point>(x, y);
    this->_dimension = std::make_unique<Rect>(l, h);
}


int AEntity::get_x()
{
    return (this->_origin->get_x());
}

int AEntity::get_y()
{
    return (this->_origin->get_y());
}

int AEntity::get_l()
{
    return (this->_dimension->get_l());
}

int AEntity::get_h()
{
    return (this->_dimension->get_h());
}


void AEntity::set_x(int x)
{
    this->_origin->set_x(x);
}

void AEntity::set_y(int y)
{
    this->_origin->set_y(y);
}

void AEntity::set_l(int l)
{
    this->_dimension->set_l(l);
}

void AEntity::set_h(int h)
{
    this->_dimension->set_h(h);
}
