/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/
 
#include "ACharacter.hpp"

ACharacter::ACharacter() : AEntity()
{
    this->_hp = Hp(1);
    this->_level = Level(1);
}


int ACharacter::get_hp() const
{
    return (this->_hp.get_value());
}

int ACharacter::get_level() const
{
    return (this->_level.get_value());
}

void ACharacter::set_hp(int hp)
{
    this->_hp.set_value(hp);
}

void ACharacter::set_level(int level)
{
    this->_level.set_value(level);
}
