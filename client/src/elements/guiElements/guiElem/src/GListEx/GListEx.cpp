/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GListEx
*/

#include "GListEx.hpp"

GListEx::GListEx(const Vector2 pos, const Vector2 size, const std::string id, const std::vector<std::string> list, int active, const bool display) : AGuiElem(pos, size, "default", id, display)
{
    this->_List = list;
    this->_Active = active;
}

void GListEx::draw() const
{
    if (this->_Display) {
        int active = this->_Active;
        int scrollIndex = this->_ScrollIndex;
        int focus = this->_Focus;
        std::vector<const char*> cstrlist;
        
        for (const auto& str : this->_List) {
            cstrlist.push_back(str.c_str());
        }

        GuiListViewEx(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, cstrlist.data(), cstrlist.size(), &active, &scrollIndex, &focus);
        const_cast<GListEx*>(this)->setScrollIndex(scrollIndex);
        const_cast<GListEx*>(this)->setFocus(focus);
        const_cast<GListEx*>(this)->setActive(active);
    }
}

void GListEx::setList(const std::vector<std::string> list)
{
    this->_List = list;
}

void GListEx::setActive(const int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

void GListEx::setFocus(const int focus)
{
    this->_Focus = focus;
}

void GListEx::setScrollIndex(const int index)
{
    this->_ScrollIndex = index;
}

int GListEx::getScrollIndex() const
{
    return this->_ScrollIndex;
}

int GListEx::getFocus() const
{
    return this->_Focus;
}

int GListEx::getActive() const
{
    return this->_Active;
}

std::vector<std::string> GListEx::getList() const
{
    return this->_List;
}
