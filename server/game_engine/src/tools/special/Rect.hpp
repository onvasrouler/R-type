/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Rect
*/

#pragma once

class Rect
{
public:
    Rect();
    Rect(const int l, const int h);
    ~Rect() = default;

    void set_l(const int l);
    void set_h(const int h);

    int get_l();
    int get_h();

private:
    int _h;
    int _l;
};
