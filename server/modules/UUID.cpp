/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "UUID.hpp"
#include <iostream>

uuid::uuid()
{
    #ifdef _WIN32
    UuidCreate(&_id);
    #else
    uuid_generate(_id);
    #endif
}

uuid::uuid(const uuid &id)
{
    #ifdef _WIN32
    _id = id.getId();
    #else
    uuid_copy(_id, id.getId());
    #endif
}

uuid::uuid(const std::string &id)
{
    #ifdef _WIN32
    UuidFromStringA((RPC_CSTR)id.c_str(), &_id);
    #else
    uuid_parse(id.c_str(), this->_id);
    #endif
}

uuid::~uuid()
{
}

bool uuid::operator==(const uuid &other) const
{
    #ifdef _WIN32
    RPC_STATUS status;
    return UuidEqual(const_cast<UUID*>(&_id), const_cast<UUID*>(&other.getId()), &status) == TRUE;
    #else
    return uuid_compare(_id, other.getId()) == 0;
    #endif
}

bool uuid::operator!=(const uuid &other) const
{
    #ifdef _WIN32
    RPC_STATUS status;
    return UuidEqual(const_cast<UUID*>(&_id), const_cast<UUID*>(&other.getId()), &status) == FALSE;
    #else
    return uuid_compare(_id, other.getId()) != 0;
    #endif
}

uuid &uuid::operator=(const uuid &id)
{
    #ifdef _WIN32
    _id = id.getId();
    #else
    uuid_copy(_id, id.getId());
    #endif
    return *this;
}

std::string uuid::toString() const
{
    char str[37];
    #ifdef _WIN32
    UuidToStringA(&_id, (RPC_CSTR*)&str);
    #else
    uuid_unparse(_id, str);
    #endif
    return std::string(str);
}

uuid_t& uuid::getId()
{
    return _id;
}

const uuid_t& uuid::getId() const
{
    return _id;
}
