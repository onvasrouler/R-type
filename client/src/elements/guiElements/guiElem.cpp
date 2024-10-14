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

void GUIElement::setValue(std::string value)
{
    this->_Value = value;
}

void GUIElement::setId(std::string id)
{
    this->_Id = id;
}

void GUIElement::setDisplay(bool state)
{
    this->_Display = state;
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

std::string GUIElement::getValue() const
{
    return this->_Value;
}

std::string GUIElement::getId() const
{
    return this->_Id;
}

bool GUIElement::getDisplay() const
{
    return this->_Display;
}

// ----------------------- GWINDBOW -----------------------

GWindBox::GWindBox(Vector2 pos, Vector2 size, std::string text, std::string id, bool isOpened, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_isOpened = isOpened;
}

void GWindBox::DrawRlibWindBox() const
{
    if (!this->_Display)
        return;
    if (this->_isOpened)
        if (GuiWindowBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str()))
            const_cast<GWindBox*>(this)->setIsOpened(this->_isOpened ? false : true);
        
}

void GWindBox::setIsOpened(bool isOpened)
{
    this->_isOpened = isOpened;
    std::string value = isOpened ? "true" : "false";
    this->setValue(value);
}




















// ----------------------- GButton -----------------------


GButton::GButton(Vector2 pos, Vector2 size, std::string text, std::string id, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_isClicked = false;
}

void GButton::DrawRlibButton() const
{
    if (!this->_Display)
        return;
    if (GuiButton(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str()))
        const_cast<GButton*>(this)->setClicked(true);
    else
        const_cast<GButton*>(this)->setClicked(false);
}

void GButton::setClicked(bool state)
{
    this->_isClicked = state;
    this->setValue(state ? "true" : "false");
}






















// ----------------------- GCheckBox -----------------------

GCheckBox::GCheckBox(Vector2 pos, Vector2 size, std::string text, std::string id, bool checked, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_isChecked = checked;
}

void GCheckBox::DrawRlibCheckBox() const
{
    if (!this->_Display)
        return;
    bool isChecked = this->_isChecked;
    if (GuiCheckBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &isChecked))
        const_cast<GCheckBox*>(this)->setChecked(isChecked);
}

void GCheckBox::setChecked(bool state)
{
    this->_isChecked = state;
    this->setValue(state ? "true" : "false");
}




















// ----------------------- GSlider -----------------------

GSlider::GSlider(Vector2 pos, Vector2 size, std::string text, std::string id, float value, float minvalue, float maxvalue, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GSlider::DrawRlibSlider() const
{
    if (!this->_Display)
        return;
    float value = this->_Value;
    if (GuiSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), TextFormat("%2.2f", value), &value, this->_MinValue, this->_MaxValue))
        const_cast<GSlider*>(this)->setSliderValue(value);
}

void GSlider::setSliderValue(float value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
}

void GSlider::setMaxValue(float value)
{
    this->_MaxValue = value;
}

