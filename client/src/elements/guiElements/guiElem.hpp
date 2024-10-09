/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#pragma once

#include "../../include.hpp"

struct Vector2 {
    float x;
    float y;
};
class GUIElement {
    public:
    GUIElement(Vector2 pos = {0, 0}, Vector2 size = {100, 50}, std::string text = "default")
        : _Text(text), _Pos(pos), _Size(size) {}
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    protected:
        std::string _Text;
        Vector2 _Pos;
        Vector2 _Size;
};

class GWindBox : public GUIElement {
public:
    GWindBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default window box text", bool isOpened = false);
    ~GWindBox() = default;

    void DrawRlibWindBox() const;

    void setIsOpened(bool isOpened);

    bool getState() const;
private:
    bool _isOpened;

};

class GButton : public GUIElement {
public:
    GButton(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default button text");
    ~GButton() = default;

    void DrawRlibButton() const;

    void setState(bool state);

    bool getState() const;
private:
    bool _isClicked = false;
};

class GCheckBox : public GUIElement {
public:
    GCheckBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default checkbox text", bool checked = false);
    ~GCheckBox() = default;

    void DrawRlibCheckBox() const;

    void setState(bool state);

    bool getState() const;
private:
    bool _isChecked;
    
};

class GSlider : public GUIElement {
public:
    GSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default slider text", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F);
    ~GSlider() = default;

    void DrawRlibSlider() const;

    void setValue(float value);
    void setMaxValue(float value);
    void setMinValue(float value);

    float getValue() const;
    float getMaxValue() const;
    float getMinValue() const;

private:
    float _value;
    float _maxValue;
    float _minValue;
};


class GList : public GUIElement {
public:
    GList(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;list;text");
    ~GList() = default;

    void DrawRlibList() const;

    void setScrollIndex(int index);
    void setVal(int value);

    int getScrollIndex() const;
    int getValue() const;
private:
    int _ScrollIndex;
    int _Value;
};

class GListEx : public GUIElement {
public:
    GListEx(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::vector<std::string> list = {"default", "list", "text"}, int active = 0);
    ~GListEx() = default;

    void DrawRlibListEx() const;

    void setList(std::vector<std::string> list);
    void setActive(int active);
    void setFocus(int focus);
    void setScrollIndex(int index);

    int getScrollIndex() const;
    int getFocus() const;
    int getActive() const;
    std::vector<std::string> getList() const;
private:
    std::vector<std::string> _list;
    int _active;
    int _ScrollIndex;
    int _Active;
    int _Focus;
};

class GTextInput : public GUIElement {
public:
    GTextInput(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default text", int textMaxSize = 100, bool editMode = false);
    ~GTextInput() = default;

    void DrawRlibTextInput() const;

    void setTextMaxSize(int textmaxSize);
    void setEditMode(bool editMode);

    int getTextMaxSize() const;
    bool getEditMode() const;
private:
    int _TextMaxSize;
    bool _EditMode;
};

class GTextInputBox : public GUIElement {
public:
    GTextInputBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string title = "default title", std::string message = "default message", std::string buttons = "default;buttons", std::string text = "default text", int textMaxSize = 100, bool secretViewActive = NULL);
    ~GTextInputBox() = default;

    void DrawRlibTextInputBox() const;

    void setMaxCharacters(int maxCharacters);
    void setSecretView(bool secretView);
    void setTitle(std::string title);
    void setMessage(std::string message);
    void setButtons(std::string buttons);
    void setResults(int result);

    int getMaxCharacters() const;
    bool getSecretView() const;
    std::string getTitle() const;
    std::string getMessage() const;
    std::string getButtons() const;
    int getResults() const;
private:
    std::string _Title;
    std::string _Message;
    std::string _Buttons;
    int _TextMaxSize;
    bool _SecretViewActive;
    int _Result;    
};


class GSpinner : public GUIElement {
public:
    GSpinner(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default spinner text", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false);
    ~GSpinner() = default;

    void DrawRlibSpinner() const;

    void setValue(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);

    int getValue() const;
    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;
private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GValueBox : public GUIElement {
public:
    GValueBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default value box text", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false);
    ~GValueBox() = default;

    void DrawRlibValueBox() const;

    void setValue(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);

    int getValue() const;
    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;
private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GGroup : public GUIElement {
public:
    GGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default group text");
    ~GGroup() = default;

    void DrawRlibGroup() const;
};

class GToggleGroup : public GUIElement {
public:
    GToggleGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle;group", int active = 0);
    ~GToggleGroup() = default;

    void DrawRlibToggleGroup() const;

    void setActive(int active);


    int getActive() const;
private:
    int _Active;
};

class GToggleSlider : public GUIElement {
public:
    GToggleSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle", int active = 0);
    ~GToggleSlider() = default;

    void DrawRlibToggleSlider() const;

    void setActive(int active);

    int getActive() const;
private:
    int _Active;
};

class GPannel : public GUIElement {
public:
    GPannel(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default pannel text");
    ~GPannel() = default;

    void DrawRlibPannel() const;
};

class GColorPicker : public GUIElement {
public:
    GColorPicker(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default color picker text", Color color = WHITE);
    ~GColorPicker() = default;

    void DrawRlibColorPicker() const;

    void setColor(Color color);

    Color getColor() const;
private:
    Color _Color;
};


class GProgressBar : public GUIElement {
public:
    GProgressBar(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string textLeft = "default progress bar left text", std::string textRight = "default progress bar right text", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F);
    ~GProgressBar() = default;

    void DrawRlibProgressBar() const;

    void setValue(float value);
    void setMaxValue(float value);
    void setMinValue(float value);
    void setTextLeft(std::string text);
    void setTextRight(std::string text);

    std::string getTextLeft() const;
    std::string getTextRight() const;
    float getValue() const;
    float getMaxValue() const;
    float getMinValue() const;
private:
    std::string _TextLeft;
    std::string _TextRight;
    float _Value;
    float _MaxValue;
    float _MinValue;
};

class GDropDown : public GUIElement {
public:
    GDropDown(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;drop;down;val", int active = 0, bool editMode = false);
    ~GDropDown() = default;

    void DrawRlibDropDown() const;

    void setActive(int active);
    void setEditMode(bool editMode);

    int getActive() const;
    bool getEditMode() const;
private:
    int _Active;
    bool _EditMode;
};