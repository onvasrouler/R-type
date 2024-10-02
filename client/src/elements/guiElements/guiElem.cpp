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
    _isOpened = false;
}

GWindBox::GWindBox(Vector2 pos, Vector2 size, std::string text, bool isOpened)
{
    _text = text;
    _pos = pos;
    _size = size;
    _isOpened = isOpened;
}

void GWindBox::DrawRlibWindBox() const
{
    if (_isOpened)
        if (GuiWindowBox(Rectangle{_pos.x, _pos.y, _size.x, _size.y}, _text.c_str()))
            const_cast<GWindBox*>(this)->setIsOpened(_isOpened ? false : true);
        
}

void GWindBox::setIsOpened(bool isOpened)
{
    _isOpened = isOpened;
}

void GWindBox::setText(std::string text)
{
    _text = text;
}

void GWindBox::setPos(Vector2 pos)
{
    _pos = pos;
}

void GWindBox::setSize(Vector2 size)
{
    _size = size;
}

std::string GWindBox::getText() const
{
    return _text;
}

Vector2 GWindBox::getPos() const
{
    return _pos;
}

Vector2 GWindBox::getSize() const
{
    return _size;
}

bool GWindBox::getState() const
{
    return _isOpened;
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
}

void GButton::setText(std::string text)
{
    _text = text;
}

void GButton::setPos(Vector2 pos)
{
    _pos = pos;
}

void GButton::setSize(Vector2 size)
{
    _size = size;
}

std::string GButton::getText() const
{
    return _text;
}

Vector2 GButton::getPos() const
{
    return _pos;
}

Vector2 GButton::getSize() const
{
    return _size;
}

