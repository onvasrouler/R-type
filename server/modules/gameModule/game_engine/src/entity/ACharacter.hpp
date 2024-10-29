/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ACharacter
*/

/**
 * @file ACharacter.hpp
 * @brief Declaration of the ACharacter class.
 */

#pragma once

#include "AEntity.hpp"
#include "../tools/src/Level.hpp"
#include "../tools/src/Hp.hpp"

#define BASIC_LIFE_VALUE 1
#define BASIC_LEVEL_VALUE 1

/**
 * @class ACharacter
 * @brief Abstract base class for character entities in the game.
 * 
 * The ACharacter class inherits from AEntity and adds specific attributes and methods
 * related to characters, such as health points (HP) and level.
 */
class ACharacter : public AEntity
{
public:
    /**
     * @brief Construct a new ACharacter object.
     * 
     * This constructor initializes the character's health points (HP) and level.
     */
    ACharacter(const std::string &id);

    /**
     * @brief Default virtual destructor for ACharacter.
     */
    virtual ~ACharacter() = default;

    /**
     * @brief Pure virtual function to move the character.
     * 
     * This function must be implemented by derived classes to define how the character moves.
     */
    virtual void move() = 0;

    /**
     * @brief Set the health points (HP) of the character.
     * 
     * @param hp The new health points to be set.
     */
    void set_hp(const int hp);

    /**
     * @brief Set the level of the character.
     * 
     * @param level The new level to be set.
     */
    void set_level(const int level);

    /**
     * @brief Get the health points (HP) of the character.
     * 
     * @return int The current health points of the character.
     */
    int get_hp(void);

    /**
     * @brief Get the level of the character.
     * 
     * @return int The current level of the character.
     */
    int get_level(void);

protected:
    Hp _hp; ///< The health points of the character.
    Level _level; ///< The level of the character.
};