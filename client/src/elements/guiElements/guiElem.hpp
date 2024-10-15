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
    GUIElement(const Vector2 pos = {0, 0}, const Vector2 size = {100, 50}, const std::string text = "default", const std::string id = "default", const bool display = false)
        : _Text(text), _Pos(pos), _Size(size), _Id(id), _Display(display) {}
    void setText(const std::string text);
    void setPos(const Vector2 pos);
    void setSize(const Vector2 size);
    void setValue(const std::string value);
    void setId(const std::string id = "default");
    void setDisplay(const bool state);

    const std::string getText() const;
    const Vector2 getPos() const;
    const Vector2 getSize() const;
    const std::string getValue() const;
    const std::string getId() const;
    const bool getDisplay() const;
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
    GWindBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default window box text", const std::string id = "default", const bool isOpened = false, const bool display = false);
    ~GWindBox() = default;

    void DrawRlibWindBox() const;

    void setIsOpened(const bool isOpened);
private:
    bool _isOpened;

};

class GButton : public GUIElement {
public:
    GButton(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default button text", const std::string id = "default", const bool display = false);
    ~GButton() = default;

    void DrawRlibButton() const;

    void setClicked(const bool state);
private:
    bool _isClicked = false;
};

class GCheckBox : public GUIElement {
public:
    GCheckBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default checkbox text", const std::string id = "default", const bool checked = false, const bool display = false);
    ~GCheckBox() = default;

    void DrawRlibCheckBox() const;

    void setChecked(const bool state);
private:
    bool _isChecked;
    
};

class GSlider : public GUIElement {
public:
    GSlider(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default slider text", const std::string id = "default", const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = false);
    ~GSlider() = default;

    void DrawRlibSlider() const;

    void setSliderValue(const float value);
    void setMaxValue(const float value);
    void setMinValue(const float value);

    const float getMaxValue() const;
    const float getMinValue() const;

private:
    float _Value;
    float _MaxValue;
    float _MinValue;
};


class GList : public GUIElement {
public:
    GList(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;list;text", const std::string id = "default", const bool display = false);
    ~GList() = default;

    void DrawRlibList() const;

    void setScrollIndex(const int index);
    void setVal(const int value);

    const int getScrollIndex() const;
private:
    int _ScrollIndex;
    int _Value;
};

class GListEx : public GUIElement {
public:
    GListEx(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string id = "default", const std::vector<std::string> list = {"default", "list", "text"}, const int active = 0, const bool display = false);
    ~GListEx() = default;

    void DrawRlibListEx() const;

    void setList(const std::vector<std::string> list);
    void setActive(const int active);
    void setFocus(const int focus);
    void setScrollIndex(const int index);

    const int getScrollIndex() const;
    const int getFocus() const;
    const int getActive() const;
    const std::vector<std::string> getList() const;
private:
    std::vector<std::string> _List;
    int _active;
    int _ScrollIndex;
    int _Active;
    int _Focus;
};

class GTextInput : public GUIElement {
public:
    GTextInput(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default text", const std::string id = "default", const int textMaxSize = 100, const bool editMode = false, const bool display = false);
    ~GTextInput() = default;

    void DrawRlibTextInput() const;

    void setTextMaxSize(const int textmaxSize);
    void setEditMode(const bool editMode);

    const int getTextMaxSize() const;
    const bool getEditMode() const;
private:
    int _TextMaxSize;
    bool _EditMode;
};

class GTextInputBox : public GUIElement {
public:
    GTextInputBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string id = "default", const std::string title = "default title", const std::string message = "default message", const std::string buttons = "default;buttons", const std::string text = "default text", const int textMaxSize = 100, const bool secretViewActive = NULL, const bool display = false);
    ~GTextInputBox() = default;

    void DrawRlibTextInputBox() const;

    void setMaxCharacters(const int maxCharacters);
    void setSecretView(const bool secretView);
    void setTitle(const std::string title);
    void setMessage(const std::string message);
    void setButtons(const std::string buttons);
    void setResults(const int result);

