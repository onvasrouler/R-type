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
#include "utils.hpp"

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

    void InitRlib();
    void CloseRlibWindow() const;

    void update();
    bool ShouldClose() const;
    void BeginRlibDraw() const;
    void EndRlibDraw() const;
    void ClearRlibBackground() const;
    void ClearRlibBackground(Color color) const;

private:
    int _WindowWidth;
    int _WindowHeight;
    int _windowX;
    int _windowY;
    bool _IsFullscreen;
    std::string _Title;
    Color _BackgroundColor;
    int _FrameRateLimit;

    bool _AutoReloadMenus;

    std::unique_ptr<FpsCounter> _fpsCounter;
    std::shared_ptr<JsonParser> _jsonParser;
    std::shared_ptr<MenuManager> _Menus;

    std::unique_ptr<RGui> _GUI;
};