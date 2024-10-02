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
    AEntity(int x, int y, int l, int h, int type, int id);
    virtual ~AEntity() = default;

    virtual void move_entity() = 0;

    void set_l(int l);
    void set_h(int h);
    void set_x(int x);
    void set_y(int y);
    void set_type(int type);

    int get_x(void);
    int get_y(void);
    int get_l(void);
    int get_h(void);
    int get_id(void);
    int get_type(void);

protected:
    std::unique_ptr<Point> _origin;
    std::unique_ptr<Rect> _dimension;
    std::unique_ptr<Id> _id;
    std::unique_ptr<Type> _type;
};
