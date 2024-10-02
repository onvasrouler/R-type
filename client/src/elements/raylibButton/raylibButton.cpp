/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibButton
*/

#include "raylibButton.hpp"

RaylibButton::RaylibButton()
{
    _text = "Button";
    _pos = {0, 0};
    _size = {100, 50};
    _color = WHITE;
    _DefaultColor = WHITE;
    _type = PBUTTON;
    _isHovered = false;
    _isClicked = false;
    _isPressed = false;
    _isReleased = true;
    _isFocused = false;
    _isDragged = false;
    _isDropped = false;
    _isHidden = false;
    _isDisabled = false;
    _isToggled = false;
}

RaylibButton::RaylibButton(std::string text, Vector2 pos, Vector2 size, Color color, PButtonType type)
{
    _text = text;
    _pos = pos;
    _size = size;
    _color = color;
    _DefaultColor = color;
    _type = type;
    _isHovered = false;
    _isClicked = false;
    _isPressed = false;
    _isReleased = true;
    _isFocused = false;
    _isDragged = false;
    _isDropped = false;
    _isHidden = false;
    _isDisabled = false;
    _isToggled = false;
}

void RaylibButton::DrawRlibButton() const
{
    if (_isHidden)
        return;

    DrawRectangle(_pos.x, _pos.y, _size.x, _size.y, _color);
    DrawText(_text.c_str(), _pos.x + _size.x / 2 - MeasureText(_text.c_str(), 20) / 2, _pos.y + _size.y / 2 - 10, 20, BLACK);
}

void RaylibButton::UpdateRlibButton() const
{
    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, { _pos.x, _pos.y, _size.x, _size.y })) {
        const_cast<RaylibButton*>(this)->setHovered(true);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            const_cast<RaylibButton*>(this)->setPressed(true);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            const_cast<RaylibButton*>(this)->setReleased(true);
    } else {
        const_cast<RaylibButton*>(this)->setHovered(false);
    }
    DrawRlibButton();
}

void RaylibButton::SetText(std::string text)
{
    _text = text;
}

void RaylibButton::SetPos(Vector2 pos)
{
    _pos = pos;
}

void RaylibButton::SetSize(Vector2 size)
{
    _size = size;
}

void RaylibButton::SetColor(Color color)
{
    _color = color;
}

void RaylibButton::setType(PButtonType type)
{
    _type = type;
}

void RaylibButton::setHovered(bool hovered)
{
    _isHovered = hovered;
    if (_isHovered && !_isPressed && !_isReleased)
        _color = LIGHTGRAY;
    else
        _color = _DefaultColor;
}

void RaylibButton::setPressed(bool pressed)
{
    _isPressed = pressed;
    _isReleased = false;
    if (_isPressed)
        _color = GRAY;
}

void RaylibButton::setReleased(bool released)
{
    _isReleased = released;
    if (_isReleased)
        _color = _DefaultColor;
}

std::string RaylibButton::GetText()
{
    return _text;
}

Vector2 RaylibButton::GetPos()
{
    return _pos;
}

Vector2 RaylibButton::GetSize()
{
    return _size;
}

Color RaylibButton::GetColor()
{
    return _color;
}

PButtonType RaylibButton::GetType()
{
    return _type;
}

