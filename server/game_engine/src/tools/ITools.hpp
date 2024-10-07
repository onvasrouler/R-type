/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ITools
*/

/**
 * @file ITools.hpp
 * @brief Declaration of the ITools interface.
 */

#pragma once

/**
 * @class ITools
 * @brief Interface for tools with a value.
 * 
 * The ITools interface provides pure virtual methods to set and get the value of the tool.
 */
class ITools
{
public:
    /**
     * @brief Virtual destructor for ITools.
     * 
     * This destructor ensures that derived classes can be properly cleaned up.
     */
    virtual ~ITools() = default;

    /**
     * @brief Set the value of the tool.
     * 
     * @param value The new value to be set.
     * 
     * This pure virtual method must be implemented by derived classes to set the value of the tool.
     */
    virtual void set_value(const int value) = 0;

    /**
     * @brief Get the value of the tool.
     * 
     * @return int The current value of the tool.
     * 
     * This pure virtual method must be implemented by derived classes to get the value of the tool.
     */
    virtual int get_value() = 0;
};