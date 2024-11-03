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

/**
 * @class RlibWindow
 * @brief A class to manage a window using the Raylib library.
 *
 * This class provides functionalities to create, manage, and manipulate a window
 * using the Raylib library. It includes methods for setting window properties,
 * handling keyboard inputs, and managing FPS counters and debug logging.
 *
 * @note The class supports default values for window width, height, title, background color, and frame rate limit.
 **/
class RlibWindow
{
public:
    /**
     * @brief Constructor to initialize the window with specified parameters.
     *
     * @param _WindowWidth Width of the window.
     * @param _WindowHeight Height of the window.
     * @param title Title of the window.
     * @param backgroundColor Background color of the window.
     * @param frameRateLimit Frame rate limit for the window.
     */
    RlibWindow(
        const int   _WindowWidth    = 800,
        const int   _WindowHeight   = 600,
        std::string title           = "r-type",
        Color       backgroundColor = WHITE,
        const int   frameRateLimit  = 60);

    /**
     * @brief Constructor to initialize the window using a configuration file.
     *
     * @param filename Path to the configuration file.
     */
    RlibWindow(const std::string filename);

    /**
     * @brief Destructor to clean up resources.
     */
    ~RlibWindow() = default;

    /**
     * @brief Set the width of the window.
     *
     * @param WindowWidth New width of the window.
     */
    void setWidth(const int WindowWidth);

    /**
     * @brief Set the height of the window.
     *
     * @param WindowHeight New height of the window.
     */
    void setHeight(const int WindowHeight);

    /**
     * @brief Set the size of the window.
     *
     * @param WindowWidth New width of the window.
     * @param WindowHeight New height of the window.
     */
    void setSize(const int WindowWidth, const int WindowHeight);

    /**
     * @brief Swap the current window settings.
     */
    void swapSettings();

    /**
     * @brief Set the position of the window.
     *
     * @param windowX X-coordinate of the window position.
     * @param windowY Y-coordinate of the window position.
     */
    void setWindowPosition(const int windowX, const int windowY);

    /**
     * @brief Set the X-coordinate of the window position.
     *
     * @param windowX New X-coordinate of the window position.
     */
    void setWindowPosX(const int windowX);

    /**
     * @brief Set the Y-coordinate of the window position.
     *
     * @param windowY New Y-coordinate of the window position.
     */
    void setWindowPosY(const int windowY);

    /**
     * @brief Set the window to fullscreen mode.
     *
     * @param isfullscreen Boolean indicating whether to set fullscreen mode.
     */
    void setFullscreen(bool isfullscreen);

    /**
     * @brief Set the title of the window.
     *
     * @param title New title of the window.
     */
    void setTitle(const std::string title);

    /**
     * @brief Set the background color of the window.
     *
     * @param backgroundColor New background color of the window.
     */
    void setBackgroundColor(const Color backgroundColor);

    /**
     * @brief Set the frame rate limit of the window.
     *
     * @param frameRateLimit New frame rate limit.
     */
    void setFrameRateLimit(const int frameRateLimit);

    /**
     * @brief Set the FPS counter.
     *
     * @param fpsCounter Unique pointer to the FPS counter.
     */
    void setFpsCounter(const std::unique_ptr<FpsCounter> fpsCounter);

    /**
     * @brief Get the width of the window.
     *
     * @return Width of the window.
     */
    int getWidth() const;

    /**
     * @brief Get the height of the window.
     *
     * @return Height of the window.
     */
    int getHeight() const;

    /**
     * @brief Get the X-coordinate of the window position.
     *
     * @return X-coordinate of the window position.
     */
    int getWindowPosX() const;

    /**
     * @brief Get the Y-coordinate of the window position.
     *
     * @return Y-coordinate of the window position.
     */
    int getWindowPosY() const;

    /**
     * @brief Check if the window is in fullscreen mode.
     *
     * @return Boolean indicating if the window is in fullscreen mode.
     */
    bool isFullscreen() const;

    /**
     * @brief Get the title of the window.
     *
     * @return Title of the window.
     */
    std::string getTitle() const;

    /**
     * @brief Get the background color of the window.
     *
     * @return Background color of the window.
     */
    Color getBackgroundColor() const;