bool GButton::getState() const
{
    return _isClicked;
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

void GCheckBox::setText(std::string text)
{
    _text = text;
}

void GCheckBox::setPos(Vector2 pos)
{
    _pos = pos;
}

void GCheckBox::setSize(Vector2 size)
{
    _size = size;
}

std::string GCheckBox::getText() const
{
    return _text;
}

Vector2 GCheckBox::getPos() const
{
    return _pos;
}

Vector2 GCheckBox::getSize() const
{
    return _size;
}

bool GCheckBox::getState() const
{
    return _isChecked;
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

void GSlider::setText(std::string text)
{
    _text = text;
}

void GSlider::setPos(Vector2 pos)
{
    _pos = pos;
}

void GSlider::setSize(Vector2 size)
{
    _size = size;
}

std::string GSlider::getText() const
{
    return _text;
}

Vector2 GSlider::getPos() const
{
    return _pos;
}

Vector2 GSlider::getSize() const
{
    return _size;
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

void GList::setText(std::string text)
{
    _text = text;
}

void GList::setPos(Vector2 pos)
{
    _pos = pos;
}

void GList::setSize(Vector2 size)
{
    _size = size;
}

std::string GList::getText() const
{
    return _text;
}

Vector2 GList::getPos() const
{
    return _pos;
}

Vector2 GList::getSize() const
{
    return _size;
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

void GListEx::setText(std::string text)
{
    _text = text;
}

void GListEx::setPos(Vector2 pos)
{
    _pos = pos;
}

void GListEx::setSize(Vector2 size)
{
    _size = size;
}

std::string GListEx::getText() const
{
    return _text;
}

Vector2 GListEx::getPos() const
{
    return _pos;
}

Vector2 GListEx::getSize() const
{
    return _size;
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

void GTextInput::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GTextInput::setSize(Vector2 size)
{
    _Size = size;
}

std::string GTextInput::getText() const
{
    return _Text;
}

int GTextInput::getTextMaxSize() const
{
    return _TextMaxSize;
}

bool GTextInput::getEditMode() const
{
    return _EditMode;
}

Vector2 GTextInput::getPos() const
{
    return _Pos;
}

Vector2 GTextInput::getSize() const
{
    return _Size;
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

void GTextInputBox::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GTextInputBox::setSize(Vector2 size)
{
    _Size = size;
}

std::string GTextInputBox::getText() const
{
    return _Text;
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

Vector2 GTextInputBox::getPos() const
{
    return _Pos;
}

Vector2 GTextInputBox::getSize() const
{
    return _Size;
}






















// ----------------------- GSpinner -----------------------

GSpinner::GSpinner()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default Spinner";
    _Value = 0;
    _MinValue = 0;
    _MaxValue = 100;
    _EditMode = false;
}

GSpinner::GSpinner(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
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

void GSpinner::setText(std::string text)
{
    _Text = text;
}

void GSpinner::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GSpinner::setSize(Vector2 size)
{
    _Size = size;
}

std::string GSpinner::getText() const
{
    return _Text;
}

Vector2 GSpinner::getPos() const
{
    return _Pos;
}

Vector2 GSpinner::getSize() const
{
    return _Size;
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

GValueBox::GValueBox()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default Value Box";
    _Value = 0.0F;
    _MinValue = 0.0F;
    _MaxValue = 100.0F;
    _EditMode = false;
}

GValueBox::GValueBox(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
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

void GValueBox::setText(std::string text)
{
    _Text = text;
}

void GValueBox::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GValueBox::setSize(Vector2 size)
{
    _Size = size;
}

std::string GValueBox::getText() const
{
    return _Text;
}

Vector2 GValueBox::getPos() const
{
    return _Pos;
}

Vector2 GValueBox::getSize() const
{
    return _Size;
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

GGroup::GGroup()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default Group";
}

GGroup::GGroup(Vector2 pos, Vector2 size, std::string text)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
}

void GGroup::DrawRlibGroup() const
{
    GuiGroupBox(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str());
}

void GGroup::setText(std::string text)
{
    _Text = text;
}

void GGroup::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GGroup::setSize(Vector2 size)
{
    _Size = size;
}

std::string GGroup::getText() const
{
    return _Text;
}

Vector2 GGroup::getPos() const
{
    return _Pos;
}

Vector2 GGroup::getSize() const
{
    return _Size;
}





















// ----------------------- GToggleGroup -----------------------

GToggleGroup::GToggleGroup()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default;Toggle;Group";
    _Active = 0;
}

GToggleGroup::GToggleGroup(Vector2 pos, Vector2 size, std::string text, int active)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
    _Active = active;
}

void GToggleGroup::DrawRlibToggleGroup() const
{
    int active = _Active;
    GuiToggleGroup(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &active);
    const_cast<GToggleGroup*>(this)->setActive(active);
}

void GToggleGroup::setText(std::string text)
{
    _Text = text;
}

void GToggleGroup::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GToggleGroup::setSize(Vector2 size)
{
    _Size = size;
}

void GToggleGroup::setActive(int active)
{
    _Active = active;
}

std::string GToggleGroup::getText() const
{
    return _Text;
}

Vector2 GToggleGroup::getPos() const
{
    return _Pos;
}

Vector2 GToggleGroup::getSize() const
{
    return _Size;
}

int GToggleGroup::getActive() const
{
    return _Active;
}



















// ----------------------- GToggleSlider -----------------------

GToggleSlider::GToggleSlider()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default;Toggle";
    _Active = 0;
}

GToggleSlider::GToggleSlider(Vector2 pos, Vector2 size, std::string text, int active)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
    _Active = active;
}

void GToggleSlider::DrawRlibToggleSlider() const
{
    int active = _Active;
    GuiToggleSlider(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &active);
    const_cast<GToggleSlider*>(this)->setActive(active);
}

void GToggleSlider::setText(std::string text)
{
    _Text = text;
}

void GToggleSlider::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GToggleSlider::setSize(Vector2 size)
{
    _Size = size;
}

void GToggleSlider::setActive(int active)
{
    _Active = active;
}

std::string GToggleSlider::getText() const
{
    return _Text;
}

Vector2 GToggleSlider::getPos() const
{
    return _Pos;
}

Vector2 GToggleSlider::getSize() const
{
    return _Size;
}

int GToggleSlider::getActive() const
{
    return _Active;
}






















// ----------------------- GPannel -----------------------

GPannel::GPannel()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default;Pannel";
}

GPannel::GPannel(Vector2 pos, Vector2 size, std::string text)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
}

void GPannel::DrawRlibPannel() const
{
    GuiPanel(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str());
}

void GPannel::setText(std::string text)
{
    _Text = text;
}

void GPannel::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GPannel::setSize(Vector2 size)
{
    _Size = size;
}

std::string GPannel::getText() const
{
    return _Text;
}

Vector2 GPannel::getPos() const
{
    return _Pos;
}

Vector2 GPannel::getSize() const
{
    return _Size;
}






















// ----------------------- GColorPicker -----------------------

GColorPicker::GColorPicker()
{
    _Pos = {0, 0};
    _Size = {100, 100};
    _Text = "Default Color Picker";
    _Color = {0, 0, 0, 0};
}

GColorPicker::GColorPicker(Vector2 pos, Vector2 size, std::string text, Color color)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
    _Color = color;
}

