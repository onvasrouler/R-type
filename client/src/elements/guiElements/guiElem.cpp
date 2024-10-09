/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#include "guiElem.hpp"

void GUIElement::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GUIElement::setSize(Vector2 size)
{
    _Size = size;
}

void GUIElement::setText(std::string text)
{
    _Text = text;
}

Vector2 GUIElement::getPos() const
{
    return _Pos;
}

Vector2 GUIElement::getSize() const
{
    return _Size;
}

std::string GUIElement::getText() const
{
    return _Text;
}

// ----------------------- GWINDBOW -----------------------

GWindBox::GWindBox(Vector2 pos, Vector2 size, std::string text, bool isOpened) : GUIElement(pos, size, text)
{
    _isOpened = isOpened;
}

void GWindBox::DrawRlibWindBox() const
{
    if (_isOpened)
        if (GuiWindowBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str()))
            const_cast<GWindBox*>(this)->setIsOpened(_isOpened ? false : true);
        
}

void GWindBox::setIsOpened(bool isOpened)
{
    _isOpened = isOpened;
}

bool GWindBox::getState() const
{
    return _isOpened;
}





















// ----------------------- GButton -----------------------


GButton::GButton(Vector2 pos, Vector2 size, std::string text)  : GUIElement(pos, size, text)
{
    _isClicked = false;
}

void GButton::DrawRlibButton() const
{
    if (GuiButton(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str()))
        const_cast<GButton*>(this)->setState(true);
    else
        const_cast<GButton*>(this)->setState(false);
}

void GButton::setState(bool state)
{
    _isClicked = state;
}

bool GButton::getState() const
{
    return _isClicked;
}























// ----------------------- GCheckBox -----------------------

GCheckBox::GCheckBox(Vector2 pos, Vector2 size, std::string text, bool checked)  : GUIElement(pos, size, text)
{
    _isChecked = checked;
}

void GCheckBox::DrawRlibCheckBox() const
{
    bool isChecked = _isChecked;
    if (GuiCheckBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &isChecked))
        const_cast<GCheckBox*>(this)->setState(isChecked);
}

void GCheckBox::setState(bool state)
{
    _isChecked = state;
}

bool GCheckBox::getState() const
{
    return _isChecked;
}





















// ----------------------- GSlider -----------------------

GSlider::GSlider(Vector2 pos, Vector2 size, std::string text, float value, float minvalue, float maxvalue)  : GUIElement(pos, size, text)
{
    _value = value;
    _minValue = minvalue;
    _maxValue = maxvalue;
}

void GSlider::DrawRlibSlider() const
{
    float value = _value;
    if (GuiSlider(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), TextFormat("%2.2f", value), &value, _minValue, _maxValue))
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

float GSlider::getValue() const
{
    return _value;
}

float GSlider::getMaxValue() const
{
    return _maxValue;
}

float GSlider::getMinValue() const
{
    return _minValue;
}





















// ----------------------- GLIST -----------------------

GList::GList(Vector2 pos, Vector2 size, std::string text)  : GUIElement(pos, size, text)
{
    _Value = 0;
    _ScrollIndex = 0;
}

