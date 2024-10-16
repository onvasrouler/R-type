/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GList
*/

#include "GList.hpp"

GList::GList(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_Value = 0;
    this->_ScrollIndex = 0;
}

void GList::draw() const
{
    if (this->_Display) {
        int value = this->_Value;
        int scrollIndex = this->_ScrollIndex;
        GuiListView(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &scrollIndex, &value);
        const_cast<GList*>(this)->setScrollIndex(scrollIndex);
        const_cast<GList*>(this)->setVal(value);
    }
}

void GList::setScrollIndex(const int index)
{
    this->_ScrollIndex = index;
}

void GList::setVal(const int value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

int GList::getScrollIndex() const
{
    return this->_ScrollIndex;
}
