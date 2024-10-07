/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/

#pragma once

#include <memory>
 
class IEntity
{
public:
   virtual ~IEntity() = default;

   virtual void move() = 0;
    
   virtual void set_l(int l) = 0;
   virtual void set_h(int h) = 0;
   virtual void set_x(int x) = 0;
   virtual void set_y(int y) = 0;
   virtual void set_type(int type) = 0;

   virtual int get_x(void) const = 0;
   virtual int get_y(void) const = 0;
   virtual int get_l(void) const = 0;
   virtual int get_h(void) const = 0;
   virtual int get_id(void) const = 0;
   virtual int get_type(void) const = 0;
};
