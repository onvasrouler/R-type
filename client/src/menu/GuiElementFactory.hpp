/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** GuiElementFactory
*/


#pragma once

#include "../jsonParser/jsonParser.hpp"
#include "../raylibWindow/utils.hpp"
#include "../elements/guiElements/gui.hpp"

enum menuType
{
    MAIN_MENU,
    START_MENU,
    SETTINGS_GENERAL,
    SETTINGS_VIDEO,
    SETTINGS_AUDIO,
    SETTINGS_CONTROLS,
    GAME_MENU,
    CONNECTION_MENU,
    PAUSE_MENU,
    GAME_OVER_MENU
};


#define defaultErrorPosX 100
#define defaultErrorPosY 100

#define defaultErrorWidth  100
#define defaultErrorHeight 100

#define defaultErrroId "errorId"

#define defaultDoDisplayElement true

#define defaultErrorZindex 0

#define defaultErrorColor Color{255, 0, 0, 255}

class GuiElementFactory {
    public:

    struct MenuItem
        { /**< Represents a menu item stored created by funct newMenuItems. */
            int         x;
            int         y;
            int         width;
            int         length;
            std::string functionName;
        };


        GuiElementFactory(std::shared_ptr<JsonParser> jsonParser = nullptr);
        ~GuiElementFactory() = default;

        /**
     * @brief Gets the relative position.
     * @param x The x position in JSON format.
     * @param y The y position in JSON format.
     * @return The relative position as a Vector2.
     */
    Vector2 getRelativePos(const nlohmann::json_abi_v3_11_3::json& x, const nlohmann::json_abi_v3_11_3::json& y) const;

    /**
     * @brief Gets the relative position with width and height.
     * @param x The x position in JSON format.
     * @param width The width.
     * @param y The y position in JSON format.
     * @param height The height.
     * @return The relative position as a Vector2.
     */
    Vector2 getRelativePos(
        const nlohmann::json_abi_v3_11_3::json& x,
        const int                               width,
        const nlohmann::json_abi_v3_11_3::json& y,
        const int                               height) const;

    /**
     * @brief Converts a position to relative x position.
     * @param pos The position as a string.
     * @param windowWidth The width of the window.
     * @return The relative x position.
     */
    int convertToRelativePosX(std::string pos, const int windowWidth) const;

    /**
     * @brief Converts a position to relative y position.
     * @param pos The position as a string.
     * @param windowHeight The height of the window.
     * @return The relative y position.
     */
    int convertToRelativePosY(std::string pos, const int windowHeight) const;

    /**
     * @brief Converts a position to relative x position with width.
     * @param pos The position as a string.
     * @param width The width.
     * @param windowWidth The width of the window.
     * @return The relative x position.
     */
    int convertToRelativePosX(std::string pos, const int width, const int windowWidth) const;

    /**
     * @brief Converts a position to relative y position with height.
     * @param pos The position as a string.
     * @param height The height.
     * @param windowHeight The height of the window.
     * @return The relative y position.
     */
    int convertToRelativePosY(std::string pos, const int height, const int windowHeight) const;

    /**
     * @brief Converts JSON to boolean.
     * @param json The JSON object.
     * @return The boolean value.
     */
    bool jsonToBool(const nlohmann::json& json) const;

    /**
     * @brief Creates text elements from JSON.
     * @param text The JSON object representing the text.
     * @param type The type of the menu.
     * @return Shared pointer to the created RLText object.
     */
    std::shared_ptr<RLText> createTexts(const nlohmann::json& text, const menuType type);

    /**
     * @brief Creates button elements from JSON.
     * @param button The JSON object representing the button.
     * @param type The type of the menu.
     * @return Shared pointer to the created GButton object.
     */
    std::shared_ptr<GButton> createButtons(const nlohmann::json& button, const menuType type);

    /**
     * @brief Creates wind box elements from JSON.
     * @param windBox The JSON object representing the wind box.
     * @param type The type of the menu.
     * @return Shared pointer to the created GWindBox object.
     */
    std::shared_ptr<GWindBox> createWindBox(const nlohmann::json& windBox, const menuType type);

    /**
     * @brief Creates check box elements from JSON.
     * @param checkBox The JSON object representing the check box.
     * @param type The type of the menu.
     * @return Shared pointer to the created GCheckBox object.
     */
    std::shared_ptr<GCheckBox> createCheckBoxes(const nlohmann::json& checkBox, const menuType type);

    /**
     * @brief Creates slider elements from JSON.
     * @param slider The JSON object representing the slider.
     * @param type The type of the menu.
     * @return Shared pointer to the created GSlider object.
     */
    std::shared_ptr<GSlider> createSliders(const nlohmann::json& slider, const menuType type);

