/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/

/**
 * @file AEntity.cpp
 * @brief Implementation of the AEntity class.
 */

#include "AEntity.hpp"
#include <string>

/**
 * @brief Construct a new AEntity object.
 * 
 * This constructor initializes the entity's ID and type.
 */
AEntity::AEntity()
{
    this->_id = Id();
    this->_type = Type(0);
}

/**
 * @brief Get the x-coordinate of the entity.
 * 
 * @return int The current x-coordinate of the entity.
 */
int AEntity::get_x() const
{
    return this->_origin.get_x();
}

/**
 * @brief Get the y-coordinate of the entity.
 * 
 * @return int The current y-coordinate of the entity.
 */
int AEntity::get_y() const
{
    return this->_origin.get_y();
}

/**
 * @brief Get the length (l) of the entity's dimension.
 * 
 * @return int The current length of the entity's dimension.
 */
int AEntity::get_l() const
{
    return this->_dimension.get_l();
}

/**
 * @brief Get the height (h) of the entity's dimension.
 * 
 * @return int The current height of the entity's dimension.
 */
int AEntity::get_h() const
{
    return this->_dimension.get_h();
}

/**
 * @brief Get the type of the entity.
 * 
 * @return int The current type of the entity.
 */
int AEntity::get_type()
{
    return this->_type.get_value();
}

/**
 * @brief Get the ID of the entity.
 * 
 * @return int The current ID of the entity.
 */
const std::string& AEntity::get_id() const
{
    return this->_id.get_value();
}

/**
 * @brief Set the x-coordinate of the entity.
 * 
 * @param x The new x-coordinate to be set.
 */
void AEntity::set_x(const int x)
{
    this->_origin.set_x(x);
}

/**
 * @brief Set the y-coordinate of the entity.
 * 
 * @param y The new y-coordinate to be set.
 */
void AEntity::set_y(const int y)
{
    this->_origin.set_y(y);
}

/**
 * @brief Set the length (l) of the entity's dimension.
 * 
 * @param l The new length to be set.
 */
void AEntity::set_l(const int l)
{
    this->_dimension.set_l(l);
}

/**
 * @brief Set the height (h) of the entity's dimension.
 * 
 * @param h The new height to be set.
 */
void AEntity::set_h(const int h)
{
    this->_dimension.set_h(h);
}

/**
 * @brief Set the type of the entity.
 * 
 * @param type The new type to be set.
 */
void AEntity::set_type(const int type)
{
    this->_type.set_value(type);
}