/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#include "gui.hpp"

RGui::~RGui()
{
    this->_elements.clear();
    this->_Texts.clear();
}

void RGui::DrawGui() const
{
    if (this->_Texts.size() > 0)
        for (const auto &text : this->_Texts)
            text->DrawRlibText();
    
    if (this->_elements.size() > 0)
        for (const auto &element : this->_elements)
            element->draw();
}

std::string RGui::GetValueById(std::string id) const
{
    for (const auto &element : this->_elements)
        if (element->getId() == id)
            return element->getValue();

    for (const auto &text : this->_Texts)
        if (text->getId() == id)
            return text->getText();

    return "";
}

const std::shared_ptr<AGuiElem> RGui::GetElementById(std::string id) const
{
    for (const auto &element : this->_elements)
        if (element->getId() == id)
            return element;

    return nullptr;
}

const std::shared_ptr<RaylibText> RGui::GetTextsById(std::string id) const
{
    for (const auto &text : this->_Texts)
        if (text->getId() == id)
            return text;
    return nullptr;
}

void RGui::AddElement(const std::shared_ptr<AGuiElem> element)
{
    this->_elements.push_back(element);
}

void RGui::AddText(const std::shared_ptr<RaylibText> text)
{
    this->_Texts.push_back(text);
}

void RGui::SetElements(std::vector<std::shared_ptr<AGuiElem>> elements)
{
    this->_elements = elements;
}

void RGui::SetTexts(std::vector<std::shared_ptr<RaylibText>> texts)
{
    this->_Texts = texts;
}

void RGui::addListElement(std::vector<std::shared_ptr<AGuiElem>> elements)
{
    this->_elements.insert(this->_elements.end(), elements.begin(), elements.end());
}

void RGui::addListText(std::vector<std::shared_ptr<RaylibText>> text)
{
    this->_Texts.insert(this->_Texts.end(), text.begin(), text.end());
}
