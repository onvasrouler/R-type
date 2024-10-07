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


int ACharacter::get_hp()
{
    return (this->_hp.get_value());
}

int ACharacter::get_level()
{
    return (this->_level.get_value());
}

void ACharacter::set_hp(const int hp)
{
    this->_hp.set_value(hp);
}

void ACharacter::set_level(const int level)
{
    this->_level.set_value(level);
}
