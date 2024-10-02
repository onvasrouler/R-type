/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#include "guiElem.hpp"

// ----------------------- GWINDBOW -----------------------

GWindBox::GWindBox()
{
    _text = "WindBox";
    _pos = {0, 0};
    _size = {100, 50};
}

GWindBox::GWindBox(Vector2 pos, Vector2 size, std::string text)
{
    _text = text;
    _pos = pos;
    _size = size;
}

void GWindBox::DrawRlibWindBox() const
{
    if (_isOpened)
        if (GuiWindowBox(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str()))
            const_cast<GWindBox*>(this)->setState(this ? false : true);
        
}

void GWindBox::setState(bool state)
{
    _isOpened = state;
}





















// ----------------------- GButton -----------------------

GButton::GButton()
{
    _text = "Button";
    _pos = {0, 0};
    _size = {100, 50};
}

GButton::GButton(Vector2 pos, Vector2 size, std::string text)
{
    _text = text;
    _pos = pos;
    _size = size;
}

void GButton::DrawRlibButton() const
{
    if (GuiButton(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str()))
        const_cast<GButton*>(this)->setState(true);
    else
        const_cast<GButton*>(this)->setState(false);
}

void GButton::setState(bool state)
{
    _isClicked = state;
    if (_isClicked && _action)
        _action();
}

void GButton::setAction(std::function<void()> action)
{
    _action = action;
}





















// ----------------------- GCheckBox -----------------------

GCheckBox::GCheckBox()
{
    _text = "CheckBox";
    _pos = {0, 0};
    _size = {100, 50};
}

GCheckBox::GCheckBox(Vector2 pos, Vector2 size, std::string text, bool checked)
{
    _text = text;
    _pos = pos;
    _size = size;
    _isChecked = checked;
}

void GCheckBox::DrawRlibCheckBox() const
{
    bool isChecked = _isChecked;
    if (GuiCheckBox(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str(), &isChecked))
        const_cast<GCheckBox*>(this)->setState(isChecked);
}

void GCheckBox::setState(bool state)
{
    _isChecked = state;
}





















// ----------------------- GSlider -----------------------

GSlider::GSlider()
{
    _text = "Slider";
    _pos = {0, 0};
    _size = {100, 50};
    _minValue = 0;
    _maxValue = 100;
}

GSlider::GSlider(Vector2 pos, Vector2 size, std::string text, float value, float minvalue, float maxvalue)
{
    _text = text;
    _pos = pos;
    _size = size;
    _value = value;
    _minValue = minvalue;
    _maxValue = maxvalue;
}

void GSlider::DrawRlibSlider() const
{
    float value = _value;
    if (GuiSlider(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str(), TextFormat("%2.2f", value), &value, _minValue, _maxValue))
        const_cast<GSlider*>(this)->setValue(value);
}

void GSlider::setValue(float value)
{
    _value = value;
}

void GSlider::setMaxValue(float value)
{
    _maxValue = value;
}

void GSlider::setMinValue(float value)
{
    _minValue = value;
}





















// ----------------------- GLIST -----------------------

GList::GList()
{
    _pos = {0, 0};
    _size = {100, 50};
    _text = "default;list;text";
    _ScrollIndex = 0;
    _Value = 0;
}

GList::GList(Vector2 pos, Vector2 size, std::string text)
{
    _pos = pos;
    _size = size;
    _text = text;
    _Value = 0;
    _ScrollIndex = 0;
}

void GList::DrawRlibList() const
{
    int value = _Value;
    int scrollIndex = _ScrollIndex;
    GuiListView(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str(), &scrollIndex, &value);
    const_cast<GList*>(this)->setScrollIndex(scrollIndex);
    const_cast<GList*>(this)->setVal(value);
}

void GList::setScrollIndex(int index)
{
    _ScrollIndex = index;
}

void GList::setVal(int value)
{
    _Value = value;
}





















// ----------------------- GLISTEX -----------------------

GListEx::GListEx()
{
    _pos = {0, 0};
    _size = {100, 50};
    _list = {"default", "list", "text"};
    _active = 0;
}

