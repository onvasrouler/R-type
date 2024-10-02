/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** RlibWindow
*/

#include "raylibWindow.hpp"

RlibWindow::RlibWindow()
{
    _WindowWidth = 800;
    _WindowHeight = 450;
    _Title = "R-type";
    _BackgroundColor = WHITE;
    _FrameRateLimit = 60;
    _AutoReloadMenus = false;
}

RlibWindow::RlibWindow(int windowWidth, int windowHeight, std::string title, Color backgroundColor, int frameRateLimit)
{
    this->_WindowWidth = windowWidth;
    this->_WindowHeight = windowHeight;
    this->_Title = title;
    this->_BackgroundColor = backgroundColor;
    this->_FrameRateLimit = frameRateLimit;
    _AutoReloadMenus = false;
}

RlibWindow::RlibWindow(std::string filename)
{
    _jsonParser = std::make_unique<JsonParser>();
    nlohmann::json json = _jsonParser->parseFile(filename);

    _WindowWidth = json["windowWidth"];
    _WindowHeight = json["windowHeight"];
    _Title = json["windowTitle"];
    _BackgroundColor = {
        json["backgroundColor"]["r"],
        json["backgroundColor"]["g"],
        json["backgroundColor"]["b"],
        json["backgroundColor"]["a"]
    };
    _FrameRateLimit = json["frameRateLimit"];
    _IsFullscreen = json["windowMaximized"];
    _windowX = json["windowX"];
    _windowY = json["windowY"];
}

RlibWindow::~RlibWindow()
{
    CloseWindow();
}

void RlibWindow::setWidth(int windowWidth)
{
    this->_WindowWidth = windowWidth;
}

void RlibWindow::setHeight(int windowHeight)
{
    this->_WindowHeight = windowHeight;
}

void RlibWindow::setSize(int windowWidth, int windowHeight)
{
    this->_WindowWidth = windowWidth;
    this->_WindowHeight = windowHeight;
}

void RlibWindow::setWindowPosition(int windowX, int windowY)
{
    this->_windowX = windowX;
    this->_windowY = windowY;
}

void RlibWindow::setWindowPosX(int windowX)
{
    this->_windowX = windowX;
}

void RlibWindow::setWindowPosY(int windowY)
{
    this->_windowY = windowY;
}

void RlibWindow::setTitle(std::string title)
{
    this->_Title = title;
}

void RlibWindow::setBackgroundColor(Color backgroundColor)
{
    this->_BackgroundColor = backgroundColor;
}

void RlibWindow::setFrameRateLimit(int frameRateLimit)
{
    this->_FrameRateLimit = frameRateLimit;
    SetTargetFPS(frameRateLimit);
}

void RlibWindow::setFpsCounter(std::unique_ptr<FpsCounter> fpsCounter)
{
    _fpsCounter = std::move(fpsCounter);
}

int RlibWindow::getWidth() const
{
    return _WindowWidth;
}

int RlibWindow::getHeight() const
{
    return _WindowHeight;
}

int RlibWindow::getWindowPosX() const
{
    return _windowX;
}

int RlibWindow::getWindowPosY() const
{
    return _windowY;
}

std::string RlibWindow::getTitle() const
{
    return _Title;
}

Color RlibWindow::getBackgroundColor() const
{
    return _BackgroundColor;
}

int RlibWindow::getFrameRateLimit() const
{
    return _FrameRateLimit;
}

const std::unique_ptr<FpsCounter>& RlibWindow::getFpsCounter() const
{
    return _fpsCounter;
}

const std::shared_ptr<JsonParser>& RlibWindow::getJsonParser() const
{
    return _jsonParser;
}

void RlibWindow::InitRlib()
{
    SetTraceLogCallback(CustomLog);
    InitWindow(_WindowWidth, _WindowHeight, _Title.c_str());
    SetTargetFPS(_FrameRateLimit);
    if (_IsFullscreen)
        ToggleFullscreen();
    SetWindowPosition(_windowX, _windowY);
    GuiLoadStyleDefault();
    _Menus = std::make_unique<MenuManager>(_jsonParser);
}

void RlibWindow::CloseRlibWindow() const
{
    CloseWindow();
}

bool RlibWindow::ShouldClose() const
{
    return WindowShouldClose();
}

void RlibWindow::update()
{
    this->ClearRlibBackground();
    this->BeginRlibDraw();
    this->ClearRlibBackground();
    this->_Menus->drawMenu();
    _fpsCounter->draw();
    if (IsKeyPressed(KEY_F11))
        ToggleFullscreen();
    if (IsKeyPressed(KEY_R))
        _AutoReloadMenus = !_AutoReloadMenus;
    if (_AutoReloadMenus)
        _Menus->reloadOnChanges();
    this->EndRlibDraw();
}

void RlibWindow::BeginRlibDraw() const
{
    BeginDrawing();
    _Menus->drawMenu();
    _fpsCounter->draw();

}

void RlibWindow::EndRlibDraw() const
{
    EndDrawing();
    _fpsCounter->update();
}

void RlibWindow::ClearRlibBackground() const
{
    ClearBackground(_BackgroundColor);
}

void RlibWindow::ClearRlibBackground(Color color) const
{
    ClearBackground(color);
}