    /**
     * @brief Get the frame rate limit of the window.
     *
     * @return Frame rate limit.
     */
    int getFrameRateLimit() const;

    /**
     * @brief Get the FPS counter.
     *
     * @return Constant reference to the unique pointer of the FPS counter.
     */
    const std::unique_ptr<FpsCounter>& getFpsCounter() const;

    /**
     * @brief Get the JSON parser.
     *
     * @return Constant reference to the shared pointer of the JSON parser.
     */
    const std::shared_ptr<JsonParser>& getJsonParser() const;

    /**
     * @brief Get the debug logger.
     *
     * @return Constant reference to the shared pointer of the debug logger.
     */
    const std::shared_ptr<DebugLogger>& getDebugLogger() const;

    /**
     * @brief Initialize the Raylib window.
     */
    void InitRlib();

    /**
     * @brief Close the Raylib window.
     */
    void CloseRlibWindow() const;

    /**
     * @brief Update the window state.
     */
    void update();

    /**
     * @brief Check if the window should close.
     *
     * @return Boolean indicating if the window should close.
     */
    bool ShouldClose() const;

    /**
     * @brief Begin drawing with Raylib.
     */
    void BeginRlibDraw() const;

    /**
     * @brief End drawing with Raylib.
     */
    void EndRlibDraw() const;

    /**
     * @brief Clear the Raylib background.
     */
    void ClearRlibBackground();

    /**
     * @brief Clear the Raylib background with a specific color.
     *
     * @param color Color to clear the background with.
     */
    void ClearRlibBackground(const Color color) const;

    /**
     * @brief Update keyboard inputs.
     */
    void updateKeyboadInputs();

    /**
     * @brief Set default values for the window properties.
     */
    void setDefaultVal();

private:
    int         _WindowWidth; /**< Width of the window. used for responsivity */
    int         _WindowHeight; /**< Height of the window. used for responsivity */
    int         _windowX; /**< X-coordinate of the window position on the actual screen. */
    int         _windowY; /**< Y-coordinate of the window position on the actual screen. */
    bool        _IsFullscreen; /**< Boolean indicating if the window is in fullscreen mode. */
    std::string _Title; /**< Title of the window. */
    Color       _BackgroundColor; /**< Background color of the window. */
    int         _FrameRateLimit; /**< Frame rate limit of the window. */

    bool _AutoReloadMenus; /**< Boolean indicating if the menus should be reloaded automatically on file change. */

    std::unique_ptr<FpsCounter>  _FpsCounter; /**< Unique pointer to the FPS counter. */
    std::shared_ptr<JsonParser>  _JsonParser; /**< Shared pointer to the JSON parser. */
    std::shared_ptr<MenuManager> _Menus; /**< Shared pointer to the menu manager. */
    std::shared_ptr<guiFunction> _GuiFunction; /**< Shared pointer to the GUI function. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to the debug logger. */
    std::shared_ptr<Game>        _Game; /**< Shared pointer to the game. */
    std::shared_ptr<NetworkElem> _NetworkElem; /**< Shared pointer to the network element. */

    std::vector<std::pair<int, std::function<void()>>> keyDownActions = {
        {KEY_F11, [this]() { ToggleFullscreen(); }},
        {KEY_R, [this]() { _AutoReloadMenus = !_AutoReloadMenus; }},
        {KEY_F5, [this]() { _Menus->reloadMenu(); }},
        {KEY_F1, [this]() { _FpsCounter->getFpsText()->toggleDisplay(); }},
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
    }; /**< List of key down actions. */

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
        {KEY_ESCAPE, [this]() { _EscapePressed = false; }}}; /**< List of key up actions. */

    bool _UpPressed; /**< Boolean indicating if the up key is pressed. */
    bool _DownPressed; /**< Boolean indicating if the down key is pressed. */
    bool _LeftPressed; /**< Boolean indicating if the left key is pressed. */
    bool _RightPressed; /**< Boolean indicating if the right key is pressed. */
    bool _SpacePressed; /**< Boolean indicating if the space key is pressed. */
    bool _EscapePressed; /**< Boolean indicating if the escape key is pressed. */
    bool _MenuOpened; /**< Boolean indicating if the menu is opened. */

    menuType _OldMenuType; /**< The old type of the menu. Used when menu is openend but then you close it */
};
