/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/

/**
 * @file AEntity.hpp
 * @brief Declaration of the AEntity class.
 */

#pragma once

#include "IEntity.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "Id.hpp"
#include "Type.hpp"

/**
 * @class AEntity
 * @brief Abstract base class for all entities in the game.
 * 
 * The AEntity class provides common attributes and methods for all entities,
 * such as position, dimensions, ID, and type. It inherits from the IEntity interface.
 */
class AEntity : public IEntity
{
public:
    /**
     * @brief Construct a new AEntity object.
     * 
     * This constructor initializes the entity's ID and type.
     */
    AEntity();

    /**
     * @brief Default virtual destructor for AEntity.
     */
    virtual ~AEntity() = default;

    /**
     * @brief Pure virtual function to move the entity.
     * 
     * This function must be implemented by derived classes to define how the entity moves.
     */
    virtual void move() = 0;

    /**
     * @brief Set the length (l) of the entity's dimension.
     * 
     * @param l The new length to be set.
     */
    void set_l(const int l);

    /**
     * @brief Set the height (h) of the entity's dimension.
     * 
     * @param h The new height to be set.
     */
    void set_h(const int h);

    /**
     * @brief Set the x-coordinate of the entity.
     * 
     * @param x The new x-coordinate to be set.
     */
    void set_x(const int x);

    /**
     * @brief Set the y-coordinate of the entity.
     * 
     * @param y The new y-coordinate to be set.
     */
    void set_y(const int y);

    /**
     * @brief Set the type of the entity.
     * 
     * @param type The new type to be set.
     */
    void set_type(const int type);

    /**
     * @brief Get the x-coordinate of the entity.
     * 
     * @return int The current x-coordinate of the entity.
     */
    int get_x(void);

    /**
     * @brief Get the y-coordinate of the entity.
     * 
     * @return int The current y-coordinate of the entity.
     */
    int get_y(void);

    /**
     * @brief Get the length (l) of the entity's dimension.
     * 
     * @return int The current length of the entity's dimension.
     */
    int get_l(void);

    /**
     * @brief Get the height (h) of the entity's dimension.
     * 
     * @return int The current height of the entity's dimension.
     */
    int get_h(void);

    /**
     * @brief Get the ID of the entity.
     * 
     * @return int The current ID of the entity.
     */
    int get_id(void);

    /**
     * @brief Get the type of the entity.
     * 
     * @return int The current type of the entity.
     */
    int get_type(void);

protected:
    Point _origin; ///< The origin point (position) of the entity.
    Rect _dimension; ///< The dimensions (length and height) of the entity.
    Id _id; ///< The unique identifier of the entity.
    Type _type; ///< The type of the entity.
};