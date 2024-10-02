/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/
 
#include "ACharacter.hpp"

ACharacter::ACharacter(int x, int y, int l, int h, int type, int id, int hp, int level) : AEntity(x, y, l, h, type, id)
{
    this->_hp = std::make_unique<Hp>(hp);
    this->_level = std::make_unique<Level>(level);
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