void GSlider::setMinValue(float value)
{
    this->_MinValue = value;
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

GList::GList(Vector2 pos, Vector2 size, std::string text, std::string id, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Value = 0;
    this->_ScrollIndex = 0;
}

void GList::DrawRlibList() const
{
    if (!this->_Display)
        return;
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
    this->setValue(std::to_string(value));
}

int GList::getScrollIndex() const
{
    return this->_ScrollIndex;
}




















// ----------------------- GLISTEX -----------------------

GListEx::GListEx(Vector2 pos, Vector2 size, std::string id, std::vector<std::string> list, int active, bool display) : GUIElement(pos, size, "default", id, display)
{
    this->_List = list;
    this->_Active = active;
}

void GListEx::DrawRlibListEx() const
{
    if (!this->_Display)
        return;
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
    this->setValue(std::to_string(active));
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

GTextInput::GTextInput(Vector2 pos, Vector2 size, std::string text, std::string id, int textSize, bool editMode, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_TextMaxSize = textSize;
    this->_EditMode = editMode;
}

void GTextInput::DrawRlibTextInput() const
{
    if (!this->_Display)
        return;
    char* text = const_cast<char*>(this->_Text.c_str());
    if (GuiTextBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, text, this->_TextMaxSize, this->_EditMode)) {
        const_cast<GTextInput*>(this)->setEditMode(!this->_EditMode);
        
        const_cast<GTextInput*>(this)->setText(text);
        const_cast<GTextInput*>(this)->setValue(text);
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



GTextInputBox::GTextInputBox(Vector2 pos, Vector2 size, std::string id, std::string title, std::string message, std::string buttons, std::string text, int textMaxSize, bool secretViewActive, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Title = title;
    this->_Message = message;
    this->_Buttons = buttons;
    this->_TextMaxSize = textMaxSize;
    this->_SecretViewActive = secretViewActive;
}

void GTextInputBox::DrawRlibTextInputBox() const
{
    if (!this->_Display)
        return;
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

GSpinner::GSpinner(Vector2 pos, Vector2 size, std::string text, std::string id, int value, int minValue, int maxValue, bool editMode, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GSpinner::DrawRlibSpinner() const
{
    if (!this->_Display)
        return;
    int value = this->_Value;
    if (GuiSpinner(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode))
        const_cast<GSpinner*>(this)->setEditMode(!this->_EditMode);
    const_cast<GSpinner*>(this)->setSpin(value);
}

void GSpinner::setSpin(int value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
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


GValueBox::GValueBox(Vector2 pos, Vector2 size, std::string text, std::string id, int value, int minValue, int maxValue, bool editMode, bool display) : GUIElement(pos, size, text, id, display)
{

    this->_Value = value;
    this->_MinValue = minValue;
    this->_MaxValue = maxValue;
    this->_EditMode = editMode;
}

void GValueBox::DrawRlibValueBox() const
{
    if (!this->_Display)
        return;
    int value = this->_Value;

    if (GuiValueBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &value, this->_MinValue, this->_MaxValue, this->_EditMode))
        const_cast<GValueBox*>(this)->setEditMode(!this->_EditMode);
    const_cast<GValueBox*>(this)->setBoxValue(value);
}

void GValueBox::setBoxValue(int value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
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

GGroup::GGroup(Vector2 pos, Vector2 size, std::string text, std::string id, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Pos = pos;
    this->_Size = size;
    this->_Text = text;
}

void GGroup::DrawRlibGroup() const
{
    if (!this->_Display)
        return;
    GuiGroupBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
}




















// ----------------------- GToggleGroup -----------------------

GToggleGroup::GToggleGroup(Vector2 pos, Vector2 size, std::string text, std::string id, int active, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Active = active;
}

void GToggleGroup::DrawRlibToggleGroup() const
{
    if (!this->_Display)
        return;
    int active = this->_Active;

    GuiToggleGroup(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
    const_cast<GToggleGroup*>(this)->setActive(active);
}

void GToggleGroup::setActive(int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

int GToggleGroup::getActive() const
{
    return this->_Active;
}



















// ----------------------- GToggleSlider -----------------------

GToggleSlider::GToggleSlider(Vector2 pos, Vector2 size, std::string text, std::string id, int active, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Active = active;
}

void GToggleSlider::DrawRlibToggleSlider() const
{
    if (!this->_Display)
        return;
    int active = this->_Active;

    GuiToggleSlider(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active);
    const_cast<GToggleSlider*>(this)->setActive(active);
}

void GToggleSlider::setActive(int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
}

int GToggleSlider::getActive() const
{
    return this->_Active;
}






















// ----------------------- GPannel -----------------------

GPannel::GPannel(Vector2 pos, Vector2 size, std::string text, std::string id, bool display) : GUIElement(pos, size, text, id, display)
{
}

void GPannel::DrawRlibPannel() const
{
    if (!this->_Display)
        return;
    GuiPanel(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str());
}




















// ----------------------- GColorPicker -----------------------

GColorPicker::GColorPicker(Vector2 pos, Vector2 size, std::string text, std::string id, Color color, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Color = color;
}

void GColorPicker::DrawRlibColorPicker() const
{
    if (!this->_Display)
        return;
    Color color = this->_Color;

    GuiColorPicker(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &color);
    const_cast<GColorPicker*>(this)->setColor(color);
}

void GColorPicker::setColor(Color color)
{
    this->_Color = color;
    this->setValue(std::to_string(color.r) + " " + std::to_string(color.g) + " " + std::to_string(color.b) + " " + std::to_string(color.a));
}

Color GColorPicker::getColor() const
{
    return this->_Color;
}























// ----------------------- GProgressBar -----------------------



GProgressBar::GProgressBar(Vector2 pos, Vector2 size, std::string id, std::string textLeft, std::string textRight, float value, float minvalue, float maxvalue, bool display) : GUIElement(pos, size, "default", id, display)
{
    this->_TextLeft = textLeft;
    this->_TextRight = textRight;
    this->_Value = value;
    this->_MinValue = minvalue;
    this->_MaxValue = maxvalue;
}

void GProgressBar::DrawRlibProgressBar() const
{
    if (!this->_Display)
        return;
    float value = this->_Value;

    GuiProgressBar(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_TextLeft.c_str(), this->_TextRight.c_str(), &value, this->_MinValue, this->_MaxValue);
    const_cast<GProgressBar*>(this)->setProgress(value);
}

void GProgressBar::setProgress(float value)
{
    this->_Value = value;
    this->setValue(std::to_string(value));
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

float GProgressBar::getMaxValue() const
{
    return this->_MaxValue;
}

float GProgressBar::getMinValue() const
{
    return this->_MinValue;
}






















// ----------------------- GDropDown -----------------------

GDropDown::GDropDown(Vector2 pos, Vector2 size, std::string text, std::string id, int active, bool editMode, bool display) : GUIElement(pos, size, text, id, display)
{
    this->_Active = active;
    this->_EditMode = editMode;
}

void GDropDown::DrawRlibDropDown() const
{
    if (!this->_Display)
        return;
    int active = this->_Active;

    if (GuiDropdownBox(Rectangle{this->_Pos.x, this->_Pos.y, this->_Size.x, this->_Size.y}, this->_Text.c_str(), &active, this->_EditMode))
        const_cast<GDropDown*>(this)->setEditMode(!this->_EditMode);
    const_cast<GDropDown*>(this)->setActive(active);
}

void GDropDown::setActive(int active)
{
    this->_Active = active;
    this->setValue(std::to_string(active));
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
