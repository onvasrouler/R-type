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
    this->_OldMenuType = START_MENU;
    this->_guiFunction = std::make_shared<guiFunction>();
    this->_Menus = std::make_shared<MenuManager>(_jsonParser);
    this->_Menus->setGuiFunction(_guiFunction);
    this->_guiFunction->setMenuManager(_Menus);
    this->_guiFunction->mapFunctions();
    this->_Menus->setWindowSize(_WindowWidth, _WindowHeight);
    this->_Menus->loadMenu();
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
    this->setDefaultVal();
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

void RlibWindow::swapSettings()
{
    this->_MenuOpened = !_MenuOpened;
    if (_MenuOpened) {
        this->_OldMenuType = this->_Menus->getMenuType();
       this->_Menus->setMenuType(SETTINGS_GENERAL);
    } else {
        this->_Menus->setMenuType(this->_OldMenuType);
    }
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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(_WindowWidth, _WindowHeight, _Title.c_str());
    SetTargetFPS(_FrameRateLimit);
    SetExitKey(KeyboardKey::KEY_NULL);
    if (_IsFullscreen)
        ToggleFullscreen();
    SetWindowPosition(_windowX, _windowY);
    GuiLoadStyleDefault();
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
    if (IsWindowResized()) {
        this->setSize(GetScreenWidth(), GetScreenHeight());
        this->_Menus->setWindowSize(_WindowWidth, _WindowHeight);
        this->_Menus->reloadMenu();
    }
    this->_Menus->drawMenu();
    this->_fpsCounter->draw();
    this->updateKeyboadInputs();
    if (_AutoReloadMenus)
        _Menus->reloadOnChanges();
    this->EndRlibDraw();
}

void RlibWindow::updateKeyboadInputs()
{
    for (const auto& [key, action] : keyDownActions)
        if (IsKeyPressed(key))
            action();
    for (const auto& [key, action] : keyUpActions)
        if (IsKeyReleased(key))
            action();
    // for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; ++key)
    //     if (IsKeyPressed(key))
    //         std::cout << "Key pressed: " << GetKeyPressed() << std::endl;

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
