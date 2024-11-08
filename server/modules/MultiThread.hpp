/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#ifdef _WIN32
    #include <Ws2tcpip.h>
    #define WIN32_LEAN_AND_MEAN
    #define _WIN32_WINNT 0x0A00
#endif

#include <memory>
#include <iostream>
#include <any>
#include <thread>
#include <vector>
#include "UUID.hpp"
#ifdef _WIN32
    #if defined(_WIN32) && defined(WIN32_LEAN_AND_MEAN)
        #include <winsock2.h>
    #else
        #include <winsock.h>
    #endif
    #include <windows.h>
    #pragma comment(lib, "ws2_32.lib") // Lien avec la bibliothèque WS2_32.lib
#else
    #include "sys/socket.h"
    #include <arpa/inet.h>
    #include "netinet/in.h"
    #include <unistd.h>
    #ifdef __APPLE__
        #include "sys/select.h"
    #endif
#endif

#define PORT 8081
#define THREAD_END_MESSAGE "\n\t"
#define DEBUG_MACRO "Debug: "

/**
 * @brief The MultiThreadData class is a class to store data in a multithread context.
 * Every module of the server and the server itself are multithread elements.
 */
class MultiThreadData {
    public:
        /**
         * @brief Constructor of MultiThreadData.
         */
        MultiThreadData();
        /**
         * @brief Constructor of MultiThreadData.
         * @param data The data to store.
         */
        MultiThreadData(const std::any data);
        /**
         * @brief Destructor of MultiThreadData.
         */
        ~MultiThreadData() = default;
        /**
         * @brief Get the data stored.
         * @return The data stored.
         */
        std::any getData() const;
        /**
         * @brief Set the data stored.
         * @param data The data to store.
         */
        void setData(const std::any data);
        /**
         * @brief Set the data stored.
         * @param data The data to store.
         */
    protected:
        std::any _data; /*!< The data stored. */
};

class MultiThreadElement {
    public:
        /**
         * @brief The main loop of a multithread element
         */
        virtual void run() = 0;
    protected:
        /**
         * @brief Constructor of MultiThreadElement.
         */
        MultiThreadElement();
        /**
         * @brief Destructor of MultiThreadElement.
         */
        virtual ~MultiThreadElement() = default;
        /**
         * @brief Start the module.
         */
        virtual std::string decodeInterCommunication(std::string message) = 0;
        /**
         * @brief Stop the module.
         */
        virtual std::string encodeInterCommunication(std::string message) = 0;

        std::thread _thread; /*!< The thread of the module. */
        std::vector<MultiThreadData> _datas; /*!< The data stored. */
        std::vector<std::string> _sendingIntern; /*!< The messages to send. */
        std::vector<std::string> _receivedIntern; /*!< The messages received. */
        #ifdef _WIN32
            SOCKET _socket; /*!< The socket of the module. */
            std::vector<SOCKET> _otherModules; /*!< The sockets of the other modules. */
        #else
            int _socket; /*!< The socket of the module. */
            std::vector<int> _otherModules; /*!< The sockets of the other modules. */
        #endif
};
