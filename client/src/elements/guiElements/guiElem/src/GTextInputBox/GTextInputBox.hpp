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
    GTextInputBox(const Vector2 pos = defaultPos, const Vector2 size = defaultSize, const int zindex = defaultZIndex, const std::string id = defaultId, const std::string title = "default title", const std::string message = "default message", const std::string buttons = "default;buttons", const std::string text = defaultText, const int textMaxSize = 100, const bool secretViewActive = NULL, const bool display = defaultDisplay);
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
