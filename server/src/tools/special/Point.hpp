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

    int get_x() const;
    int get_y() const;

private:
    int _x;
    int _y;
};
