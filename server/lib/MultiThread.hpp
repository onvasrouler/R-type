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
        MultiThreadElement(const int serverInterSocket);
        virtual ~MultiThreadElement() = default;
        virtual void decodeInterCommunication(std::string message) = 0;
        virtual void encodeInterCommunication(std::string message) = 0;
        std::thread _thread;
        std::vector<MultiThreadData> _datas;
        std::vector<int> _otherModules;
        std::vector<std::string> _sendingIntern;
        std::vector<std::string> _receivedIntern;
        int _socket;
};
