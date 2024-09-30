/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "../core/AbstractModule.hpp"

class SendModule : public AbstractModule {
    public:
        SendModule();
        SendModule(std::string name);
        ~SendModule();
        void encodeInterCommunication(std::string message) override;
        void decodeInterCommunication(std::string message) override;
        void run() override;
    private:
        //Need to be implemented with the network lib
};
