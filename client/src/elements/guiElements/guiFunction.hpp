
/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** guiFunction
*/

#pragma once

#include "../../include.hpp"

class MenuManager;

/**
 * @class guiFunction
 * @brief A class to manage GUI functions and their mappings.
 * 
 * This class provides functionality to map custom GUI functions, manage a menu manager,
 * and retrieve or clear cached functions.
 */
class guiFunction {
    public:
    /**
     * @def custom_func(name, body)
     * @brief Macro to define a custom function and add it to the function list.
     * 
     * @param name The name of the function.
     * @param body The body of the function.
     */
    #define custom_func(name, body) \
    { \
        auto fn = [this]() { body; }; \
        _FunctionList[#name] = fn; \
    }

    /**
     * @brief Default constructor for guiFunction.
     */
    guiFunction() = default;

    /**
     * @brief Default destructor for guiFunction.
     */
    ~guiFunction() = default;

    /**
     * @brief Sets the menu manager.
     * 
     * @param menumanager A shared pointer to the MenuManager.
     */
    void setMenuManager(const std::shared_ptr<MenuManager> menumanager);

    /**
     * @brief Maps custom functions to the function list.
     */
    void mapFunctions();

    /**
     * @brief Clears the cached functions.
     */
    void clearCache();

    /**
     * @brief Retrieves the function map.
     * 
     * @return An unordered map of function names to their corresponding functions.
     */
    std::unordered_map<std::string, std::function<void()>> getFunctionMap();

    /**
     * @brief Retrieves a specific function by name.
     * 
     * @param functionName The name of the function to retrieve.
     * @return The function corresponding to the given name.
     */
    std::function<void()> getFunction(const std::string functionName);


    private:
    std::unordered_map<std::string, std::function<void()>> _FunctionList; ///< A map of function names to functions.
    std::shared_ptr<MenuManager> _MenuManager; ///< A shared pointer to the MenuManager.
};
