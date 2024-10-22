/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib") // Lien avec la bibliothèque WS2_32.lib
#else
#include "sys/socket.h"
#endif
#include "../UUID.hpp"
#include <string>

/**
 * @class Client
 * @brief Represents a client with an IP address, port, and UUID.
 *
 * The Client class encapsulates the details of a client, including its IP
 * address, port number, and universally unique identifier (UUID). It provides
 * methods to retrieve these details and supports comparison operations.
 */
class Client {
  public:
    /**
     * @brief Default constructor for the Client class.
     */
    Client();

    /**
     * @brief Parameterized constructor for the Client class.
     *
     * @param ip The IP address of the client.
     * @param port The port number of the client.
     * @param uuid The universally unique identifier (UUID) of the client.
     */
    Client(const std::string ip, const std::size_t port, const uuid uuid);

    /**
     * @brief Copy constructor for the Client class.
     *
     * @param client The Client object to copy from.
     */
    Client(const Client& client);

    /**
     * @brief Destructor for the Client class.
     */
    ~Client() = default;

    /**
     * @brief Retrieves the IP address of the client.
     *
     * @return The IP address as a std::string.
     */
    const std::string getIp() const;

    /**
     * @brief Retrieves the port number of the client.
     *
     * @return The port number as a std::size_t.
     */
    const std::size_t getPort() const;

    /**
     * @brief Retrieves the UUID of the client.
     *
     * @return The UUID as a uuid.
     */
    const std::string getUuid() const;

    /**
     * @brief Equality operator for comparing two Client objects.
     *
     * @param client The Client object to compare with.
     * @return True if the clients are equal, false otherwise.
     */
    bool operator==(const Client& client) const;

    /**
     * @brief Inequality operator for comparing two Client objects.
     *
     * @param client The Client object to compare with.
     * @return True if the clients are not equal, false otherwise.
     */
    bool operator!=(const Client& client) const;

    /**
     * @brief Assignment operator for the Client class.
     *
     * @param client The Client object to assign from.
     * @return A reference to the assigned Client object.
     */
    Client operator=(const Client& client);

  protected:
    const std::string _ip;
    const std::size_t _port;
    const std::string _uuid;
};
