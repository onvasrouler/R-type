/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#pragma once

#include "guiElem/Elem.hpp"
#include "../raylibText/raylibText.hpp"

class RGui {
public:
    RGui() = default;
    ~RGui();

    void DrawGui() const;

    std::string GetValueById(std::string id) const;

    const std::shared_ptr<AGuiElem> GetElementById(std::string id) const;
    const std::shared_ptr<RaylibText> GetTextsById(std::string id) const;

    void AddElement(const std::shared_ptr<AGuiElem> elem);
    void AddText(const std::shared_ptr<RaylibText> text);

    void SetElements(std::vector<std::shared_ptr<AGuiElem>> elements);
    void SetTexts(std::vector<std::shared_ptr<RaylibText>> texts);

    void addListElement(std::vector<std::shared_ptr<AGuiElem>> elem);
    void addListText(std::vector<std::shared_ptr<RaylibText>> texts);
private:
    std::vector<std::shared_ptr<RaylibText>> _Texts;
    std::vector<std::shared_ptr<AGuiElem>> _elements;
};
