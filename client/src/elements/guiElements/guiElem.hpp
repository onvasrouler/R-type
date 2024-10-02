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
    GWindBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default window box text");
    ~GWindBox() = default;
    void DrawRlibWindBox() const;

    void setState(bool state);
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    bool _isOpened;

};

class GButton {
public:
    GButton();
    GButton(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default button text");
    ~GButton() = default;
    void DrawRlibButton() const;

    void setAction(std::function<void()> action);

    void setState(bool state);
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    bool _isClicked = false;
    std::function<void()> _action;
};

class GCheckBox {
public:
    GCheckBox();
    GCheckBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default checkbox text", bool checked = false);
    ~GCheckBox() = default;
    void DrawRlibCheckBox() const;

    void setState(bool state);
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
    //void setAction(std::function<void()> action);
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
    //void setAction(std::function<void()> action);
private:
    std::string _text;
    Vector2 _pos;
    Vector2 _size;
    int _ScrollIndex;
    int _Value;
    //std::function<void()> _action;
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