    /**
     * @brief Creates list elements from JSON.
     * @param list The JSON object representing the list.
     * @param type The type of the menu.
     * @return Shared pointer to the created GList object.
     */
    std::shared_ptr<GList> createLists(const nlohmann::json& list, const menuType type);

    /**
     * @brief Creates extended list elements from JSON.
     * @param listEx The JSON object representing the extended list.
     * @param type The type of the menu.
     * @return Shared pointer to the created GListEx object.
     */
    std::shared_ptr<GListEx> createListExs(const nlohmann::json& listEx, const menuType type);

    /**
     * @brief Creates text input elements from JSON.
     * @param inputText The JSON object representing the text input.
     * @param type The type of the menu.
     * @return Shared pointer to the created GTextInput object.
     */
    std::shared_ptr<GTextInput> createInputTexts(const nlohmann::json& inputText, const menuType type);

    /**
     * @brief Creates text input box elements from JSON.
     * @param inputTextBox The JSON object representing the text input box.
     * @param type The type of the menu.
     * @return Shared pointer to the created GTextInputBox object.
     */
    std::shared_ptr<GTextInputBox> createInputTextsBoxs(const nlohmann::json& inputTextBox, const menuType type);

    /**
     * @brief Creates spinner elements from JSON.
     * @param spinner The JSON object representing the spinner.
     * @param type The type of the menu.
     * @return Shared pointer to the created GSpinner object.
     */
    std::shared_ptr<GSpinner> createSpinners(const nlohmann::json& spinner, const menuType type);

    /**
     * @brief Creates value box elements from JSON.
     * @param valueBox The JSON object representing the value box.
     * @param type The type of the menu.
     * @return Shared pointer to the created GValueBox object.
     */
    std::shared_ptr<GValueBox> createValueBoxes(const nlohmann::json& valueBox, const menuType type);

    /**
     * @brief Creates group elements from JSON.
     * @param group The JSON object representing the group.
     * @param type The type of the menu.
     * @return Shared pointer to the created GGroup object.
     */
    std::shared_ptr<GGroup> createGroups(const nlohmann::json& group, const menuType type);

    /**
     * @brief Creates toggle group elements from JSON.
     * @param toggleGroup The JSON object representing the toggle group.
     * @param type The type of the menu.
     * @return Shared pointer to the created GToggleGroup object.
     */
    std::shared_ptr<GToggleGroup> createToggleGroups(const nlohmann::json& toggleGroup, const menuType type);

    /**
     * @brief Creates toggle slider elements from JSON.
     * @param toggleSlider The JSON object representing the toggle slider.
     * @param type The type of the menu.
     * @return Shared pointer to the created GToggleSlider object.
     */
    std::shared_ptr<GToggleSlider> createToggleSliders(const nlohmann::json& toggleSlider, const menuType type);

    /**
     * @brief Creates panel elements from JSON.
     * @param pannel The JSON object representing the panel.
     * @param type The type of the menu.
     * @return Shared pointer to the created GPannel object.
     */
    std::shared_ptr<GPannel> createPannels(const nlohmann::json& pannel, const menuType type);

    /**
     * @brief Creates color picker elements from JSON.
     * @param colorPicker The JSON object representing the color picker.
     * @param type The type of the menu.
     * @return Shared pointer to the created GColorPicker object.
     */
    std::shared_ptr<GColorPicker> createColorPickers(const nlohmann::json& colorPicker, const menuType type);

    /**
     * @brief Creates progress bar elements from JSON.
     * @param progressBar The JSON object representing the progress bar.
     * @param type The type of the menu.
     * @return Shared pointer to the created GProgressBar object.
     */
    std::shared_ptr<GProgressBar> createProgressBars(const nlohmann::json& progressBar, const menuType type);

    /**
     * @brief Creates drop-down elements from JSON.
     * @param dropDown The JSON object representing the drop-down.
     * @param type The type of the menu.
     * @return Shared pointer to the created GDropDown object.
     */
    std::shared_ptr<GDropDown> createDropDowns(const nlohmann::json& dropDown, const menuType type);

