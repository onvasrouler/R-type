/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** gui
*/

#pragma once

#include "guiElem/src/GButton/GButton.hpp"
#include "guiElem/src/GCheckBox/GCheckBox.hpp"
#include "guiElem/src/GColorPicker/GColorPicker.hpp"
#include "guiElem/src/GDropDown/GDropDown.hpp"
#include "guiElem/src/GGroup/GGroup.hpp"
#include "guiElem/src/GList/GList.hpp"
#include "guiElem/src/GListEx/GListEx.hpp"
#include "guiElem/src/GPannel/GPannel.hpp"
#include "guiElem/src/GProgressBar/GProgressBar.hpp"
#include "guiElem/src/GSlider/GSlider.hpp"
#include "guiElem/src/GSpinner/GSpinner.hpp"
#include "guiElem/src/GTextInput/GTextInput.hpp"
#include "guiElem/src/GTextInputBox/GTextInputBox.hpp"
#include "guiElem/src/GToggleGroup/GToggleGroup.hpp"
#include "guiElem/src/GToggleSlider/GToggleSlider.hpp"
#include "guiElem/src/GValueBox/GValueBox.hpp"
#include "guiElem/src/GWindBox/GWindBox.hpp"
#include "guiElem/src/Text/Text.hpp"

/**
 * @class RGui
 * @brief A class representing a graphical user interface (GUI) manager.
 * 
 * The RGui class is responsible for managing and rendering GUI elements.
 * It provides methods to draw the GUI, retrieve elements by their ID,
 * add new elements, and set a list of elements.
 */
class RGui {
public:
    /**
     * @brief Default constructor for RGui.
     */
    RGui() = default;

    /**
     * @brief Destructor for RGui.
     */
    ~RGui();

    /**
     * @brief Draws the GUI elements.
     * 
     * This method is responsible for rendering all the GUI elements managed by this class.
     */
    void DrawGui() const;

    /**
     * @brief Retrieves the value of an element by its ID.
     * 
     * @param id The ID of the element.
     * @return The value of the element as a string.
     */
    std::string GetValueById(const std::string id) const;

    /**
     * @brief Retrieves a shared pointer to an element by its ID.
     * 
     * @param id The ID of the element.
     * @return A shared pointer to the element.
     */
    const std::shared_ptr<AGuiElem> GetElementById(const std::string id) const;

    /**
     * @brief Adds a new GUI element.
     * 
     * @param elem A shared pointer to the new element to be added.
     */
    void AddElement(const std::shared_ptr<AGuiElem> elem);

    /**
     * @brief Sets the list of GUI elements.
     * 
     * @param elements A vector of shared pointers to the elements to be set.
     */
    void SetElements(const std::vector<std::shared_ptr<AGuiElem>> elements);

    /**
     * @brief Adds a list of GUI elements.
     * 
     * @param elem A vector of shared pointers to the elements to be added.
     */
    void addListElement(const std::vector<std::shared_ptr<AGuiElem>> elem);

private:
    /**
     * @brief A vector of shared pointers to the GUI elements managed by this class.
     */
    std::vector<std::shared_ptr<AGuiElem>> _elements;
};
