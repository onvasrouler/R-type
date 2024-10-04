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

    int get_hp(void);
    int get_level(void);

protected:
    std::shared_ptr<Hp> _hp;
    std::shared_ptr<Level> _level;
};