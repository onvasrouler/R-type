/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** daltonismFilter
*/

#pragma once

#include <raylib.h>
#include <iostream>

class daltonismFilter {
public:
    enum class daltonismType {
        NONE,
        PROTANOPIA,
        DEUTERANOPIA,
        TRITANOPIA
    };
    daltonismFilter();
    ~daltonismFilter();

    void setDaltonismType(daltonismType daltonismType);
    void setDaltonismType(int daltonismType);
    daltonismType getDaltonismType() const;

    Shader getShader() const;

private:
    daltonismType _DaltonismType;
    int _FilterTypeLoc;
    Shader _Shader;
};
