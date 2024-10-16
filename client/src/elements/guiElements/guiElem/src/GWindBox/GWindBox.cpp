/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** IGuiElem
*/

#include "GWindBox.hpp"

GWindBox::GWindBox(const Vector2 pos, const Vector2 size, const std::string text, const int zindex, const std::string id, const bool isOpened, const bool display) : AGuiElem(pos, size, text, zindex, id, display)
{
    this->_isOpened = isOpened;
}

void GWindBox::draw() const
{
    if (this->_Display && this->_isOpened) {
        if (GuiWindowBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str())) {
            const_cast<GWindBox*>(this)->setIsOpened(this->_isOpened ? false : true);
        }
    }
        
}

void GWindBox::setIsOpened(const bool isOpened)
{
    this->_isOpened = isOpened;
    std::string value = isOpened ? "true" : "false";
    this->setValue(value);
}
