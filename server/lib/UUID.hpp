/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#ifdef _WIN32
#include <rpc.h>
#pragma comment(lib, "Rpcrt4.lib")
#else
#include <uuid/uuid.h>
#endif
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
        uuid_t& uuid::getId();
    private:
        uuid_t _id;
};
