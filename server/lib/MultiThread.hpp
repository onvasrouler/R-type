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

class MultiThreadData {
    public:
        MultiThreadData();
        MultiThreadData(const std::any data);
        ~MultiThreadData() = default;
        std::any getData() const;
        void setData(const std::any data);
        void setData(std::any &data);
    protected:
        std::any _data;
};

class MultiThreadElement {
    public:
        virtual void run() = 0;
    protected:
        MultiThreadElement();
        #ifdef _WIN32
            MultiThreadElement(const SOCKET serverInterSocket);
        #else
            MultiThreadElement(const int serverInterSocket);
        #endif
        virtual ~MultiThreadElement() = default;
        virtual void decodeInterCommunication(std::string message) = 0;
        virtual void encodeInterCommunication(std::string message) = 0;
        std::thread _thread;
        std::vector<MultiThreadData> _datas;
        std::vector<std::string> _sendingIntern;
        std::vector<std::string> _receivedIntern;
        #ifdef _WIN32
            SOCKET _socket;
            std::vector<SOCKET> _otherModules;
        #else
            int _socket;
            std::vector<int> _otherModules;
        #endif
};
