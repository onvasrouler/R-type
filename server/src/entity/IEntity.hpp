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

    virtual void move_entity() = 0;

    virtual void set_l(int l) = 0;
    virtual void set_h(int h) = 0;
    virtual void set_x(int x) = 0;
    virtual void set_y(int y) = 0;
    virtual void set_type(int type) = 0;

    virtual int get_x(void) = 0;
    virtual int get_y(void) = 0;
    virtual int get_l(void) = 0;
    virtual int get_h(void) = 0;
    virtual int get_id(void) = 0;
    virtual int get_type(void) = 0;
 };
