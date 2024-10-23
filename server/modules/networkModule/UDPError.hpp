/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** UDPError.hpp
*/

#pragma once

#include <exception>
#include <string>

/**
 * @class UDPError
 * @brief A custom exception class for handling UDP server errors.
 *
 * This class encapsulates errors specific to the UDP server, allowing for
 * better error reporting and handling.
 */
class UDPError : public std::exception {
  public:
    /**
     * @brief Constructs a new UDPError object with an error message.
     *
     * @param message A string describing the error.
     */
    explicit UDPError(const std::string& message) : _message(message) {}

    /**
     * @brief Returns the error message as a C-string.
     *
     * @return const char* The error message.
     */
    const char* what() const noexcept override {
        return _message.c_str();
    }

  private:
    /// The error message describing the exception.
    std::string _message;
};
