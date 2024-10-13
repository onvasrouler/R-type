/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** RlibWindow
*/

#include "raylibWindow.hpp"

RlibWindow::RlibWindow()
{
    this->_WindowWidth = 800;
    this->_WindowHeight = 450;
    this->_Title = "R-type";
    this->_BackgroundColor = WHITE;
    this->_FrameRateLimit = 60;   
    this->setDefaultVal(); 
}

RlibWindow::RlibWindow(int windowWidth, int windowHeight, std::string title, Color backgroundColor, int frameRateLimit)
{
    this->_WindowWidth = windowWidth;
    this->_WindowHeight = windowHeight;
    this->_Title = title;
    this->_BackgroundColor = backgroundColor;
    this->_FrameRateLimit = frameRateLimit;
    this->setDefaultVal();
}

void RlibWindow::setDefaultVal()
{
    this->_AutoReloadMenus = false;
    this->_DebugMode = false;
    this->_UpPressed = false;
    this->_DownPressed = false;
    this->_LeftPressed = false;
    this->_RightPressed = false;
    this->_SpacePressed = false;
    this->_EscapePressed = false;
}

RlibWindow::RlibWindow(std::string filename)
{
    this->_jsonParser = std::make_unique<JsonParser>();
    nlohmann::json json = _jsonParser->parseFile(filename);

    this->_WindowWidth = json["windowWidth"];
    this->_WindowHeight = json["windowHeight"];
    this->_Title = json["windowTitle"];
    this->_BackgroundColor = {
        json["backgroundColor"]["r"],
        json["backgroundColor"]["g"],
        json["backgroundColor"]["b"],
        json["backgroundColor"]["a"]
    };
    this->_FrameRateLimit = json["frameRateLimit"];
    this->_IsFullscreen = json["windowMaximized"];
    this->_windowX = json["windowX"];
    this->_windowY = json["windowY"];
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
    this->_fpsCounter = std::move(fpsCounter);
}

int RlibWindow::getWidth() const
{
    return this->_WindowWidth;
}

int RlibWindow::getHeight() const
{
    return this->_WindowHeight;
}

int RlibWindow::getWindowPosX() const
{
    return this->_windowX;
}

int RlibWindow::getWindowPosY() const
{
    return this->_windowY;
}

std::string RlibWindow::getTitle() const
{
    return this->_Title;
}

Color RlibWindow::getBackgroundColor() const
{
    return this->_BackgroundColor;
}

int RlibWindow::getFrameRateLimit() const
{
    return this->_FrameRateLimit;
}

const std::unique_ptr<FpsCounter>& RlibWindow::getFpsCounter() const
{
    return this->_fpsCounter;
}

const std::shared_ptr<JsonParser>& RlibWindow::getJsonParser() const
{
    return this->_jsonParser;
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
    this->_Menus = std::make_shared<MenuManager>(_jsonParser);
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
    this->_fpsCounter->draw();
    this->updateKeyboadInputs();
    if (_AutoReloadMenus)
        _Menus->reloadOnChanges();
    this->EndRlibDraw();
}

void RlibWindow::updateKeyboadInputs()
{
    for (const auto& [key, action] : keyDownActions) {
        if (IsKeyPressed(key)) {
            action();
        }
    }
    for (const auto& [key, action] : keyUpActions) {
        if (IsKeyReleased(key)) {
            action();
        }
    }
    // std::cout << "debugMode: " << (_DebugMode? "on": "off") << std::endl;
    // if (_DebugMode) {
    //     DrawText("Debug Mode", 10, 10, 20, RED);
        
    //     std::cout << "up: " << _UpPressed << std::endl;
    //     std::cout << "down: " << _DownPressed << std::endl;
    //     std::cout << "left: " << _LeftPressed << std::endl;
    //     std::cout << "right: " << _RightPressed << std::endl;
    //     std::cout << "space: " << _SpacePressed << std::endl;
    //     std::cout << "escape: " << _EscapePressed << std::endl;
    //     std::cout << "------------------------------------------------" << std::endl;
    //     std::cout << "autoReloadMenus: " << _AutoReloadMenus << std::endl;
    //     std::cout << "debugMode: " << (_DebugMode? "on": "off") << std::endl;
    //     std::cout << "fps active" << _fpsCounter->isActive() << std::endl;
    // } 
    // std::cout << "debugMode: " << (_DebugMode? "on": "off") << std::endl;
    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; ++key) {
        if (IsKeyPressed(key)) {
            std::cout << "Key pressed: " << GetKeyPressed() << std::endl;
        }
    }

}

void RlibWindow::BeginRlibDraw() const
{
    BeginDrawing();
}

void RlibWindow::EndRlibDraw() const
{
    EndDrawing();
    this->_fpsCounter->update();
}

void RlibWindow::ClearRlibBackground() const
{
    ClearBackground(_BackgroundColor);
}

void RlibWindow::ClearRlibBackground(Color color) const
{
    ClearBackground(color);
}
