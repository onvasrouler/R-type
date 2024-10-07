/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ACharacter
*/

#pragma once
 
#include "AEntity.hpp"
#include "Level.hpp"
#include "Hp.hpp"

class ACharacter : public AEntity
{
public:
    ACharacter();
    virtual ~ACharacter() = default;

    virtual void move() = 0;

    void set_hp(int hp);
    void set_level(int level);

    int get_hp(void) const;
    int get_level(void) const;

protected:
    Hp _hp;
    Level _level;
};