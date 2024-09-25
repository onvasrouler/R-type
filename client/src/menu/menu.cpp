/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menu
*/

#include "menu.hpp"

void Menu::drawMenu() const
{
    if (!_Texts.empty())
        for (auto &text : _Texts)
            text.DrawRlibText();
    if (!_Buttons.empty())
        for (auto &button : _Buttons)
            button.DrawRlibButton();
}

void Menu::addText(RaylibText text)
{
    _Texts.push_back(text);
}

void Menu::addButton(RaylibButton button)
{
    _Buttons.push_back(button);
}

void Menu::setTexts(std::vector<RaylibText> texts)
{
    _Texts = texts;
}

void Menu::setButtons(std::vector<RaylibButton> buttons)
{
    _Buttons = buttons;
}
