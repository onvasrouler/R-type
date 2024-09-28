/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../lib/MultiThread.hpp"

class AbstractModule : public MultiThreadElement {
    public:
        AbstractModule();
        #ifdef _WIN32
            AbstractModule(const SOCKET serverInterSocket);
        #else
            AbstractModule(const int serverInterSocket);
        #endif
        ~AbstractModule();
        void start();
        void run() override;
        void stop();
    protected:
        virtual void decodeInterCommunication(std::string message) override;
        virtual void encodeInterCommunication(std::string message) override;
        bool _Running;
};
