/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** IGuiElem
*/

#include "AGuiElem.hpp"

AGuiElem::AGuiElem(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool display)
{
    this->_Pos = pos;
    this->_Size = size;
    this->_Text = text;
    this->_Id = id;
    this->_Display = display;
    this->_ZIndex = zindex;
}


void AGuiElem::setPos(const Vector2 pos)
{
    this->_Pos = pos;
}

void AGuiElem::setSize(const Vector2 size)
{
    this->_Size = size;
}

void AGuiElem::setText(const std::string text)
{
    this->_Text = text;
}

void AGuiElem::setValue(const std::string value)
{
    this->_Value = value;
}

void AGuiElem::setId(const std::string id)
{
    this->_Id = id;
}

void AGuiElem::toggleDisplay()
{
    this->_Display = !this->_Display;
}

void AGuiElem::setDisplay(const bool state)
{
    this->_Display = state;
}

void AGuiElem::setZIndex(const int zIndex)
{
    this->_ZIndex = zIndex;
}

Vector2 AGuiElem::getPos() const
{
    return this->_Pos;
}

Vector2 AGuiElem::getSize() const
{
    return this->_Size;
}

std::string AGuiElem::getText() const
{
    return this->_Text;
}

std::string AGuiElem::getValue() const
{
    return this->_Value;
}

std::string AGuiElem::getId() const
{
    return this->_Id;
}

bool AGuiElem::getDisplay() const
{
    return this->_Display;
}

int AGuiElem::getZIndex() const
{
    return this->_ZIndex;
}