    const int getMaxCharacters() const;
    const bool getSecretView() const;
    const std::string getTitle() const;
    const std::string getMessage() const;
    const std::string getButtons() const;
    const int getResults() const;
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
    GSpinner(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default spinner text", const std::string id = "default", const int value = 0, const int minValue = 0, const int maxValue = 100, const bool editMode = false, const bool display = false);
    ~GSpinner() = default;

    void DrawRlibSpinner() const;

    void setSpin(const int value);
    void setMaxValue(const int value);
    void setMinValue(const int value);
    void setEditMode(const bool editMode);

    const int getMaxValue() const;
    const int getMinValue() const;
    const bool getEditMode() const;
private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GValueBox : public GUIElement {
public:
    GValueBox(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default value box text", const std::string id = "default", const int value = 0, const int minValue = 0, const int maxValue = 100, const bool editMode = false, const bool display = false);
    ~GValueBox() = default;

    void DrawRlibValueBox() const;

    void setBoxValue(const int value);
    void setMaxValue(const int value);
    void setMinValue(const int value);
    void setEditMode(const bool editMode);

    const int getMaxValue() const;
    const int getMinValue() const;
    const bool getEditMode() const;
private:
    int _Value;
    int _MaxValue;
    int _MinValue;
    bool _EditMode;
};

class GGroup : public GUIElement {
public:
    GGroup(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default group text", const std::string id = "default", const bool display = false);
    ~GGroup() = default;

    void DrawRlibGroup() const;
};

class GToggleGroup : public GUIElement {
public:
    GToggleGroup(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;toggle;group", const std::string id = "default", const int active = 0, const bool display = false);
    ~GToggleGroup() = default;

    void DrawRlibToggleGroup() const;

    void setActive(const int active);


    const int getActive() const;
private:
    int _Active;
};

class GToggleSlider : public GUIElement {
public:
    GToggleSlider(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;toggle", const std::string id = "default", const int active = 0, const bool display = false);
    ~GToggleSlider() = default;

    void DrawRlibToggleSlider() const;

    void setActive(const int active);

    const int getActive() const;
private:
    int _Active;
};

class GPannel : public GUIElement {
public:
    GPannel(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default pannel text", const std::string id = "default", const bool display = false);
    ~GPannel() = default;

    void DrawRlibPannel() const;
};

class GColorPicker : public GUIElement {
public:
    GColorPicker(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default color picker text", const std::string id = "default", const Color color = WHITE, const bool display = false);
    ~GColorPicker() = default;

    void DrawRlibColorPicker() const;

    void setColor(const Color color);

    const Color getColor() const;
private:
    Color _Color;
};


class GProgressBar : public GUIElement {
public:
    GProgressBar(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string id = "default", const std::string textLeft = "default progress bar left text", const std::string textRight = "default progress bar right text", const float value = 0.0F, const float minvalue = 0.0F, const float maxvalue = 100.0F, const bool display = false);
    ~GProgressBar() = default;

    void DrawRlibProgressBar() const;

    void setProgress(const float value);
    void setMaxValue(const float value);
    void setMinValue(const float value);
    void setTextLeft(const std::string text);
    void setTextRight(const std::string text);

    const std::string getTextLeft() const;
    const std::string getTextRight() const;
    const float getMaxValue() const;
    const float getMinValue() const;
private:
    std::string _TextLeft;
    std::string _TextRight;
    float _Value;
    float _MaxValue;
    float _MinValue;
};

class GDropDown : public GUIElement {
public:
    GDropDown(const Vector2 pos = {0, 0}, const Vector2 size = {100, 100}, const std::string text = "default;drop;down;val", const std::string id = "default", const int active = 0, const bool editMode = false, const bool display = false);
    ~GDropDown() = default;

    void DrawRlibDropDown() const;

    void setActive(const int active);
    void setEditMode(const bool editMode);

    const int getActive() const;
    const bool getEditMode() const;
private:
    int _Active;
    bool _EditMode;
};