void GList::DrawRlibList() const
{
    int value = _Value;
    int scrollIndex = _ScrollIndex;
    GuiListView(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &scrollIndex, &value);
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

int GList::getScrollIndex() const
{
    return _ScrollIndex;
}

int GList::getValue() const
{
    return _Value;
}





















// ----------------------- GLISTEX -----------------------

GListEx::GListEx(Vector2 pos, Vector2 size, std::vector<std::string> list, int active) : GUIElement(pos, size, std::move(list[0]))
{
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
    GuiListViewEx(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, cstr_list.data(), cstr_list.size(), &active, &scrollIndex, &focus);
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

int GListEx::getScrollIndex() const
{
    return _ScrollIndex;
}

int GListEx::getFocus() const
{
    return _Focus;
}

int GListEx::getActive() const
{
    return _active;
}

std::vector<std::string> GListEx::getList() const
{
    return _list;
}




















// ----------------------- GTextInput -----------------------

GTextInput::GTextInput(Vector2 pos, Vector2 size, std::string text, int textSize, bool editMode) : GUIElement(pos, size, text)
{
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

void GTextInput::setTextMaxSize(int textMaxSize)
{
    _TextMaxSize = textMaxSize;
}

void GTextInput::setEditMode(bool editMode)
{
    _EditMode = editMode;
}


int GTextInput::getTextMaxSize() const
{
    return _TextMaxSize;
}

bool GTextInput::getEditMode() const
{
    return _EditMode;
}



















// ----------------------- GTextInputBox -----------------------



GTextInputBox::GTextInputBox(Vector2 pos, Vector2 size, std::string title, std::string message, std::string buttons, std::string text, int textMaxSize, bool secretViewActive)  : GUIElement(pos, size, text)
{
    _Title = title;
    _Message = message;
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

int GTextInputBox::getMaxCharacters() const
{
    return _TextMaxSize;
}

bool GTextInputBox::getSecretView() const
{
    return _SecretViewActive;
}

std::string GTextInputBox::getTitle() const
{
    return _Title;
}

std::string GTextInputBox::getMessage() const
{
    return _Message;
}

std::string GTextInputBox::getButtons() const
{
    return _Buttons;
}

int GTextInputBox::getResults() const
{
    return _Result;
}






















// ----------------------- GSpinner -----------------------

GSpinner::GSpinner(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode) : GUIElement(pos, size, text)
{
    _Value = value;
    _MinValue = minValue;
    _MaxValue = maxValue;
    _EditMode = editMode;
}

void GSpinner::DrawRlibSpinner() const
{
    int value = _Value;
    if (GuiSpinner(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &value, _MinValue, _MaxValue, _EditMode))
        const_cast<GSpinner*>(this)->setEditMode(!this->_EditMode);
    const_cast<GSpinner*>(this)->setValue(value);
}

void GSpinner::setValue(int value)
{
    _Value = value;
}

void GSpinner::setMaxValue(int value)
{
    _MaxValue = value;
}

void GSpinner::setMinValue(int value)
{
    _MinValue = value;
}

void GSpinner::setEditMode(bool editMode)
{
    _EditMode = editMode;
}

int GSpinner::getValue() const
{
    return _Value;
}

int GSpinner::getMaxValue() const
{
    return _MaxValue;
}

int GSpinner::getMinValue() const
{
    return _MinValue;
}

bool GSpinner::getEditMode() const
{
    return _EditMode;
}






















// ----------------------- GValueBox -----------------------


GValueBox::GValueBox(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode) : GUIElement(pos, size, text)
{

    _Value = value;
    _MinValue = minValue;
    _MaxValue = maxValue;
    _EditMode = editMode;
}

void GValueBox::DrawRlibValueBox() const
{
    int value = _Value;
    if (GuiValueBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &value, _MinValue, _MaxValue, _EditMode))
        const_cast<GValueBox*>(this)->setEditMode(!this->_EditMode);
    const_cast<GValueBox*>(this)->setValue(value);
}

void GValueBox::setValue(int value)
{
    _Value = value;
}

void GValueBox::setMaxValue(int value)
{
    _MaxValue = value;
}

void GValueBox::setMinValue(int value)
{
    _MinValue = value;
}

void GValueBox::setEditMode(bool editMode)
{
    _EditMode = editMode;
}

int GValueBox::getValue() const
{
    return _Value;
}

int GValueBox::getMaxValue() const
{
    return _MaxValue;
}

int GValueBox::getMinValue() const
{
    return _MinValue;
}

bool GValueBox::getEditMode() const
{
    return _EditMode;
}






















// ----------------------- GGroup -----------------------

GGroup::GGroup(Vector2 pos, Vector2 size, std::string text) : GUIElement(pos, size, text)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
}

void GGroup::DrawRlibGroup() const
{
    GuiGroupBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str());
}




















// ----------------------- GToggleGroup -----------------------

GToggleGroup::GToggleGroup(Vector2 pos, Vector2 size, std::string text, int active) : GUIElement(pos, size, text)
{
    _Active = active;
}

void GToggleGroup::DrawRlibToggleGroup() const
{
    int active = _Active;
    GuiToggleGroup(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &active);
    const_cast<GToggleGroup*>(this)->setActive(active);
}

void GToggleGroup::setActive(int active)
{
    _Active = active;
}

int GToggleGroup::getActive() const
{
    return _Active;
}



















// ----------------------- GToggleSlider -----------------------

GToggleSlider::GToggleSlider(Vector2 pos, Vector2 size, std::string text, int active) : GUIElement(pos, size, text)
{
    _Active = active;
}

void GToggleSlider::DrawRlibToggleSlider() const
{
    int active = _Active;
    GuiToggleSlider(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &active);
    const_cast<GToggleSlider*>(this)->setActive(active);
}

void GToggleSlider::setActive(int active)
{
    _Active = active;
}

int GToggleSlider::getActive() const
{
    return _Active;
}






















// ----------------------- GPannel -----------------------

GPannel::GPannel(Vector2 pos, Vector2 size, std::string text) : GUIElement(pos, size, text)
{
}

void GPannel::DrawRlibPannel() const
{
    GuiPanel(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str());
}




















// ----------------------- GColorPicker -----------------------

GColorPicker::GColorPicker(Vector2 pos, Vector2 size, std::string text, Color color) : GUIElement(pos, size, text)
{
    _Color = color;
}

void GColorPicker::DrawRlibColorPicker() const
{
    Color color = _Color;
    GuiColorPicker(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &color);
    const_cast<GColorPicker*>(this)->setColor(color);
}

void GColorPicker::setColor(Color color)
{
    _Color = color;
}

Color GColorPicker::getColor() const
{
    return _Color;
}























// ----------------------- GProgressBar -----------------------



GProgressBar::GProgressBar(Vector2 pos, Vector2 size, std::string textLeft, std::string textRight, float value, float minvalue, float maxvalue) : GUIElement(pos, size, text)
{
    _TextLeft = textLeft;
    _TextRight = textRight;
    _Value = value;
    _MinValue = minvalue;
    _MaxValue = maxvalue;
}

void GProgressBar::DrawRlibProgressBar() const
{
    float value = _Value;
    GuiProgressBar(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _TextLeft.c_str(), _TextRight.c_str(), &value, _MinValue, _MaxValue);
    const_cast<GProgressBar*>(this)->setValue(value);
}

void GProgressBar::setValue(float value)
{
    _Value = value;
}

void GProgressBar::setMaxValue(float value)
{
    _MaxValue = value;
}

void GProgressBar::setMinValue(float value)
{
    _MinValue = value;
}

void GProgressBar::setTextLeft(std::string text)
{
    _TextLeft = text;
}

void GProgressBar::setTextRight(std::string text)
{
    _TextRight = text;
}

std::string GProgressBar::getTextLeft() const
{
    return _TextLeft;
}

std::string GProgressBar::getTextRight() const
{
    return _TextRight;
}

float GProgressBar::getValue() const
{
    return _Value;
}

float GProgressBar::getMaxValue() const
{
    return _MaxValue;
}

float GProgressBar::getMinValue() const
{
    return _MinValue;
}






















// ----------------------- GDropDown -----------------------

GDropDown::GDropDown(Vector2 pos, Vector2 size, std::string text, int active, bool editMode) : GUIElement(pos, size, text)
{
    _Active = active;
    _EditMode = editMode;
}

void GDropDown::DrawRlibDropDown() const
{
    int active = _Active;
    if (GuiDropdownBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &active, _EditMode))
        const_cast<GDropDown*>(this)->setEditMode(!this->_EditMode);
    const_cast<GDropDown*>(this)->setActive(active);
}

void GDropDown::setActive(int active)
{
    _Active = active;
}

void GDropDown::setEditMode(bool editMode)
{
    _EditMode = editMode;
}

int GDropDown::getActive() const
{
    return _Active;
}

bool GDropDown::getEditMode() const
{
    return _EditMode;
}
