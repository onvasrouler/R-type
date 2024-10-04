/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/
 
#include "ACharacter.hpp"

ACharacter::ACharacter() : AEntity()
{
    this->_hp = std::make_shared<Hp>(1);
    this->_level = std::make_shared<Level>(1);
}


int ACharacter::get_hp()
{
    return (this->_hp->get_value());
}

int ACharacter::get_level()
{
    return (this->_level->get_value());
}

void ACharacter::set_hp(int hp)
{
    this->_hp->set_value(hp);
}

void ACharacter::set_level(int level)
{
    this->_level->set_value(level);
}
