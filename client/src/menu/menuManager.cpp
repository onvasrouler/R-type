/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menus
*/

#include "menuManager.hpp"
#include "../elements/guiElements/guiFunction.hpp"

MenuManager::MenuManager()
{
    this->_type = START_MENU;
    this->_WindowHeight = GetScreenHeight();
    this->_WindowWidth = GetScreenWidth();
    _Is_connecting = false;
    this->_GuiElementFactory = std::make_shared<GuiElementFactory>();
    this->_GuiElementFactory->setWindowHeight(this->_WindowHeight);
    this->_GuiElementFactory->setWindowWidth(this->_WindowWidth);
}

MenuManager::MenuManager(std::shared_ptr<JsonParser> jsonParser)
{
    this->_type = START_MENU;
    this->_JsonParser = jsonParser;
    _Is_connecting = false;
    this->_GuiElementFactory = std::make_shared<GuiElementFactory>(jsonParser);

}

void MenuManager::setMenuType(const menuType type)
{
    this->_type = type;
}

void MenuManager::setMenuType(const int typeId)
{
    this->_type = static_cast<menuType>(typeId);
}


enum menuType MenuManager::getMenuType() const
{
    return this->_type;
}

void MenuManager::setWindowHeight(const int windowHeight)
{
    this->_WindowHeight = windowHeight;
    this->_GuiElementFactory->setWindowHeight(windowHeight);
}

void MenuManager::setWindowWidth(const int windowWidth)
{
    this->_WindowWidth = windowWidth;
    this->_GuiElementFactory->setWindowWidth(windowWidth);
}

void MenuManager::setWindowSize(const int windowWidth, const int windowHeight)
{
    this->setWindowHeight(windowHeight);
    this->setWindowWidth(windowWidth);
    this->_GuiElementFactory->setWindowWidth(windowWidth);
    this->_GuiElementFactory->setWindowHeight(windowHeight);
}

int MenuManager::getWindowHeight() const
{
    return this->_WindowHeight;
}

int MenuManager::getWindowWidth() const
{
    return this->_WindowWidth;
}

void MenuManager::setBackgroundColor(const Color color)
{
    this->_BackgroundColor = color;
}

void MenuManager::setGame(std::shared_ptr<Game> game)
{
    _Game = game;
    if (_NetworkElem)
        _NetworkElem->setGame(game);
    else
        this->_DebugLogger->Log("NetworkElem not setted", 0);
}

void MenuManager::setNetworkElem(std::shared_ptr<NetworkElem> networkElem)
{
    _NetworkElem = networkElem;
    if (_Game)
        _NetworkElem->setGame(_Game);
    else
        this->_DebugLogger->Log("Game not setted", 0);
}

std::shared_ptr<MenuManager> MenuManager::getThis()
{
    return shared_from_this();
}

void MenuManager::setGuiFunction(std::shared_ptr<guiFunction> guifunction)
{
    this->_guiFunction = guifunction;
}

void MenuManager::loadMenu()
{
    this->_DebugLogger->Log("Loading Menu", 2);
    this->_menuJson = _JsonParser->parseFile("./config/menu_settings.json");
    this->_menuTemplate = _menuJson["templates"];

    this->_DebugLogger->Log("Menu Loaded creating every elements", 2);
    for (auto &menu : _menuJson["menus"]) {
        if (menu["isSimple"] == false)
            continue;
        if (!menu.is_null()) {
            menuType type = static_cast<menuType>(menu["id"]);
            this->_menuList[type] = std::make_shared<RGui>();
            this->integrateTemplate(menu, menu["id"]);
            this->createMenu(menu, menu["id"]);
        }
    }
}

std::shared_ptr<RGui> MenuManager::getCurrentGui() const
{
    return this->_menuList.at(this->_type);
}

void MenuManager::reloadMenu()
{
    this->_DebugLogger->Log("Menu Reloaded", 2);
    this->eraseMenu();
    this->loadMenu();
}

void MenuManager::reloadOnChanges()
{
    if (_JsonParser->fileHasChanged("./config/menu_settings.json"))
        this->reloadMenu();
}

