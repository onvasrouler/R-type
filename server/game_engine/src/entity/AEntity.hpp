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

    void set_l(const int l);
    void set_h(const int h);
    void set_x(const int x);
    void set_y(const int y);
    void set_type(const int type);

    int get_x(void);
    int get_y(void);
    int get_l(void);
    int get_h(void);
    int get_id(void);
    int get_type(void);

protected:
    Point _origin;
    Rect _dimension;
    Id _id;
    Type _type;
};
