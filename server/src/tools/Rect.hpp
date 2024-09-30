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
    Rect(int l, int h);
    ~Rect();

    void set_l(int l);
    void set_h(int h);

    int get_l();
    int get_h();

private:
    int _h;
    int _l;
};
