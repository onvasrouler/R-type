/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include <memory>
#include <iostream>
#include <any>
#include <thread>
#include <vector>
#ifdef _WIN32
     #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib") // Lien avec la bibliothèque WS2_32.lib
#else
    #include "sys/socket.h"
#endif

#define PORT 8081
#define THREAD_END_MESSAGE "\n\t"

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
        void setData(std::any &data);
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
