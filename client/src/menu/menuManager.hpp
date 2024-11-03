/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#pragma once

#include "../elements/guiElements/guiFunction.hpp"
#include "./GuiElementFactory.hpp"
#include "../network/networkElem.hpp"


/**
 * @class MenuManager
 * @brief Manages the menu system for the application.
 *
 * The MenuManager class is responsible for handling the creation, rendering, and management of menus within the
 * application. It provides various methods to set and get menu properties, load and reload menus, and create different
 * GUI elements.
 *
 * * The MenuManager class is responsible for handling various menu-related functionalities,
 * including setting menu types, window dimensions, background colors, and GUI functions.
 * It also provides methods for loading, reloading, and drawing menus, as well as converting
 * positions and creating various GUI elements from JSON objects.
 *
 * @note This class uses the nlohmann::json library for JSON parsing and manipulation.
 *
 * @details The MenuManager class supports the following functionalities:
 * - Setting and getting menu types.
 * - Setting and getting window dimensions.
 * - Setting and getting background colors.
 * - Setting GUI functions and JSON parsers.
 * - Loading, reloading, and drawing menus.
 * - Converting positions to relative coordinates.
 * - Creating various GUI elements from JSON objects.
 *
 * @see JsonParser
 * @see DebugLogger
 * @see RGui
 * @see AGuiElem
 * @see RLText
 * @see GButton
 * @see GWindBox
 * @see GCheckBox
 * @see GSlider
 * @see GList
 * @see GListEx
 * @see GTextInput
 * @see GTextInputBox
 * @see GSpinner
 * @see GValueBox
 * @see GGroup
 * @see GToggleGroup
 * @see GToggleSlider
 * @see GPannel
 * @see GColorPicker
 * @see GProgressBar
 * @see GDropDown
 */
class MenuManager : public std::enable_shared_from_this<MenuManager>
{
public:
    /**
     * @brief Default constructor for MenuManager.
     */
    MenuManager();

    /**
     * @brief Constructor with JsonParser.
     * @param jsonParser Shared pointer to a JsonParser object.
     */
    MenuManager(const std::shared_ptr<JsonParser> jsonParser);

    ~MenuManager() = default;

    /**
     * @brief Sets the menu type.
     * @param type The type of the menu.
     */
    void setMenuType(const menuType type);

    /**
     * @brief Sets the menu type by ID.
     * @param typeId The ID of the menu type.
     */
    void setMenuType(const int typeId);

    /**
     * @brief Gets the current menu type.
     * @return The current menu type.
     */
    menuType getMenuType() const;

    /**
     * @brief Sets the window height.
     * @param windowHeight The height of the window.
     */
    void setWindowHeight(const int windowHeight);

    /**
     * @brief Sets the window width.
     * @param windowWidth The width of the window.
     */
    void setWindowWidth(const int windowWidth);

    /**
     * @brief Sets the window size.
     * @param windowWidth The width of the window.
     * @param windowHeight The height of the window.
     */
    void setWindowSize(const int windowWidth, const int windowHeight);

    /**
     * @brief Sets the background color.
     * @param color The background color.
     */
    void setBackgroundColor(const Color color);

    void setGame(std::shared_ptr<Game> game);

    void setNetworkElem(std::shared_ptr<NetworkElem> networkElem);

    /**
     * @brief Gets the window height.
     * @return The height of the window.
     */
    int getWindowHeight() const;

    /**
     * @brief Gets the window width.
     * @return The width of the window.
     */
    int getWindowWidth() const;

    /**
     * @brief Sets the GUI function.
     * @param guiFunction Shared pointer to a guiFunction object.
     */
    void setGuiFunction(const std::shared_ptr<guiFunction> guiFunction);

    /**
     * @brief Sets the JsonParser.
     * @param jsonParser Shared pointer to a JsonParser object.
     */
    void setJsonParser(const std::shared_ptr<JsonParser> jsonParser);

    /**
     * @brief Sets the DebugLogger.
     * @param debugLogger Shared pointer to a DebugLogger object.
     */
    void setDebugLogger(const std::shared_ptr<DebugLogger> debugLogger);

    /**
     * @brief Loads the menu.
     */
    void loadMenu();

    /**
     * @brief Reloads the menu.
     */
    void reloadMenu();

    /**
     * @brief Reloads the menu on changes.
     */
    void reloadOnChanges();

    /**
     * @brief Draws the menu.
     */
    void drawMenu() const;

    /**
     * @brief Gets a shared pointer to the current MenuManager instance.
     * @return Shared pointer to the current MenuManager instance.
     */
    std::shared_ptr<MenuManager> getThis();

    /**
     * @brief Gets the background color.
     * @return The background color.
     */
    Color getBackgroundColor() const;

    /**
     * @brief Gets the current GUI.
     * @return Shared pointer to the current RGui object.
     */
    std::shared_ptr<RGui> getCurrentGui() const;


    void setGameInfo(const std::string ip = "1.1.1.1", const std::string port = "1234");

    void handleInput(int key, int pressedOrReleased);

    void setUserName(const std::string username);

    void restartGame();

private:
    void checkForNetwork();

    /**
     * @brief Creates a menu from JSON.
     * @param menu The JSON object representing the menu.
     * @param menuID The ID of the menu.
     */
    void createMenu(const nlohmann::json& menu, const int menuID = 0);

    /**
     * @brief Integrates a template into the menu.
     * @param menu The JSON object representing the menu.
     * @param menuID The ID of the menu.
     */
    void integrateTemplate(const nlohmann::json& menu, const int menuID = 0);

    /**
     * @brief Erases the menu.
     */
    void eraseMenu();

    void setIsConnecting(bool is_connecting);

    void setIsConnected(bool is_connected);


    std::shared_ptr<GuiElementFactory> _GuiElementFactory;

    
    nlohmann::json _menuJson; /**< The JSON object representing the menu. */
    nlohmann::json _menuTemplate; /**< The JSON object representing the menu template (ex: navbar). */

    menuType                     _type; /**< The type of the menu. see menuType */
    std::shared_ptr<JsonParser>  _JsonParser; /**< Shared pointer to a JsonParser object. */
    std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */

    std::map<menuType, std::shared_ptr<RGui>>
                                 _menuList; /**< Map of menu types to RGui objects. this is the list off all the menu */
    std::shared_ptr<guiFunction> _guiFunction; /**< Shared pointer to a guiFunction object. */
    std::shared_ptr<Game>        _Game;
    std::shared_ptr<NetworkElem> _NetworkElem;
    std::string _Ip;
    std::string _Port;

    Color _BackgroundColor; /**< The background color of the menu, is used to communicated with rayLibWindow without
                               using potentially risky pointer. */
    std::map<menuType, std::vector<GuiElementFactory::MenuItem>>
        _MenuItems; /**< Map of menu types to MenuItem objects used to handle and treat click. */

    int _WindowWidth; /**< The width of the window. is used for responsivity */
    int _WindowHeight; /**< The height of the window. is used for responsivity */

    bool _Is_connecting;
    bool _Is_connected;

    std::string _Username;
};
