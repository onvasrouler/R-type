/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ACharacter
*/

/**
 * @file ACharacter.cpp
 * @brief Implementation of the ACharacter class.
 */

#include "ACharacter.hpp"

/**
 * @brief Construct a new ACharacter object.
 * 
 * This constructor initializes the character's health points (HP) and level.
 */
ACharacter::ACharacter(const uuid &id) : AEntity(id)
{
    this->_hp = Hp(BASIC_LIFE_VALUE);
    this->_level = Level(BASIC_LEVEL_VALUE);
}

/**
 * @brief Get the health points (HP) of the character.
 * 
 * @return int The current health points of the character.
 */
int ACharacter::get_hp()
{
    return this->_hp.get_value();
}

/**
 * @brief Get the level of the character.
 * 
 * @return int The current level of the character.
 */
int ACharacter::get_level()
{
    return this->_level.get_value();
}

/**
 * @brief Set the health points (HP) of the character.
 * 
 * @param hp The new health points to be set.
 */
void ACharacter::set_hp(const int hp)
{
    this->_hp.set_value(hp);
}

/**
 * @brief Set the level of the character.
 * 
 * @param level The new level to be set.
 */
void ACharacter::set_level(const int level)
{
    this->_level.set_value(level);
}
