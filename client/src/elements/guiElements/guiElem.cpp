/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#include "guiElem.hpp"

void GUIElement::setPos(Vector2 pos)
{
    this->_Pos = pos;
}

void GUIElement::setSize(Vector2 size)
{
    this->_Size = size;
}

void GUIElement::setText(std::string text)
{
    this->_Text = text;
}

Vector2 GUIElement::getPos() const
{
    return this->_Pos;
}

Vector2 GUIElement::getSize() const
{
    return this->_Size;
}

std::string GUIElement::getText() const
{
    return this->_Text;
}

// ----------------------- GWINDBOW -----------------------

GWindBox::GWindBox(Vector2 pos, Vector2 size, std::string text, bool isOpened) : GUIElement(pos, size, text)
{
    this->_isOpened = isOpened;
}

void GWindBox::DrawRlibWindBox() const
{
    if (this->_isOpened)
        if (GuiWindowBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str()))
            const_cast<GWindBox*>(this)->setIsOpened(this->_isOpened ? false : true);
        
}

void GWindBox::setIsOpened(bool isOpened)
{
    this->_isOpened = isOpened;
}

bool GWindBox::getState() const
{
    return this->_isOpened;
}





















// ----------------------- GButton -----------------------


GButton::GButton(Vector2 pos, Vector2 size, std::string text)  : GUIElement(pos, size, text)
{
    this->_isClicked = false;
}

void GButton::DrawRlibButton() const
{
    if (GuiButton(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str()))
        const_cast<GButton*>(this)->setState(true);
    else
        const_cast<GButton*>(this)->setState(false);
}

void GButton::setState(bool state)
{
    this->_isClicked = state;
}

bool GButton::getState() const
{
    return this->_isClicked;
}























// ----------------------- GCheckBox -----------------------

GCheckBox::GCheckBox(Vector2 pos, Vector2 size, std::string text, bool checked)  : GUIElement(pos, size, text)
{
    this->_isChecked = checked;
}

void GCheckBox::DrawRlibCheckBox() const
{
    bool isChecked = this->_isChecked;
    if (GuiCheckBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &isChecked))
        const_cast<GCheckBox*>(this)->setState(isChecked);
}

void GCheckBox::setState(bool state)
{
    this->_isChecked = state;
}

bool GCheckBox::getState() const
{
    return this->_isChecked;
}





















// ----------------------- GSlider -----------------------

GSlider::GSlider(Vector2 pos, Vector2 size, std::string text, float value, float minvalue, float maxvalue)  : GUIElement(pos, size, text)
{
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GSlider::DrawRlibSlider() const
{
    float value = this->_Value;
    if (GuiSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), TextFormat("%2.2f", value), &value, this->_MinValue, this->_MaxValue))
        const_cast<GSlider*>(this)->setValue(value);
}

void GSlider::setValue(float value)
{
    this->_Value = value;
}

void GSlider::setMaxValue(float value)
{
    this->_MaxValue = value;
}

void GSlider::setMinValue(float value)
{
    this->_MinValue = value;
}

float GSlider::getValue() const
{
    return this->_Value;
}

float GSlider::getMaxValue() const
{
    return this->_MaxValue;
}

float GSlider::getMinValue() const
{
    return this->_MinValue;
}





















// ----------------------- GLIST -----------------------

GList::GList(Vector2 pos, Vector2 size, std::string text)  : GUIElement(pos, size, text)
{
    this->_Value = 0;
    this->_ScrollIndex = 0;
}

void GList::DrawRlibList() const
{
    int value = this->_Value;
    int scrollIndex = this->_ScrollIndex;
    GuiListView(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &scrollIndex, &value);
    const_cast<GList*>(this)->setScrollIndex(scrollIndex);
    const_cast<GList*>(this)->setVal(value);
}

void GList::setScrollIndex(int index)
{
    this->_ScrollIndex = index;
}

void GList::setVal(int value)
{
    this->_Value = value;
}

int GList::getScrollIndex() const
{
    return this->_ScrollIndex;
}

int GList::getValue() const
{
    return this->_Value;
}





















// ----------------------- GLISTEX -----------------------

GListEx::GListEx(Vector2 pos, Vector2 size, std::vector<std::string> list, int active) : GUIElement(pos, size, std::move(list[0]))
{
    this->_List = list;
    this->_Active = active;
}

