/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibButton
*/

#pragma once

#include "../../include.hpp"

enum ButtonType {
    BUTTON,
    TOGGLE,
    ERROR
};

class RaylibButton {
    public:
    RaylibButton();
    RaylibButton(std::string text, Vector2 pos, Vector2 size, Color color, ButtonType type);
    ~RaylibButton() = default;

    void DrawRlibButton() const;

    void UpdateRlibButton();

    void SetText(std::string text);
    void SetPos(Vector2 pos);
    void SetSize(Vector2 size);
    void SetColor(Color color);
    void setType(ButtonType type);

    std::string GetText();
    Vector2 GetPos();
    Vector2 GetSize();
    Color GetColor();
    ButtonType GetType();
    
    private:
    ButtonType _type;
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    Color _color;
    bool _isHovered;
    bool _isClicked;
    bool _isPressed;
    bool _isReleased;
    bool _isFocused;
    bool _isDragged;
    bool _isDropped;
    bool _isHidden;
    bool _isDisabled;
    bool _isToggled;
};