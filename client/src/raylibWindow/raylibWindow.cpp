/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** RlibWindow
*/

#include "raylibWindow.hpp"

RlibWindow::RlibWindow(
    const int         windowWidth,
    const int         windowHeight,
    const std::string title,
    const Color       backgroundColor,
    const int         frameRateLimit)
{
    this->_FpsCounter = std::make_unique<FpsCounter>();
    this->_FpsCounter->getFpsText()->setDisplay(false);
    this->_WindowWidth     = windowWidth;
    this->_WindowHeight    = windowHeight;
    this->_Title           = title;
    this->_BackgroundColor = backgroundColor;
    this->_FrameRateLimit  = frameRateLimit;
    this->setDefaultVal();
}

void RlibWindow::setDefaultVal()
{
    this->_DebugLogger->Log("setting simple value : _AutoReloadMenus -> _OldMenuType", 2);
    this->_AutoReloadMenus = false;
    this->_UpPressed       = false;
    this->_DownPressed     = false;
    this->_LeftPressed     = false;
    this->_RightPressed    = false;
    this->_SpacePressed    = false;
    this->_EscapePressed   = false;
    this->_OldMenuType     = START_MENU;
    this->_DebugLogger->Log("setting _GuiFunction", 2);
    this->_GuiFunction = std::make_shared<guiFunction>();

    this->_DebugLogger->Log("creating menu with json parser", 2);
    this->_Menus = std::make_shared<MenuManager>(_JsonParser);

    this->_DebugLogger->Log("setting debuglogger to menuManager", 2);
    this->_Menus->setDebugLogger(_DebugLogger);

    this->_DebugLogger->Log("setting guifunct to menuManager", 2);
    this->_Menus->setGuiFunction(_GuiFunction);

    this->_DebugLogger->Log("setting menuManager to guifunct", 2);
    this->_GuiFunction->setMenuManager(_Menus);

    this->_DebugLogger->Log("mapping functions", 2);
    this->_GuiFunction->mapFunctions();

    this->_DebugLogger->Log("setting window size", 2);
    this->_Menus->setWindowSize(_WindowWidth, _WindowHeight);

    this->_DebugLogger->Log("loading menu", 2);
    this->_Menus->loadMenu();

    this->_DebugLogger->Log("setting game to raylibwindow", 2);
    this->_Game = std::make_shared<Game>(_JsonParser, _DebugLogger, _WindowWidth, _WindowHeight);

    this->_DebugLogger->Log("setting game to menuManager", 2);
    this->_Menus->setGame(_Game);

    this->_DebugLogger->Log("initiating game", 2);
    this->_Game->initGame();

    this->_DebugLogger->Log("creating networkelem", 2);
    this->_NetworkElem = std::make_shared<NetworkElem>(_DebugLogger);

    this->_DebugLogger->Log("setting networkelem to menuManager", 2);
    this->_Menus->setNetworkElem(_NetworkElem);
}

RlibWindow::RlibWindow(const std::string filename)
{
    nlohmann::json          json;
    std::shared_ptr<RLText> fpsTxt;
    this->_JsonParser  = std::make_unique<JsonParser>();
    this->_FpsCounter  = std::make_unique<FpsCounter>();
    this->_DebugLogger = std::make_shared<DebugLogger>(true);

    json = _JsonParser->parseFile(filename);

    this->_WindowWidth     = json["windowWidth"];
    this->_WindowHeight    = json["windowHeight"];
    this->_Title           = json["windowTitle"];
    this->_BackgroundColor = {
        json["backgroundColor"]["r"],
        json["backgroundColor"]["g"],
        json["backgroundColor"]["b"],
        json["backgroundColor"]["a"]};
    this->_FrameRateLimit = json["frameRateLimit"];
    this->_IsFullscreen   = json["windowMaximized"];
    this->_windowX        = json["windowX"];
    this->_windowY        = json["windowY"];

    fpsTxt = this->_FpsCounter->getFpsText();

    fpsTxt->setPos(Vector2{json["fpsText"]["position"]["x"], json["fpsText"]["position"]["y"]});
    fpsTxt->setSize(Vector2{0.0F, json["fpsText"]["fontSize"].get<float>()});
    fpsTxt->setColor(Color{
        json["fpsText"]["color"]["r"],
        json["fpsText"]["color"]["g"],
        json["fpsText"]["color"]["b"],
        json["fpsText"]["color"]["a"]});
    fpsTxt->setDisplay(json["fpsText"]["display"]);
    fpsTxt->setZIndex(json["fpsText"]["z-index"]);
    this->_DebugLogger->SetActive(json["logger"]["active"]);
    this->_DebugLogger->SetLogDepth(json["logger"]["degree"].get<int>());
    this->setDefaultVal();
}

RlibWindow::~RlibWindow()
{
    CloseWindow();
}

void RlibWindow::setWidth(const int windowWidth)
{
    this->_WindowWidth = windowWidth;
}

void RlibWindow::setHeight(const int windowHeight)
{
    this->_WindowHeight = windowHeight;
}

void RlibWindow::setSize(const int windowWidth, const int windowHeight)
{
    this->_WindowWidth  = windowWidth;
    this->_WindowHeight = windowHeight;
}

void RlibWindow::setWindowPosition(const int windowX, const int windowY)
{
    this->_windowX = windowX;
    this->_windowY = windowY;
}

void RlibWindow::setWindowPosX(const int windowX)
{
    this->_windowX = windowX;
}

void RlibWindow::setWindowPosY(const int windowY)
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
    if ( _MenuOpened ) {
        _DebugLogger->Log("Config Menu wasn't oppened, opening it...", 1);
        this->_OldMenuType = this->_Menus->getMenuType();
        this->_Menus->setMenuType(SETTINGS_GENERAL);
    } else {
        _DebugLogger->Log("Config Menu was oppened, closing it...", 1);
        this->_Menus->setMenuType(this->_OldMenuType);
    }
}

void RlibWindow::setBackgroundColor(const Color backgroundColor)
{
    this->_BackgroundColor = backgroundColor;
}

void RlibWindow::setFrameRateLimit(const int frameRateLimit)
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
    if ( _IsFullscreen )
        ToggleFullscreen();
    SetWindowPosition(_windowX, _windowY);
    GuiLoadStyleDefault();
    _Menus->setBackgroundColor(_BackgroundColor);
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
    if ( IsWindowResized() ) {
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
    this->_FpsCounter->getFpsText()->draw();
    _DebugLogger->Log("Updating keyboard input", 3);
    this->updateKeyboadInputs();
    if ( _AutoReloadMenus )
        _Menus->reloadOnChanges();
    _DebugLogger->Log("Ending draw", 3);
    this->EndRlibDraw();
    _DebugLogger->Log("Raylib Window Updated", 2);
}

void RlibWindow::updateKeyboadInputs()
{
    
    for ( const auto& [key, action] : keyDownActions )
        if ( IsKeyPressed(key) )
            action();
    for ( const auto& [key, action] : keyUpActions )
        if ( IsKeyReleased(key) )
            action();
    for ( int key = KEY_SPACE; key <= KEY_KP_EQUAL; ++key )
        if ( IsKeyPressed(key) )
            this->_Menus->handleInput(key, 1);
        else if ( IsKeyReleased(key) )
            this->_Menus->handleInput(key, 0);
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

void RlibWindow::ClearRlibBackground()
{
    _BackgroundColor = this->_Menus->getBackgroundColor();
    ClearBackground(_BackgroundColor);
}

void RlibWindow::ClearRlibBackground(const Color color) const
{
    ClearBackground(color);
}
