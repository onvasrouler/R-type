/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** raylibButton
*/

#pragma once

#include "../../include.hpp"

enum PButtonType {
    PBUTTON,
    PTOGGLE,
    PERROR
};

class RaylibButton {
    public:
    RaylibButton();
    RaylibButton(std::string text, Vector2 pos, Vector2 size, Color color, PButtonType type);
    ~RaylibButton() = default;

    void DrawRlibButton() const;

    void UpdateRlibButton() const;

    void SetText(std::string text);
    void SetPos(Vector2 pos);
    void SetSize(Vector2 size);
    void SetColor(Color color);
    void setType(PButtonType type);

    void setHovered(bool hovered);
    void setPressed(bool pressed);
    void setReleased(bool released);

    std::string GetText();
    Vector2 GetPos();
    Vector2 GetSize();
    Color GetColor();
    PButtonType GetType();
    
    private:
    PButtonType _type;
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    Color _color;
    Color _DefaultColor;
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