void GColorPicker::DrawRlibColorPicker() const
{
    Color color = _Color;
    GuiColorPicker(Rectangle{_Pos.x, _Pos.y, _Size.x, _Size.y}, _Text.c_str(), &color);
    const_cast<GColorPicker*>(this)->setColor(color);
}

void GColorPicker::setText(std::string text)
{
    _Text = text;
}

void GColorPicker::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GColorPicker::setSize(Vector2 size)
{
    _Size = size;
}

void GColorPicker::setColor(Color color)
{
    _Color = color;
}

std::string GColorPicker::getText() const
{
    return _Text;
}

Vector2 GColorPicker::getPos() const
{
    return _Pos;
}

Vector2 GColorPicker::getSize() const
{
    return _Size;
}

Color GColorPicker::getColor() const
{
    return _Color;
}























// ----------------------- GProgressBar -----------------------

GProgressBar::GProgressBar()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _TextLeft = "Default Progress Bar left text";
    _TextRight = "Default Progress Bar right text";
    _Value = 0.0F;
    _MinValue = 0.0F;
    _MaxValue = 100.0F;
}

GProgressBar::GProgressBar(Vector2 pos, Vector2 size, std::string textLeft, std::string textRight, float value, float minvalue, float maxvalue)
{
    _Pos = pos;
    _Size = size;
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

void GProgressBar::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GProgressBar::setSize(Vector2 size)
{
    _Size = size;
}

std::string GProgressBar::getTextLeft() const
{
    return _TextLeft;
}

std::string GProgressBar::getTextRight() const
{
    return _TextRight;
}

Vector2 GProgressBar::getPos() const
{
    return _Pos;
}

Vector2 GProgressBar::getSize() const
{
    return _Size;
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

GDropDown::GDropDown()
{
    _Pos = {0, 0};
    _Size = {100, 50};
    _Text = "Default;Drop;Down;value";
    _Active = 0;
    _EditMode = false;
}

GDropDown::GDropDown(Vector2 pos, Vector2 size, std::string text, int active, bool editMode)
{
    _Pos = pos;
    _Size = size;
    _Text = text;
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

void GDropDown::setText(std::string text)
{
    _Text = text;
}

void GDropDown::setPos(Vector2 pos)
{
    _Pos = pos;
}

void GDropDown::setSize(Vector2 size)
{
    _Size = size;
}

void GDropDown::setActive(int active)
{
    _Active = active;
}

void GDropDown::setEditMode(bool editMode)
{
    _EditMode = editMode;
}

std::string GDropDown::getText() const
{
    return _Text;
}

Vector2 GDropDown::getPos() const
{
    return _Pos;
}

Vector2 GDropDown::getSize() const
{
    return _Size;
}

int GDropDown::getActive() const
{
    return _Active;
}

bool GDropDown::getEditMode() const
{
    return _EditMode;
}
