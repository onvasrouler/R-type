/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menu
*/

#pragma once

#include "../elements/raylibText/raylibText.hpp"
#include "../elements/raylibButton/raylibButton.hpp"
#include "../include.hpp"

class Menu {
public:
    Menu() = default;
    ~Menu() = default;

    void drawMenu() const;

    void addText(RaylibText text);
    void addButton(RaylibButton button);

    void setTexts(std::vector<RaylibText> texts);
    void setButtons(std::vector<RaylibButton> buttons);

private:
    std::vector<RaylibText> _Texts;
    std::vector<RaylibButton> _Buttons;

};