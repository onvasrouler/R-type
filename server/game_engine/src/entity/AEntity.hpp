/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEntity
*/

#pragma once
 
#include "IEntity.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "Id.hpp"
#include "Type.hpp"

class AEntity : public IEntity
{
public:
    AEntity();
    virtual ~AEntity() = default;

    virtual void move() = 0;

    void set_l(int l);
    void set_h(int h);
    void set_x(int x);
    void set_y(int y);
    void set_type(int type);

    int get_x(void) const;
    int get_y(void) const;
    int get_l(void) const;
    int get_h(void) const;
    int get_id(void) const;
    int get_type(void) const;

protected:
    Point _origin;
    Rect _dimension;
    Id _id;
    Type _type;
};
