/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "MultiThread.hpp"

class Server : MultiThreadElement {
    public:
        Server();
        ~Server();
        void start();
        void run() override;
        void stop();
    protected:
        void decodeInterCommunication(std::string message) override;
        void encodeInterCommunication(std::string message) override;
        bool _Running;
};
