# R-Type Client Documentation

## Overview

The R-Type Client is a game window manager for the R-Type project, handling user inputs, graphical rendering, networking, and logging within a Raylib window. This document provides an overview of its core classes, their functionality, and the methods for managing the game state.

---

## Classes and Methods

### 1. `RlibWindow`
Manages the Raylib window, including initialization, rendering, and user input handling.

#### Constructor
- `RlibWindow(int windowWidth, int windowHeight, std::string title, Color backgroundColor, int frameRateLimit)`: Sets up window properties and initial states.
- `RlibWindow(std::string filename)`: Loads settings from a JSON file.

#### Methods
- `setDefaultVal()`: Sets initial values for window configuration, including menu management and key press tracking.
- `setWidth(int windowWidth)`, `setHeight(int windowHeight)`, `setSize(int width, int height)`: Adjusts window dimensions.
- `setWindowPosition(int windowX, int windowY)`, `setWindowPosX(int windowX)`, `setWindowPosY(int windowY)`: Sets window position.
- `setTitle(std::string title)`: Sets the window title.
- `swapSettings()`: Toggles settings display in the menu.
- `InitRlib()`: Initializes the Raylib window and settings.
- `CloseRlibWindow()`: Closes the Raylib window.
- `update()`: Main update loop to handle resizing, drawing, and menu updates.

---

### 2. `DebugLogger`
Provides logging capabilities to monitor client activity, with adjustable verbosity levels.

#### Constructor
- `DebugLogger(bool active, int depth)`: Initializes the logger with active status and depth level.

#### Methods
- `Log(std::string msg, int depth)`: Logs messages if the current depth is within the defined logging depth.
- `SetActive(bool active)`, `SetLogDepth(int depth)`: Sets logging parameters.
- `GetActive()`, `GetLogDepth()`: Returns current logging status and depth.

---

### 3. `NetworkElem`
Manages network connection, handling server communication, connection status, and network operations.

#### Constructor
- `NetworkElem(std::shared_ptr<DebugLogger> debuglogger, std::string ip, std::string port)`: Initializes network with server details.

#### Methods
- `connect()`, `disconnect()`: Manages connection lifecycle.
- `setServerInfos(std::string ip, std::string port)`: Updates server details.
- `asyncReceive()`: Listens for incoming data asynchronously.
- `send(std::string message)`: Sends data to the server.
- `update()`: Updates network status and communication.

---

### 4. `MenuManager`
Handles game menus, integrating GUI elements and templates from JSON files.

#### Constructor
- `MenuManager(std::shared_ptr<JsonParser> jsonParser)`: Initializes menu settings.

#### Methods
- `setMenuType(menuType type)`, `getMenuType()`: Manages the current menu type.
- `setWindowSize(int width, int height)`: Adjusts window size for menu.
- `loadMenu()`, `reloadMenu()`, `drawMenu()`: Manages loading, reloading, and drawing menu elements.
- `setGameInfo(std::string ip, std::string port)`: Updates network information and sets the connection menu.

---

### 5. `JsonParser`
Loads, parses, and manages JSON files for window and menu configurations.

#### Methods
- `parseFile(std::string filename)`: Loads JSON configuration file.
- `writeFile(std::string filename, nlohmann::json json)`, `writePrettyFile(std::string filename, nlohmann::json json, int indent = 4)`: Writes JSON data to file.
- `fileHasChanged(std::string filename)`: Checks if a JSON file has been modified.

---

### 6. `Game`
Manages game state, entities, and gameplay interactions.

#### Constructor
- `Game(std::shared_ptr<JsonParser> jsonParser, std::shared_ptr<DebugLogger> debugLogger, int width, int height)`: Initializes the game with window size, parser, and logger.

#### Methods
- `initGame()`, `start()`, `update(std::string data)`: Manages game initialization, start, and state updates.
- `handleData(std::vector<std::string> tokens)`, `handlePlayer(std::string uuid, std::vector<std::string> tokens)`: Processes game data for entities.
- `draw()`: Renders game entities.
- `resetGame()`, `stop()`: Resets and stops game state.

---

## Utility Functions

- `CustomLog(int msgType, const char *text, va_list args)`: Custom log formatting with time stamps.
- `HealthCheck()`: Verifies the existence of critical JSON configuration files.
- `isIpValid(std::string ip)`, `isPortValid(std::string port)`: Validates IP and port formats.
- `splitter(std::string str, char delimiter)`: Splits strings into tokens for data parsing.

---

## JSON Configuration

### Window Settings
- **Path**: `./config/window_settings.json`
- **Properties**: Defines window dimensions, position, title, and other customizable settings.

### Menu Settings
- **Path**: `./config/menu_settings.json`
- **Properties**: Defines menu structure, including elements such as buttons, text fields, and dropdowns, with templates for GUI consistency.

---

## Notes

- Ensure that required configuration files are available and valid in the `./config/` directory for proper initialization.
- Debug logging depth is adjustable to control verbosity for development and troubleshooting.
- Ensure to put `config` and `assets` folder at the same place at the binary r-type_client in the workspace.
