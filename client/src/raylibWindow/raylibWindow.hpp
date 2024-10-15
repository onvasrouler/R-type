/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** RlibWindow
*/

#pragma once

#include "../fpsCounter/fpsCounter.hpp"
#include "../jsonParser/jsonParser.hpp"
#include "../menu/menuManager.hpp"
#include "../elements/guiElements/gui.hpp"
#include "../include.hpp"

class RlibWindow {
public:
    RlibWindow();
    RlibWindow(int _WindowWidth = 800, int _WindowHeight = 600, std::string title = "r-type", Color backgroundColor = WHITE, int frameRateLimit = 60);
    RlibWindow(std::string filename);
    ~RlibWindow();

    //window size related
    void setWidth(int WindowWidth);
    void setHeight(int WindowHeight);
    void setSize(int WindowWidth, int WindowHeight);
    void swapSettings();

    //window position related
    void setWindowPosition(int windowX, int windowY);
    void setWindowPosX(int windowX);
    void setWindowPosY(int windowY);

    void setFullscreen(bool isfullscreen);
    void setTitle(std::string title);
    void setBackgroundColor(Color backgroundColor);
    void setFrameRateLimit(int frameRateLimit);
    void setFpsCounter(std::unique_ptr<FpsCounter> fpsCounter);

    int getWidth() const;
    int getHeight() const;
    int getWindowPosX() const;
    int getWindowPosY() const;
    bool isFullscreen() const;
    std::string getTitle() const;
    Color getBackgroundColor() const;
    int getFrameRateLimit() const;

    const std::unique_ptr<FpsCounter>& getFpsCounter() const;
    const std::shared_ptr<JsonParser>& getJsonParser() const;
    const std::shared_ptr<DebugLogger>& getDebugLogger() const;

    void InitRlib();
    void CloseRlibWindow() const;

    void update();
    bool ShouldClose() const;
    void BeginRlibDraw() const;
    void EndRlibDraw() const;
    void ClearRlibBackground() const;
    void ClearRlibBackground(Color color) const;

private:

    void updateKeyboadInputs();
    void setDefaultVal();

    int _WindowWidth;
    int _WindowHeight;
    int _windowX;
    int _windowY;
    bool _IsFullscreen;
    std::string _Title;
    Color _BackgroundColor;
    int _FrameRateLimit;

    bool _AutoReloadMenus;

    std::unique_ptr<FpsCounter> _FpsCounter;
    std::shared_ptr<JsonParser> _JsonParser;
    std::shared_ptr<MenuManager> _Menus;
    std::unique_ptr<RaylibText> _DebugText;
    std::unique_ptr<RGui> _GUI;
    std::shared_ptr<guiFunction> _GuiFunction;
    std::shared_ptr<DebugLogger> _DebugLogger;

    std::vector<std::pair<int, std::function<void()>>> keyDownActions = {
        {KEY_F11, [this]() { ToggleFullscreen(); }},
        {KEY_R, [this]() { _AutoReloadMenus = !_AutoReloadMenus; }},
        {KEY_F5, [this]() { _Menus->reloadMenu(); }},
        {KEY_F1, [this]() { _FpsCounter->toggleActive(); }},
        {KEY_Z, [this]() { _UpPressed = true; }},
        {KEY_UP, [this]() { _UpPressed = true; }},
        {KEY_S, [this]() { _DownPressed = true; }},
        {KEY_DOWN, [this]() { _DownPressed = true; }},
        {KEY_Q, [this]() { _LeftPressed = true; }},
        {KEY_LEFT, [this]() { _LeftPressed = true; }},
        {KEY_D, [this]() { _RightPressed = true; }},
        {KEY_RIGHT, [this]() { _RightPressed = true; }},
        {KEY_SPACE, [this]() { _SpacePressed = true; }},
        {KEY_ESCAPE, [this]() { swapSettings(); }},
        {KEY_F3, [this]() { _DebugLogger->SetActive(!_DebugLogger->GetActive()); }},
    };

    std::vector<std::pair<int, std::function<void()>>> keyUpActions = {
        {KEY_W, [this]() { _UpPressed = false; }},
        {KEY_UP, [this]() { _UpPressed = false; }},
        {KEY_S, [this]() { _DownPressed = false; }},
        {KEY_DOWN, [this]() { _DownPressed = false; }},
        {KEY_A, [this]() { _LeftPressed = false; }},
        {KEY_LEFT, [this]() { _LeftPressed = false; }},
        {KEY_D, [this]() { _RightPressed = false; }},
        {KEY_RIGHT, [this]() { _RightPressed = false; }},
        {KEY_SPACE, [this]() { _SpacePressed = false; }},
        {KEY_ESCAPE, [this]() { _EscapePressed = false; }}
    };

    bool _UpPressed;
    bool _DownPressed;
    bool _LeftPressed;
    bool _RightPressed;
    bool _SpacePressed;
    bool _EscapePressed;
    bool _MenuOpened;

    menuType _OldMenuType;
};
