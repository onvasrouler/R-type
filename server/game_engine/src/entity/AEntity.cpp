/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/
 
#include "AEntity.hpp"

AEntity::AEntity()
{
    this->_id = Id();
    this->_type = Type(0);
}

int AEntity::get_x()
{
    return this->_origin.get_x();
}

int AEntity::get_y()
{
    return this->_origin.get_y();
}

int AEntity::get_l()
{
    return this->_dimension.get_l();
}

int AEntity::get_h()
{
    return this->_dimension.get_h();
}

int AEntity::get_type()
{
    return this->_type.get_value();
}

int AEntity::get_id()
{
    return this->_id.get_value();
}


void AEntity::set_x(const int x)
{
    this->_origin.set_x(x);
}

void AEntity::set_y(const int y)
{
    this->_origin.set_y(y);
}

void AEntity::set_l(const int l)
{
    this->_dimension.set_l(l);
}

void AEntity::set_h(const int h)
{
    this->_dimension.set_h(h);
}

void AEntity::set_type(const int type)
{
    this->_dimension.set_h(type);
}