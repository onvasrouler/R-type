/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <uuid/uuid.h>
#include <string>

class uuid {
    public:
        uuid();
        uuid(const std::string& id);
        ~uuid();
        bool operator==(const uuid& other) const;
        bool operator!=(const uuid& other) const;
        std::string toString() const;
        const uuid_t& getId() const;
    private:
        uuid_t _id;
};