void GListEx::DrawRlibListEx() const
{
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

void GListEx::setList(std::vector<std::string> list)
{
    this->_List = list;
}

void GListEx::setActive(int active)
{
    this->_Active = active;
}

void GListEx::setFocus(int focus)
{
    this->_Focus = focus;
}

void GListEx::setScrollIndex(int index)
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




















// ----------------------- GTextInput -----------------------

GTextInput::GTextInput(Vector2 pos, Vector2 size, std::string text, int textSize, bool editMode) : GUIElement(pos, size, text)
{
    this->_TextMaxSize = textSize;
    this->_EditMode = editMode;
}

void GTextInput::DrawRlibTextInput() const
{
    char* text = const_cast<char*>(this->_Text.c_str());
    if (GuiTextBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, text, this->_TextMaxSize, this->_EditMode)) {
        const_cast<GTextInput*>(this)->setEditMode(!this->_EditMode);
        
        const_cast<GTextInput*>(this)->setText(text);
    }
}

void GTextInput::setTextMaxSize(int textMaxSize)
{
    this->_TextMaxSize = textMaxSize;
}

void GTextInput::setEditMode(bool editMode)
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



















// ----------------------- GTextInputBox -----------------------



GTextInputBox::GTextInputBox(Vector2 pos, Vector2 size, std::string title, std::string message, std::string buttons, std::string text, int textMaxSize, bool secretViewActive)  : GUIElement(pos, size, text)
{
    this->_Title = title;
    this->_Message = message;
    this->_Buttons = buttons;
    this->_TextMaxSize = textMaxSize;
    this->_SecretViewActive = secretViewActive;
}

void GTextInputBox::DrawRlibTextInputBox() const
{
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
}

void GTextInputBox::setMaxCharacters(int maxCharacters)
{
    this->_TextMaxSize = maxCharacters;
}

void GTextInputBox::setSecretView(bool secretView)
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

void GTextInputBox::setResults(int result)
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






















// ----------------------- GSpinner -----------------------

