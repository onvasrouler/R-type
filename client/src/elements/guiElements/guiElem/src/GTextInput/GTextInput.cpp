/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GTextInput
*/

#include "GTextInput.hpp"

GTextInput::GTextInput(const Vector2 pos, const Vector2 size, const std::string text, const std::string id, int textSize, const bool editMode, const bool display) : AGuiElem(pos, size, text, id, display)
{
    this->_TextMaxSize = textSize;
    this->_EditMode = editMode;
}

void GTextInput::draw() const
{
    if (this->_Display) {
        char* text = const_cast<char*>(this->_Text.c_str());
        
        if (GuiTextBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, text, this->_TextMaxSize, this->_EditMode)) {
            const_cast<GTextInput*>(this)->setEditMode(!this->_EditMode);
            
            const_cast<GTextInput*>(this)->setText(text);
            const_cast<GTextInput*>(this)->setValue(text);
        }
    }
}

void GTextInput::setTextMaxSize(const int textMaxSize)
{
    this->_TextMaxSize = textMaxSize;
}

void GTextInput::setEditMode(const bool editMode)
{
    this->_EditMode = editMode;
}


int GTextInput::getTextMaxSize() const
{
    return this->_TextMaxSize;
}

bool GTextInput::getEditMode() const
{
    return this->_EditMode;
}
