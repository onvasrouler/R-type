/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiElem
*/

#pragma once

#include "../../include.hpp"

class GUIElement {
    public:
    GUIElement(Vector2 pos = {0, 0}, Vector2 size = {100, 50}, std::string text = "default", std::string id = "default", bool display = false)
        : _Text(text), _Pos(pos), _Size(size), _Id(id), _Display(display) {}
    void setText(std::string text);
    void setPos(Vector2 pos);
    void setSize(Vector2 size);
    void setValue(std::string value);
    void setId(std::string id = "default");
    void setDisplay(bool state);

    std::string getText() const;
    Vector2 getPos() const;
    Vector2 getSize() const;
    std::string getValue() const;
    std::string getId() const;
    bool getDisplay() const;
    protected:
        std::string _Text;
        Vector2 _Pos;
        Vector2 _Size;
        std::string _Value;
        std::string _Id;
        bool _Display;
};

class GWindBox : public GUIElement {
public:
    GWindBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default window box text", std::string id = "default", bool isOpened = false, bool display = false);
    ~GWindBox() = default;

    void DrawRlibWindBox() const;

    void setIsOpened(bool isOpened);
private:
    bool _isOpened;

};

class GButton : public GUIElement {
public:
    GButton(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default button text", std::string id = "default", bool display = false);
    ~GButton() = default;

    void DrawRlibButton() const;

    void setClicked(bool state);
private:
    bool _isClicked = false;
};

class GCheckBox : public GUIElement {
public:
    GCheckBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default checkbox text", std::string id = "default", bool checked = false, bool display = false);
    ~GCheckBox() = default;

    void DrawRlibCheckBox() const;

    void setChecked(bool state);
private:
    bool _isChecked;
    
};

class GSlider : public GUIElement {
public:
    GSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default slider text", std::string id = "default", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F, bool display = false);
    ~GSlider() = default;

    void DrawRlibSlider() const;

    void setSliderValue(float value);
    void setMaxValue(float value);
    void setMinValue(float value);

    float getMaxValue() const;
    float getMinValue() const;

private:
    float _Value;
    float _MaxValue;
    float _MinValue;
};


class GList : public GUIElement {
public:
    GList(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;list;text", std::string id = "default", bool display = false);
    ~GList() = default;

    void DrawRlibList() const;

    void setScrollIndex(int index);
    void setVal(int value);

    int getScrollIndex() const;
private:
    int _ScrollIndex;
    int _Value;
};

class GListEx : public GUIElement {
public:
    GListEx(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string id = "default", std::vector<std::string> list = {"default", "list", "text"}, int active = 0, bool display = false);
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
    std::vector<std::string> _List;
    int _active;
    int _ScrollIndex;
    int _Active;
    int _Focus;
};

class GTextInput : public GUIElement {
public:
    GTextInput(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default text", std::string id = "default", int textMaxSize = 100, bool editMode = false, bool display = false);
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
    GTextInputBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string id = "default", std::string title = "default title", std::string message = "default message", std::string buttons = "default;buttons", std::string text = "default text", int textMaxSize = 100, bool secretViewActive = NULL, bool display = false);
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
    GSpinner(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default spinner text", std::string id = "default", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false, bool display = false);
    ~GSpinner() = default;

    void DrawRlibSpinner() const;

    void setSpin(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);

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
    GValueBox(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default value box text", std::string id = "default", int value = 0, int minValue = 0, int maxValue = 100, bool editMode = false, bool display = false);
    ~GValueBox() = default;

    void DrawRlibValueBox() const;

    void setBoxValue(int value);
    void setMaxValue(int value);
    void setMinValue(int value);
    void setEditMode(bool editMode);

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
    GGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default group text", std::string id = "default", bool display = false);
    ~GGroup() = default;

    void DrawRlibGroup() const;
};

class GToggleGroup : public GUIElement {
public:
    GToggleGroup(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle;group", std::string id = "default", int active = 0, bool display = false);
    ~GToggleGroup() = default;

    void DrawRlibToggleGroup() const;

    void setActive(int active);


    int getActive() const;
private:
    int _Active;
};

class GToggleSlider : public GUIElement {
public:
    GToggleSlider(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;toggle", std::string id = "default", int active = 0, bool display = false);
    ~GToggleSlider() = default;

    void DrawRlibToggleSlider() const;

    void setActive(int active);

    int getActive() const;
private:
    int _Active;
};

class GPannel : public GUIElement {
public:
    GPannel(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default pannel text", std::string id = "default", bool display = false);
    ~GPannel() = default;

    void DrawRlibPannel() const;
};

class GColorPicker : public GUIElement {
public:
    GColorPicker(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default color picker text", std::string id = "default", Color color = WHITE, bool display = false);
    ~GColorPicker() = default;

    void DrawRlibColorPicker() const;

    void setColor(Color color);

    Color getColor() const;
private:
    Color _Color;
};


class GProgressBar : public GUIElement {
public:
    GProgressBar(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string id = "default", std::string textLeft = "default progress bar left text", std::string textRight = "default progress bar right text", float value = 0.0F, float minvalue = 0.0F, float maxvalue = 100.0F, bool display = false);
    ~GProgressBar() = default;

    void DrawRlibProgressBar() const;

    void setProgress(float value);
    void setMaxValue(float value);
    void setMinValue(float value);
    void setTextLeft(std::string text);
    void setTextRight(std::string text);

    std::string getTextLeft() const;
    std::string getTextRight() const;
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
    GDropDown(Vector2 pos = {0, 0}, Vector2 size = {100, 100}, std::string text = "default;drop;down;val", std::string id = "default", int active = 0, bool editMode = false, bool display = false);
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