void MenuManager::createMenu(const nlohmann::json &menu, const int menuID)
{
    menuType type;

    try {   
        type = static_cast<menuType>(menuID);
        this->_DebugLogger->Log("Creating Texts", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsTexts(menu, type));
        this->_DebugLogger->Log("Creating Buttons", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsButtons(menu, type));
        this->_DebugLogger->Log("Creating WindBoxes", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsWindBoxes(menu, type));
        this->_DebugLogger->Log("Creating CheckBoxes", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsCheckBoxes(menu, type));
        this->_DebugLogger->Log("Creating Sliders", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsSliders(menu, type));
        this->_DebugLogger->Log("Creating Lists", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsLists(menu, type));
        this->_DebugLogger->Log("Creating ListExs", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsListExs(menu, type));
        this->_DebugLogger->Log("Creating InputTexts", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsInputTexts(menu, type));
        this->_DebugLogger->Log("Creating InputTextBoxs", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsInputTextsBoxs(menu, type));
        this->_DebugLogger->Log("Creating Spinners", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsSpinners(menu, type));
        this->_DebugLogger->Log("Creating ValueBoxes", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsValueBoxes(menu, type));
        this->_DebugLogger->Log("Creating Groups", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsGroups(menu, type));
        this->_DebugLogger->Log("Creating ToggleGroups", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsToggleGroups(menu, type));
        this->_DebugLogger->Log("Creating ToggleSliders", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsToggleSliders(menu, type));
        this->_DebugLogger->Log("Creating Pannels", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsPannels(menu, type));
        this->_DebugLogger->Log("Creating ColorPickers", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsColorPickers(menu, type));
        this->_DebugLogger->Log("Creating ProgressBars", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsProgressBars(menu, type));
        this->_DebugLogger->Log("Creating DropDowns", 4);
        this->_menuList[type]->addListElement(_GuiElementFactory->loadsDropDowns(menu, type));
    } catch (std::exception &e) {
        this->_DebugLogger->Log("invalid json : " + std::string(e.what()), 0);
    }

    this->_MenuItems = _GuiElementFactory->getMenuItems();
}

Color MenuManager::getBackgroundColor() const
{
    return this->_BackgroundColor;
}

void MenuManager::integrateTemplate(const nlohmann::json &menu, const int menuID)
{
    this->_DebugLogger->Log("Integrating template", 3);
    if (menu.contains("templates")) {
        for (auto &templateID : menu["templates"]) {
            if (_menuTemplate.contains(templateID)) {
                this->createMenu(_menuTemplate[templateID], menuID);
            }
        }
    }
}

void MenuManager::eraseMenu()
{
    this->_DebugLogger->Log("Erasing Menu", 1);
    this->_menuList.clear();
    this->_GuiElementFactory->clearMenuItems();
    this->_JsonParser->eraseCache("./config/menu_settings.json");
}

void MenuManager::setGameInfo(const std::string ip, const std::string port) // ajouter std::string username
{
    _Ip = ip;
    _Port = port;
    if (_NetworkElem)
        _NetworkElem->setServerInfos(ip, port); // ajouter username
    else
        this->_DebugLogger->Log("NetworkElem not setted", 0);
    this->setMenuType(CONNECTION_MENU);
    _Is_connecting = true;
    this->_NetworkElem->connect();
}

void MenuManager::setJsonParser(std::shared_ptr<JsonParser> jsonParser)
{
    this->_JsonParser = jsonParser;
}

void MenuManager::setDebugLogger(std::shared_ptr<DebugLogger> debugLogger)
{
    this->_DebugLogger = debugLogger;
    this->_GuiElementFactory->setDebugLogger(debugLogger);
    this->_DebugLogger->Log("MenuManager DebugLogger setted");
}

void MenuManager::checkForNetwork()
{

    if (this->_NetworkElem->getStatus() == NetworkElem::Status::CONNECTING)
        const_cast<MenuManager*>(this)->setMenuType(CONNECTION_MENU);
    else if (this->_NetworkElem->getStatus() == NetworkElem::Status::CONNECTED) {
        const_cast<MenuManager*>(this)->setMenuType(GAME_MENU);
        _Is_connecting = false;
    } else
        const_cast<MenuManager*>(this)->setMenuType(START_MENU);
    if (this->_NetworkElem->getStatus() == NetworkElem::Status::CONNECTION_FAILED) {
        _Is_connecting = false;
        this->_NetworkElem->disconnect();
    }
    
}

void MenuManager::drawMenu() const
{
    if (_DebugLogger)
        this->_DebugLogger->Log("Drawing menu in menu manager", 2);
    if (_Is_connecting)
        const_cast<MenuManager*>(this)->checkForNetwork();
    if (this->_menuList.find(_type) != this->_menuList.end())
        this->_menuList.at(_type)->DrawGui();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        //check that the list of menu items is not empty
        if (this->_MenuItems.find(_type) == this->_MenuItems.end())
            return;
        for (auto &item : this->_MenuItems.at(_type)) {
            if (CheckCollisionPointRec(mousePosition, Rectangle{static_cast<float>(item.x), static_cast<float>(item.y), static_cast<float>(item.width), static_cast<float>(item.length)})) {
                std::function<void()> func = _guiFunction->getFunction(item.functionName);
                if (func != nullptr)
                    func();
            }
        }
    }
    if (_Game)
        this->_Game->draw();
}

void MenuManager::handleInput(int key, int pressedOrReleased)
{
    if (_Game)
        this->_Game->handleInput(key, pressedOrReleased);
}