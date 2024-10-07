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

    void set_hp(const int hp);
    void set_level(const int level);

    int get_hp(void);
    int get_level(void);

protected:
    Hp _hp;
    Level _level;
};