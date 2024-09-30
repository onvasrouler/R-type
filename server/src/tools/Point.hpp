/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Point
*/

#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();

    void set_x(int x);
    void set_y(int y);

    int get_x();
    int get_y();

private:
    int _x;
    int _y;
};