    /**
     * @brief Loads button elements from JSON.
     * @param buttons The JSON object representing the buttons.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsButtons(const nlohmann::json& buttons, const menuType type);

    /**
     * @brief Loads wind box elements from JSON.
     * @param windBoxes The JSON object representing the wind boxes.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsWindBoxes(const nlohmann::json& windBoxes, const menuType type);

    /**
     * @brief Loads text elements from JSON.
     * @param texts The JSON object representing the texts.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsTexts(const nlohmann::json& texts, const menuType type);

    /**
     * @brief Loads check box elements from JSON.
     * @param checkBoxes The JSON object representing the check boxes.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsCheckBoxes(const nlohmann::json& checkBoxes, const menuType type);

    /**
     * @brief Loads slider elements from JSON.
     * @param sliders The JSON object representing the sliders.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsSliders(const nlohmann::json& sliders, const menuType type);

    /**
     * @brief Loads list elements from JSON.
     * @param lists The JSON object representing the lists.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsLists(const nlohmann::json& lists, const menuType type);

    /**
     * @brief Loads extended list elements from JSON.
     * @param listExs The JSON object representing the extended lists.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsListExs(const nlohmann::json& listExs, const menuType type);

    /**
     * @brief Loads text input elements from JSON.
     * @param inputTexts The JSON object representing the text inputs.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsInputTexts(const nlohmann::json& inputTexts, const menuType type);

    /**
     * @brief Loads text input box elements from JSON.
     * @param inputTextsBoxs The JSON object representing the text input boxes.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>>
        loadsInputTextsBoxs(const nlohmann::json& inputTextsBoxs, const menuType type);

    /**
     * @brief Loads spinner elements from JSON.
     * @param spinners The JSON object representing the spinners.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsSpinners(const nlohmann::json& spinners, const menuType type);

    /**
     * @brief Loads value box elements from JSON.
     * @param valueBoxes The JSON object representing the value boxes.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsValueBoxes(const nlohmann::json& valueBoxes, const menuType type);

    /**
     * @brief Loads group elements from JSON.
     * @param groups The JSON object representing the groups.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsGroups(const nlohmann::json& groups, const menuType type);

    /**
     * @brief Loads toggle group elements from JSON.
     * @param toggleGroups The JSON object representing the toggle groups.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsToggleGroups(const nlohmann::json& toggleGroups, const menuType type);

    /**
     * @brief Loads toggle slider elements from JSON.
     * @param toggleSliders The JSON object representing the toggle sliders.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsToggleSliders(const nlohmann::json& toggleSliders, const menuType type);

    /**
     * @brief Loads panel elements from JSON.
     * @param pannels The JSON object representing the panels.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsPannels(const nlohmann::json& pannels, const menuType type);

    /**
     * @brief Loads color picker elements from JSON.
     * @param colorPickers The JSON object representing the color pickers.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsColorPickers(const nlohmann::json& colorPickers, const menuType type);

    /**
     * @brief Loads progress bar elements from JSON.
     * @param progressBars The JSON object representing the progress bars.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsProgressBars(const nlohmann::json& progressBars, const menuType type);

    /**
     * @brief Loads drop-down elements from JSON.
     * @param dropDowns The JSON object representing the drop-downs.
     * @param type The type of the menu.
     * @return Vector of shared pointers to the loaded AGuiElem objects.
     */
    std::vector<std::shared_ptr<AGuiElem>> loadsDropDowns(const nlohmann::json& dropDowns, const menuType type);

    /**
     * @brief Registers the element in a list to handle when the element is clicked
     * @param x The x position in JSON format.
     * @param y The y position in JSON format.
     * @param width The width of the element in JSON format.
     * @param length The length of the element in JSON format.
     * @param functionName The name of the function to call when the element is clicked.
     * @param type The type of the menu.
     */
    void newMenuItems(
        const nlohmann::json_abi_v3_11_3::json& x,
        const nlohmann::json_abi_v3_11_3::json& y,
        const nlohmann::json_abi_v3_11_3::json& width,
        const nlohmann::json_abi_v3_11_3::json& length,
        std::string                             functionName,
        menuType                                type);
    
    void setJsonParser(const std::shared_ptr<JsonParser> jsonParser);
    void setDebugLogger(const std::shared_ptr<DebugLogger> debugLogger);

    void setWindowWidth(const int windowWidth);
    void setWindowHeight(const int windowHeight);
    void setWindowSize(const int windowWidth, const int windowHeight);
    
    std::map<menuType, std::vector<MenuItem>> getMenuItems() const;

    void clearMenuItems();

    private:

        std::shared_ptr<JsonParser>  _JsonParser; /**< Shared pointer to a JsonParser object. */
        std::shared_ptr<DebugLogger> _DebugLogger; /**< Shared pointer to a DebugLogger object. */


    int _WindowWidth; /**< The width of the window. is used for responsivity */
    int _WindowHeight; /**< The height of the window. is used for responsivity */

    std::map<menuType, std::vector<MenuItem>>
        _MenuItems; /**< Map of menu types to MenuItem objects used to handle and treat click. */
};