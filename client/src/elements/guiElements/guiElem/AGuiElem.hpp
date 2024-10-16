/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** IGuiElem
*/

#pragma once

#include "IGuiElem.hpp"

/**
 * @class AGuiElem
 * @brief Abstract base class for GUI elements.
 * 
 * This class provides a common interface and basic functionality for GUI elements.
 * It inherits from the IGuiElem interface and provides several methods for managing
 * the properties of a GUI element such as position, size, text, value, ID, display state,
 * and z-index.
 * 
 * @param pos Initial position of the GUI element. Default is {0, 0}.
 * @param size Initial size of the GUI element. Default is {100, 50}.
 * @param text Initial text of the GUI element. Default is "default".
 * @param zindex Initial z-index of the GUI element. Default is 0.
 * @param id Initial ID of the GUI element. Default is "default".
 * @param display Initial display state of the GUI element. Default is false.
 * 
 * @note This class is abstract and cannot be instantiated directly. It must be inherited
 *       and the draw() method must be implemented by the derived class.
**/
class AGuiElem : public IGuiElem {
public:

    /**
     * @brief Constructs a new AGuiElem object.
     * 
     * @param pos Initial position of the GUI element. Default is {0, 0}.
     * @param size Initial size of the GUI element. Default is {100, 50}.
     * @param text Initial text of the GUI element. Default is "default".
     * @param zindex Initial z-index of the GUI element. Default is 0.
     * @param id Initial ID of the GUI element. Default is "default".
     * @param display Initial display state of the GUI element. Default is false.
     */
    AGuiElem(const Vector2 pos = {0, 0}, const Vector2 size = {100, 50}, const std::string text = "default", const int zindex = 0, const std::string id = "default", const bool display = false);

    /**
     * @brief Default destructor for AGuiElem.
     */
    virtual ~AGuiElem() = default;

    /**
     * @brief Sets the text of the GUI element.
     * 
     * @param text The new text for the GUI element.
     */
    virtual void draw() const = 0;

    /**
     * @brief Sets the text of the GUI element.
     * 
     * @param text The new text for the GUI element.
     */
    void setText(const std::string text);

    /**
     * @brief Sets the position of the GUI element.
     * 
     * @param pos The new position for the GUI element.
     */
    void setPos(const Vector2 pos);

    /**
     * @brief Sets the size of the GUI element.
     * 
     * @param size The new size for the GUI element.
     */
    void setSize(const Vector2 size);

    /**
     * @brief Sets the value of the GUI element.
     * 
     * @param value The new value for the GUI element.
     */
    void setValue(const std::string value);

    /**
     * @brief Sets the ID of the GUI element.
     * 
     * @param id The new ID for the GUI element.
     */
    void setId(const std::string id);

    /**
     * @brief Sets the display state of the GUI element.
     * 
     * @param state The new display state for the GUI element.
     */
    void setDisplay(const bool state);

    /**
     * @brief Toggles the display state of the GUI element.
     */
    void toggleDisplay();

    /**
     * @brief Sets the z-index of the GUI element.
     * 
     * @param zIndex The new z-index for the GUI element.
     */
    void setZIndex(const int zIndex);

    /**
     * @brief Gets the text of the GUI element.
     * 
     * @return The text of the GUI element.
     */
    std::string getText() const;

    /**
     * @brief Gets the position of the GUI element.
     * 
     * @return The position of the GUI element.
     */
    Vector2 getPos() const;

    /**
     * @brief Gets the size of the GUI element.
     * 
     * @return The size of the GUI element.
     */
    Vector2 getSize() const;

    /**
     * @brief Gets the value of the GUI element.
     * 
     * @return The value of the GUI element.
     */
    std::string getValue() const;

    /**
     * @brief Gets the ID of the GUI element.
     * 
     * @return The ID of the GUI element.
     */
    std::string getId() const;

    /**
     * @brief Gets the display state of the GUI element.
     * 
     * @return The display state of the GUI element.
     */
    bool getDisplay() const;

    /**
     * @brief Gets the z-index of the GUI element.
     * 
     * @return The z-index of the GUI element.
     */
    int getZIndex() const;
protected:
    std::string _Text; /**< The text of the GUI element. */
    Vector2 _Pos; /**< The position of the GUI element. */
    Vector2 _Size; /**< The size of the GUI element. */
    std::string _Value; /**< The value of the GUI element. */
    std::string _Id; /**< The ID of the GUI element. */
    bool _Display; /**< The display state of the GUI element. */
    int _ZIndex; /**< The z-index of the GUI element. */
};
