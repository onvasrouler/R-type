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
    ACharacter(int x, int y, int l, int h, int type, int id, int hp, int level);
    virtual ~ACharacter() = default;

    virtual void move_entity() = 0;

    void set_hp(int hp);
    void set_level(int level);

    int get_hp(void);
    int get_level(void);

protected:
    std::unique_ptr<Hp> _hp;
    std::unique_ptr<Level> _level;
};