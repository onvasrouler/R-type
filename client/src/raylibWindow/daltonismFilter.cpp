/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** daltonismFilter
*/

#include "daltonismFilter.hpp"

daltonismFilter::daltonismFilter()
{
    _DaltonismType = daltonismType::NONE;
    _Shader = LoadShader(0, "./config/daltonism_filter.fs");
    _FilterTypeLoc = GetShaderLocation(_Shader, "type");
    int daltonismTypeInt = static_cast<int>(_DaltonismType);
    SetShaderValue(_Shader, _FilterTypeLoc, &daltonismTypeInt, SHADER_UNIFORM_INT);
}

daltonismFilter::~daltonismFilter()
{
    UnloadShader(_Shader);
}

void daltonismFilter::setDaltonismType(daltonismType daltonismType)
{
    _DaltonismType = daltonismType;
    int daltonismTypeInt = static_cast<int>(daltonismType);
    SetShaderValue(_Shader, _FilterTypeLoc, &daltonismTypeInt, SHADER_UNIFORM_INT);
}

void daltonismFilter::setDaltonismType(int daltonismType)
{
    SetShaderValue(_Shader, _FilterTypeLoc, &daltonismType, SHADER_UNIFORM_INT);
}

daltonismFilter::daltonismType daltonismFilter::getDaltonismType() const
{
    return _DaltonismType;
}

Shader daltonismFilter::getShader() const
{
    return _Shader;
}