GListEx::GListEx(Vector2 pos, Vector2 size, std::vector<std::string> list, int active)
{
    _pos = pos;
    _size = size;
    _list = list;
    _active = active;
}

void GListEx::DrawRlibListEx() const
{
    int active = _active;
    int scrollIndex = _ScrollIndex;
    int focus = _Focus;
    std::vector<const char*> cstr_list;
    for (const auto& str : _list) {
        cstr_list.push_back(str.c_str());
    }
    GuiListViewEx(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, cstr_list.data(), cstr_list.size(), &active, &scrollIndex, &focus);
    const_cast<GListEx*>(this)->setScrollIndex(scrollIndex);
    const_cast<GListEx*>(this)->setFocus(focus);
    const_cast<GListEx*>(this)->setActive(active);
}

void GListEx::setList(std::vector<std::string> list)
{
    _list = list;
}

void GListEx::setActive(int active)
{
    _active = active;
}

void GListEx::setFocus(int focus)
{
    _Focus = focus;
}

void GListEx::setScrollIndex(int index)
{
    _ScrollIndex = index;
}





















// ----------------------- GTextInput -----------------------

GTextInput::GTextInput()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "default text";
    _TextMaxSize = 100;
    _EditMode = false;
}

GTextInput::GTextInput(Vector2 pos, Vector2 size, std::string text, int textSize, bool editMode)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
    _TextMaxSize = textSize;
    _EditMode = editMode;
}

void GTextInput::DrawRlibTextInput() const
{
    char* text = const_cast<char*>(_Text.c_str());
    if (GuiTextBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, text, _TextMaxSize, _EditMode)) {
        const_cast<GTextInput*>(this)->setEditMode(!this->_EditMode);
        
        const_cast<GTextInput*>(this)->setText(text);
    }
}

void GTextInput::setText(std::string text)
{
    _Text = text;
}

void GTextInput::setTextMaxSize(int textMaxSize)
{
    _TextMaxSize = textMaxSize;
}

void GTextInput::setEditMode(bool editMode)
{
    _EditMode = editMode;
}





















// ----------------------- GTextInputBox -----------------------

GTextInputBox::GTextInputBox()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Title = "TextInputBox";
    _Message = "Enter text:";
    _Text = "";
    _Buttons = "OK;Cancel";
    _TextMaxSize = 100;
    _SecretViewActive = NULL;
}

GTextInputBox::GTextInputBox(Vector2 pos, Vector2 size, std::string title, std::string message, std::string buttons, std::string text, int textMaxSize, bool secretViewActive)
{
    _Pos = pos;
    _Size = size;
    _Title = title;
    _Message = message;
    _Text = text;
    _Buttons = buttons;
    _TextMaxSize = textMaxSize;
    _SecretViewActive = secretViewActive;
}

void GTextInputBox::DrawRlibTextInputBox() const
{
    char* text = const_cast<char*>(_Text.c_str());
    int result = _Result;
    if (_SecretViewActive != NULL) {
        bool secretviewactive = _SecretViewActive;
        result = GuiTextInputBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Title.c_str(), _Message.c_str(), _Buttons.c_str(), text, _TextMaxSize, &secretviewactive);
        const_cast<GTextInputBox*>(this)->setSecretView(secretviewactive);

    } else {
        result = GuiTextInputBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Title.c_str(), _Message.c_str(), _Buttons.c_str(), text, _TextMaxSize, NULL);
    }

    const_cast<GTextInputBox*>(this)->setResults(result);
    const_cast<GTextInputBox*>(this)->setText(text);
}

void GTextInputBox::setText(std::string text)
{
    _Text = text;
}

void GTextInputBox::setMaxCharacters(int maxCharacters)
{
    _TextMaxSize = maxCharacters;
}

void GTextInputBox::setSecretView(bool secretView)
{
    _SecretViewActive = secretView;
}

void GTextInputBox::setTitle(std::string title)
{
    _Title = title;
}

void GTextInputBox::setMessage(std::string message)
{
    _Message = message;
}

void GTextInputBox::setButtons(std::string buttons)
{
    _Buttons = buttons;
}

void GTextInputBox::setResults(int result)
{
    _Result = result;
}