/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/

/**
 * @file IEntity.hpp
 * @brief Declaration of the IEntity interface.
 */

#pragma once

#include <memory>

/**
 * @class IEntity
 * @brief Interface for all entities in the game.
 * 
 * The IEntity interface defines the basic operations that all entities in the game must implement.
 * This includes methods for movement, setting and getting dimensions, coordinates, type, and ID.
 */
class IEntity
{
public:
   /**
    * @brief Virtual destructor for IEntity.
    * 
    * Ensures derived class destructors are called properly.
    */
   virtual ~IEntity() = default;

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
   virtual void set_l(const int l) = 0;

   /**
    * @brief Set the height (h) of the entity's dimension.
    * 
    * @param h The new height to be set.
    */
   virtual void set_h(const int h) = 0;

   /**
    * @brief Set the x-coordinate of the entity.
    * 
    * @param x The new x-coordinate to be set.
    */
   virtual void set_x(const int x) = 0;

   /**
    * @brief Set the y-coordinate of the entity.
    * 
    * @param y The new y-coordinate to be set.
    */
   virtual void set_y(const int y) = 0;

   /**
    * @brief Set the type of the entity.
    * 
    * @param type The new type to be set.
    */
   virtual void set_type(const int type) = 0;

   /**
    * @brief Get the x-coordinate of the entity.
    * 
    * @return int The current x-coordinate of the entity.
    */
   virtual int get_x(void) = 0;

   /**
    * @brief Get the y-coordinate of the entity.
    * 
    * @return int The current y-coordinate of the entity.
    */
   virtual int get_y(void) = 0;

   /**
    * @brief Get the length (l) of the entity's dimension.
    * 
    * @return int The current length of the entity's dimension.
    */
   virtual int get_l(void) = 0;

   /**
    * @brief Get the height (h) of the entity's dimension.
    * 
    * @return int The current height of the entity's dimension.
    */
   virtual int get_h(void) = 0;

   /**
    * @brief Get the ID of the entity.
    * 
    * @return int The current ID of the entity.
    */
   virtual int get_id(void) = 0;

   /**
    * @brief Get the type of the entity.
    * 
    * @return int The current type of the entity.
    */
   virtual int get_type(void) = 0;
};