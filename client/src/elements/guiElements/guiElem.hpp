/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#pragma once

#include "../../include.hpp"

class GWindBox {
public:
    GWindBox();
    GWindBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default window box text", bool isOpened = false);
    ~GWindBox() = default;

    void DrawRlibWindBox() const;

    void setIsOpened(bool isOpened);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    bool getState() const;
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    std::function<void()> _action;
    bool _isOpened;

};

class GButton {
public:
    GButton();
    GButton(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default button text", std::function<void (const std::string &)> action = nullptr);
    ~GButton() = default;

    void DrawRlibButton() const;

    void setState(bool state);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    bool getState() const;
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    bool _isClicked = false;
    std::function<void (const std::string &)> _Action;
};

class GCheckBox {
public:
    GCheckBox();
    GCheckBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default checkbox text", bool checked = false);
    ~GCheckBox() = default;

    void DrawRlibCheckBox() const;

    void setState(bool state);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    bool getState() const;
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    bool _isChecked;
    
};

class GSlider {
public:
    GSlider();
    GSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default slider text", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F);
    ~GSlider() = default;

    void DrawRlibSlider() const;

    void setValue(float value);
    void setMaxValue(float value);
    void setMinValue(float value);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    float getValue() const;
    float getMaxValue() const;
    float getMinValue() const;

private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    float _value;
    float _maxValue;
    float _minValue;
    //std::function<void()> _action;
};


class GList {
public:
    GList();
    GList(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;list;text");
    ~GList() = default;

    void DrawRlibList() const;

    void setScrollIndex(int index);
    void setVal(int value);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getScrollIndex() const;
    int getValue() const;
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    int _ScrollIndex;
    int _Value;
};

class GListEx {
public:
    GListEx();
    GListEx(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::vector<std::string> list = {"default", "list", "text"}, int active = 0);
    ~GListEx() = default;

    void DrawRlibListEx() const;

    void setList(std::vector<std::string> list);
    void setActive(int active);
    void setFocus(int focus);
    void setScrollIndex(int index);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getScrollIndex() const;
    int getFocus() const;
    int getActive() const;
    std::vector<std::string> getList() const;
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    std::vector<std::string> _list;
    int _active;
    int _ScrollIndex;
    int _Active;
    int _Focus;
};

class GTextInput {
public:
    GTextInput();
    GTextInput(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default text", int textMaxSize = 100, bool editMode = false);
    ~GTextInput() = default;

    void DrawRlibTextInput() const;

    void setText(std::string text);
    void setTextMaxSize(int textmaxSize);
    void setEditMode(bool editMode);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    int getTextMaxSize() const;
    bool getEditMode() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
private:
    Vector2 _Pos;
    Vector2 _Size;
    std::string _Text;
    int _TextMaxSize;
    bool _EditMode;
};

class GTextInputBox {
public:
    GTextInputBox();
    GTextInputBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string title = "default title", std::string message = "default message", std::string buttons = "default;buttons", std::string text = "default text", int textMaxSize = 100, bool secretViewActive = NULL);
    ~GTextInputBox() = default;

    void DrawRlibTextInputBox() const;

    void setText(std::string text);
    void setMaxCharacters(int maxCharacters);
    void setSecretView(bool secretView);
    void setTitle(std::string title);
    void setMessage(std::string message);
    void setButtons(std::string buttons);
    void setResults(int result);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    int getMaxCharacters() const;
    bool getSecretView() const;
    std::string getTitle() const;
    std::string getMessage() const;
    std::string getButtons() const;
    int getResults() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
private:
    Vector2 _Pos;
    Vector2 _Size;
    std::string _Title;
    std::string _Message;
    std::string _Buttons;
    std::string _Text;
    int _TextMaxSize;
    bool _SecretViewActive;
    int _Result;    
};


class GSpinner {
public:
    GSpinner();
    GSpinner(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default spinner text", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false);
    ~GSpinner() = default;

    void DrawRlibSpinner() const;

    void setValue(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getValue() const;
    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GValueBox {
public:
    GValueBox();
    GValueBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default value box text", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false);
    ~GValueBox() = default;

    void DrawRlibValueBox() const;

    void setValue(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getValue() const;
    int getMaxValue() const;
    int getMinValue() const;
    bool getEditMode() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GGroup {
public:
    GGroup();
    GGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default group text");
    ~GGroup() = default;

    void DrawRlibGroup() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
};

class GToggleGroup {
public:
    GToggleGroup();
    GToggleGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle;group", int active = 0);
    ~GToggleGroup() = default;

    void DrawRlibToggleGroup() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);
    void setActive(int active);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getActive() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    int _Active;
};

class GToggleSlider {
public:
    GToggleSlider();
    GToggleSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle", int active = 0);
    ~GToggleSlider() = default;

    void DrawRlibToggleSlider() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);
    void setActive(int active);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getActive() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    int _Active;
};

class GPannel {
public:
    GPannel();
    GPannel(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default pannel text");
    ~GPannel() = default;

    void DrawRlibPannel() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
};

class GColorPicker {
public:
    GColorPicker();
    GColorPicker(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default color picker text", Color color = WHITE);
    ~GColorPicker() = default;

    void DrawRlibColorPicker() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);
    void setColor(Color color);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    Color getColor() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    Color _Color;
};


class GProgressBar {
public:
    GProgressBar();
    GProgressBar(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string textLeft = "default progress bar left text", std::string textRight = "default progress bar right text", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F);
    ~GProgressBar() = default;

    void DrawRlibProgressBar() const;

    void setValue(float value);
    void setMaxValue(float value);
    void setMinValue(float value);
    void setTextLeft(std::string text);
    void setTextRight(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    std::string getTextLeft() const;
    std::string getTextRight() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    float getValue() const;
    float getMaxValue() const;
    float getMinValue() const;
private:
    std::string _TextLeft;
    std::string _TextRight;
    Vector2 _Pos;
    Vector2 _Size;
    float _Value;
    float _MaxValue;
    float _MinValue;
};

class GDropDown {
public:
    GDropDown();
    GDropDown(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;drop;down;val", int active = 0, bool editMode = false);
    ~GDropDown() = default;

    void DrawRlibDropDown() const;

    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);
    void setActive(int active);
    void setEditMode(bool editMode);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    int getActive() const;
    bool getEditMode() const;
private:
    std::string _Text;
    Vector2 _Pos;
    Vector2 _Size;
    int _Active;
    bool _EditMode;
};