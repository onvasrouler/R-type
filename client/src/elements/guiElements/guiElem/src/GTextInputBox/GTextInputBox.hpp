/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** GTextInputBox
*/

#pragma once

#include "../../AGuiElem.hpp"

class GTextInputBox : public AGuiElem {
public:
    GTextInputBox(const Vector2 pos = DEFAULT_POS, const Vector2 size = DEFAULT_SIZE, const int zindex = DEFAULT_Z_INDEX, const std::string id = DEFAULT_ID, const std::string title = "default title", const std::string message = "default message", const std::string buttons = "default;buttons", const std::string text = DEFAULT_TEXT, const int textMaxSize = 100, const bool secretViewActive = NULL, const bool display = DEFAULT_DISPLAY);
    ~GTextInputBox() = default;

    void draw() const;

    void setMaxCharacters(const int maxCharacters);
    void setSecretView(const bool secretView);
    void setTitle(const std::string title);
    void setMessage(const std::string message);
    void setButtons(const std::string buttons);
    void setResults(const int result);

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
