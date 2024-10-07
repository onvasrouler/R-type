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

int AEntity::get_x() const
{
    return (this->_origin.get_x());
}

int AEntity::get_y() const
{
    return (this->_origin.get_y());
}

int AEntity::get_l() const
{
    return (this->_dimension.get_l());
}

int AEntity::get_h() const
{
    return (this->_dimension.get_h());
}

int AEntity::get_type() const
{
    return (this->_type.get_value());
}

int AEntity::get_id() const
{
    return (this->_id.get_value());
}


void AEntity::set_x(int x)
{
    this->_origin.set_x(x);
}

void AEntity::set_y(int y)
{
    this->_origin.set_y(y);
}

void AEntity::set_l(int l)
{
    this->_dimension.set_l(l);
}

void AEntity::set_h(int h)
{
    this->_dimension.set_h(h);
}

void AEntity::set_type(int type)
{
    this->_dimension.set_h(type);
}
