/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** RlibWindow
*/

#include "raylibWindow.hpp"

RlibWindow::RlibWindow()
{
    this->_FpsCounter = std::make_unique<FpsCounter>();
    this->_FpsCounter->setActive(false);
    this->_WindowWidth = 800;
    this->_WindowHeight = 450;
    this->_Title = "R-type";
    this->_BackgroundColor = WHITE;
    this->_FrameRateLimit = 60;
    this->setDefaultVal();

}

RlibWindow::RlibWindow(int windowWidth, int windowHeight, std::string title, Color backgroundColor, int frameRateLimit)
{
    this->_FpsCounter = std::make_unique<FpsCounter>();
    this->_FpsCounter->setActive(false);
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
    this->_UpPressed = false;
    this->_DownPressed = false;
    this->_LeftPressed = false;
    this->_RightPressed = false;
    this->_SpacePressed = false;
    this->_EscapePressed = false;
    this->_OldMenuType = START_MENU;
    this->_GuiFunction = std::make_shared<guiFunction>();
    this->_Menus = std::make_shared<MenuManager>(_JsonParser);
    this->_Menus->setDebugLogger(_DebugLogger);
    this->_Menus->setGuiFunction(_GuiFunction);
    this->_GuiFunction->setMenuManager(_Menus);
    this->_GuiFunction->mapFunctions();
    this->_Menus->setWindowSize(_WindowWidth, _WindowHeight);
    this->_Menus->loadMenu();

}

RlibWindow::RlibWindow(std::string filename)
{
    this->_JsonParser = std::make_unique<JsonParser>();
    this->_FpsCounter = std::make_unique<FpsCounter>();
    this->_DebugLogger = std::make_shared<DebugLogger>(true);

    nlohmann::json json = _JsonParser->parseFile(filename);

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

    this->_FpsCounter->setPos(
        Vector2{
            json["fpsText"]["position"]["x"],
            json["fpsText"]["position"]["y"]
            }
        );
    this->_FpsCounter->setFontSize(json["fpsText"]["fontSize"]);
    this->_FpsCounter->setColor(
        Color{
            json["fpsText"]["color"]["r"],
            json["fpsText"]["color"]["g"],
            json["fpsText"]["color"]["b"],
            json["fpsText"]["color"]["a"]
            }
        );
    this->_FpsCounter->setActive(json["fpsText"]["display"]);

    this->_DebugLogger->SetActive(json["logger"]["active"]);
    this->_DebugLogger->SetLogDepth(json["logger"]["degree"].get<int>());
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
    _DebugLogger->Log("Settings Touch or Button clicked swapping the state of the config menu", 1);
    this->_MenuOpened = !_MenuOpened;
    if (_MenuOpened) {
        _DebugLogger->Log("Config Menu wasn't oppened, opening it...", 1);
        this->_OldMenuType = this->_Menus->getMenuType();
        this->_Menus->setMenuType(SETTINGS_GENERAL);
    } else {
        _DebugLogger->Log("Config Menu was oppened, closing it...", 1);
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
    this->_FpsCounter = std::move(fpsCounter);
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
    return this->_FpsCounter;
}

const std::shared_ptr<JsonParser>& RlibWindow::getJsonParser() const
{
    return this->_JsonParser;
}

const std::shared_ptr<DebugLogger>& RlibWindow::getDebugLogger() const
{
    return this->_DebugLogger;
}

void RlibWindow::InitRlib()
{
    _DebugLogger->Log("Initiating Raylib Window");
    SetTraceLogCallback(CustomLog);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(_WindowWidth, _WindowHeight, _Title.c_str());
    SetTargetFPS(_FrameRateLimit);
    SetExitKey(KeyboardKey::KEY_NULL);
    if (_IsFullscreen)
        ToggleFullscreen();
    SetWindowPosition(_windowX, _windowY);
    GuiLoadStyleDefault();
    _DebugLogger->Log("Raylib Window Initiated");
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
    _DebugLogger->Log("Updating Raylib Window", 2);
    _DebugLogger->Log("Clearing background", 3);
    this->ClearRlibBackground();
    _DebugLogger->Log("Begin Draw", 3);
    this->BeginRlibDraw();
    _DebugLogger->Log("Checking if window resized", 3);
    if (IsWindowResized()) {
        _DebugLogger->Log("Window resize", 2);
        _DebugLogger->Log("Updated size in raylibWindow class", 3);
        this->setSize(GetScreenWidth(), GetScreenHeight());
        _DebugLogger->Log("Giving the new size to the menu", 3);
        this->_Menus->setWindowSize(_WindowWidth, _WindowHeight);
        _DebugLogger->Log("Reloading the menu", 3);
        this->_Menus->reloadMenu();
        _DebugLogger->Log("Done handling window resize", 3);
    }
    _DebugLogger->Log("Drawing menu", 3);
    this->_Menus->drawMenu();
    _DebugLogger->Log("Drawing fps counter", 3);
    this->_FpsCounter->draw();
    _DebugLogger->Log("Updating keyboard input", 3);
    this->updateKeyboadInputs();
    if (_AutoReloadMenus)
        _Menus->reloadOnChanges();
    _DebugLogger->Log("Ending draw", 3);
    this->EndRlibDraw();
    _DebugLogger->Log("Raylib Window Updated", 2);
}

void RlibWindow::updateKeyboadInputs()
{
    for (const auto& [key, action] : keyDownActions)
        if (IsKeyPressed(key))
            action();
    for (const auto& [key, action] : keyUpActions)
        if (IsKeyReleased(key))
            action();
    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; ++key)
        if (IsKeyPressed(key))
            _DebugLogger->Log("Key pressed: " + GetKeyPressed(), 2);

}

void RlibWindow::BeginRlibDraw() const
{
    BeginDrawing();
}

void RlibWindow::EndRlibDraw() const
{
    EndDrawing();
    this->_FpsCounter->update();
}

void RlibWindow::ClearRlibBackground() const
{
    ClearBackground(_BackgroundColor);
}

void RlibWindow::ClearRlibBackground(Color color) const
{
    ClearBackground(color);
}
