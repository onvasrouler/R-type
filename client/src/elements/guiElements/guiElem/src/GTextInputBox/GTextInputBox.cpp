/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GTextInputBox
*/

#include "GTextInputBox.hpp"

GTextInputBox::GTextInputBox(const Vector2 pos, const Vector2 size, const std::string id, const std::string title, const std::string message, const std::string buttons, const std::string text, int textMaxSize, const bool secretViewActive, const bool display) : AGuiElem(pos, size, text, id, display)
{
    this->_Title = title;
    this->_Message = message;
    this->_Buttons = buttons;
    this->_TextMaxSize = textMaxSize;
    this->_SecretViewActive = secretViewActive;
}

void GTextInputBox::draw() const
{
    if (this->_Display) {
        char* text = const_cast<char*>(this->_Text.c_str());
        int result = this->_Result;

        if (this->_SecretViewActive) {
            bool secretviewactive = this->_SecretViewActive;
            result = GuiTextInputBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Title.c_str(), this->_Message.c_str(), this->_Buttons.c_str(), text, this->_TextMaxSize, &secretviewactive);
            const_cast<GTextInputBox*>(this)->setSecretView(secretviewactive);
        } else {
            result = GuiTextInputBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Title.c_str(), this->_Message.c_str(), this->_Buttons.c_str(), text, this->_TextMaxSize, NULL);
        }
        
        const_cast<GTextInputBox*>(this)->setResults(result);
        const_cast<GTextInputBox*>(this)->setText(text);
        const_cast<GTextInputBox*>(this)->setValue(text);
    }
}

void GTextInputBox::setMaxCharacters(const int maxCharacters)
{
    this->_TextMaxSize = maxCharacters;
}

void GTextInputBox::setSecretView(const bool secretView)
{
    this->_SecretViewActive = secretView;
}

void GTextInputBox::setTitle(std::string title)
{
    this->_Title = title;
}

void GTextInputBox::setMessage(std::string message)
{
    this->_Message = message;
}

void GTextInputBox::setButtons(std::string buttons)
{
    this->_Buttons = buttons;
}

void GTextInputBox::setResults(const int result)
{
    this->_Result = result;
}

int GTextInputBox::getMaxCharacters() const
{
    return this->_TextMaxSize;
}

bool GTextInputBox::getSecretView() const
{
    return this->_SecretViewActive;
}

std::string GTextInputBox::getTitle() const
{
    return this->_Title;
}

std::string GTextInputBox::getMessage() const
{
    return this->_Message;
}

std::string GTextInputBox::getButtons() const
{
    return this->_Buttons;
}

int GTextInputBox::getResults() const
{
    return this->_Result;
}