GSpinner::GSpinner(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode) : GUIElement(pos, size, text)
{
    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GSpinner::DrawRlibSpinner() const
{
    int value = this->_Value;
    if (GuiSpinner(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode))
        const_cast<GSpinner*>(this)->setEditMode(!this->_EditMode);
    const_cast<GSpinner*>(this)->setValue(value);
}

void GSpinner::setValue(int value)
{
    this->_Value = value;
}

void GSpinner::setMaxValue(int value)
{
    this->_MaxValue = value;
}

void GSpinner::setMinValue(int value)
{
    this->_MinValue = value;
}

void GSpinner::setEditMode(bool editMode)
{
    this->_EditMode = editMode;
}

int GSpinner::getValue() const
{
    return this->_Value;
}

int GSpinner::getMaxValue() const
{
    return this->_MaxValue;
}

int GSpinner::getMinValue() const
{
    return this->_MinValue;
}

bool GSpinner::getEditMode() const
{
    return this->_EditMode;
}






















// ----------------------- GValueBox -----------------------


GValueBox::GValueBox(Vector2 pos, Vector2 size, std::string text, int value, int minValue, int maxValue, bool editMode) : GUIElement(pos, size, text)
{

    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GValueBox::DrawRlibValueBox() const
{
    int value = this->_Value;

    if (GuiValueBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode))
        const_cast<GValueBox*>(this)->setEditMode(!this->_EditMode);
    const_cast<GValueBox*>(this)->setValue(value);
}

void GValueBox::setValue(int value)
{
    this->_Value = value;
}

void GValueBox::setMaxValue(int value)
{
    this->_MaxValue = value;
}

void GValueBox::setMinValue(int value)
{
    this->_MinValue = value;
}

void GValueBox::setEditMode(bool editMode)
{
    this->_EditMode = editMode;
}

int GValueBox::getValue() const
{
    return this->_Value;
}

int GValueBox::getMaxValue() const
{
    return this->_MaxValue;
}

int GValueBox::getMinValue() const
{
    return this->_MinValue;
}

bool GValueBox::getEditMode() const
{
    return this->_EditMode;
}






















// ----------------------- GGroup -----------------------

GGroup::GGroup(Vector2 pos, Vector2 size, std::string text) : GUIElement(pos, size, text)
{
    this->_Pos = pos;
    this->_Size = size;
    this->_Text = text;
}

void GGroup::DrawRlibGroup() const
{
    GuiGroupBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
}




















// ----------------------- GToggleGroup -----------------------

GToggleGroup::GToggleGroup(Vector2 pos, Vector2 size, std::string text, int active) : GUIElement(pos, size, text)
{
    this->_Active = active;
}

void GToggleGroup::DrawRlibToggleGroup() const
{
    int active = this->_Active;

    GuiToggleGroup(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
    const_cast<GToggleGroup*>(this)->setActive(active);
}

void GToggleGroup::setActive(int active)
{
    this->_Active = active;
}

int GToggleGroup::getActive() const
{
    return this->_Active;
}



















// ----------------------- GToggleSlider -----------------------

GToggleSlider::GToggleSlider(Vector2 pos, Vector2 size, std::string text, int active) : GUIElement(pos, size, text)
{
    this->_Active = active;
}

void GToggleSlider::DrawRlibToggleSlider() const
{
    int active = this->_Active;

    GuiToggleSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
    const_cast<GToggleSlider*>(this)->setActive(active);
}

void GToggleSlider::setActive(int active)
{
    this->_Active = active;
}

int GToggleSlider::getActive() const
{
    return this->_Active;
}






















// ----------------------- GPannel -----------------------

GPannel::GPannel(Vector2 pos, Vector2 size, std::string text) : GUIElement(pos, size, text)
{
}

void GPannel::DrawRlibPannel() const
{
    GuiPanel(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
}




















// ----------------------- GColorPicker -----------------------

GColorPicker::GColorPicker(Vector2 pos, Vector2 size, std::string text, Color color) : GUIElement(pos, size, text)
{
    this->_Color = color;
}

void GColorPicker::DrawRlibColorPicker() const
{
    Color color = this->_Color;

    GuiColorPicker(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &color);
    const_cast<GColorPicker*>(this)->setColor(color);
}

void GColorPicker::setColor(Color color)
{
    this->_Color = color;
}

Color GColorPicker::getColor() const
{
    return this->_Color;
}























// ----------------------- GProgressBar -----------------------



GProgressBar::GProgressBar(Vector2 pos, Vector2 size, std::string textLeft, std::string textRight, float value, float minvalue, float maxvalue) : GUIElement(pos, size, "default text")
{
    this->_TextLeft = textLeft;
    this->_TextRight = textRight;
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GProgressBar::DrawRlibProgressBar() const
{
    float value = this->_Value;

    GuiProgressBar(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_TextLeft.c_str(), this->_TextRight.c_str(), &value, this->_MinValue, this->_MaxValue);
    const_cast<GProgressBar*>(this)->setValue(value);
}

void GProgressBar::setValue(float value)
{
    this->_Value = value;
}

void GProgressBar::setMaxValue(float value)
{
    this->_MaxValue = value;
}

void GProgressBar::setMinValue(float value)
{
    this->_MinValue = value;
}

void GProgressBar::setTextLeft(std::string text)
{
    this->_TextLeft = text;
}

void GProgressBar::setTextRight(std::string text)
{
    this->_TextRight = text;
}

std::string GProgressBar::getTextLeft() const
{
    return this->_TextLeft;
}

std::string GProgressBar::getTextRight() const
{
    return this->_TextRight;
}

float GProgressBar::getValue() const
{
    return this->_Value;
}

float GProgressBar::getMaxValue() const
{
    return this->_MaxValue;
}

float GProgressBar::getMinValue() const
{
    return this->_MinValue;
}






















// ----------------------- GDropDown -----------------------

GDropDown::GDropDown(Vector2 pos, Vector2 size, std::string text, int active, bool editMode) : GUIElement(pos, size, text)
{
    this->_Active = active;
    this->_EditMode = editMode;
}

void GDropDown::DrawRlibDropDown() const
{
    int active = this->_Active;

    if (GuiDropdownBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active, this->_EditMode))
        const_cast<GDropDown*>(this)->setEditMode(!this->_EditMode);
    const_cast<GDropDown*>(this)->setActive(active);
}

void GDropDown::setActive(int active)
{
    this->_Active = active;
}

void GDropDown::setEditMode(bool editMode)
{
    this->_EditMode = editMode;
}

int GDropDown::getActive() const
{
    return this->_Active;
}

bool GDropDown::getEditMode() const
{
    return this->_EditMode;
}
