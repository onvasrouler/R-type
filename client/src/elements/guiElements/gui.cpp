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
}

void RGui::DrawGui() const
{
    std::map<int, std::vector<std::shared_ptr<AGuiElem>>> elementsBuffer;

    if (this->_elements.size() > 0)
        for (const auto &element : this->_elements)
            elementsBuffer[element->getZIndex()].push_back(element);
    for (const auto &pair : elementsBuffer)
        for (const auto &element : pair.second)
            element->draw();
    elementsBuffer.clear();
}

std::string RGui::GetValueById(const std::string id) const
{
    for (const auto &element : this->_elements)
        if (element->getId() == id)
            return element->getValue();
    return "";
}

const std::shared_ptr<AGuiElem> RGui::GetElementById(const std::string id) const
{
    for (const auto &element : this->_elements)
        if (element->getId() == id)
            return element;
    return nullptr;
}

void RGui::AddElement(const std::shared_ptr<AGuiElem> element)
{
    this->_elements.push_back(element);
}

void RGui::SetElements(const std::vector<std::shared_ptr<AGuiElem>> elements)
{
    this->_elements = elements;
}

void RGui::addListElement(const std::vector<std::shared_ptr<AGuiElem>> elements)
{
    this->_elements.insert(this->_elements.end(), elements.begin(), elements.end());
}