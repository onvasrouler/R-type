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
    Point(const int x, const int y);
    ~Point() = default;

    void set_x(const int x);
    void set_y(const int y);

    int get_x() const;
    int get_y() const;

    void moveX(const int distance);
    void moveY(const int distance);

private:
    int _x;
    int _y;
};
