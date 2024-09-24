/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "Thread.hpp"
#include "Mutex.hpp"
#include <memory>
#include <iostream>
#include <any>

class MultiThreadElement {
    public:
        Thread getThread() const;
        virtual void run() = 0;
    protected:
        MultiThreadElement();
        MultiThreadElement(const int serverInterSocket);
        ~MultiThreadElement() = default;
        virtual void decodeInterCommunication(std::string message);
        virtual void encodeInterCommunication(std::string message);
        Thread _thread;
        std::vector<MultiThreadData> _datas;
        std::vector<int> _otherElements;
        std::vector<std::string> _sendingMessages;
        std::vector<std::string> _receivedMessages;
        int _socket;
};

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
