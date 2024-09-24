/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "uuid.h"

class uuid {
    public:
        uuid();
        ~uuid();
        bool operator==(const uuid& other) const;
        bool operator!=(const uuid& other) const;
    private:
        uuid_t id;
};
