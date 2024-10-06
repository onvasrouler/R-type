/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "UUID.hpp"

uuid::uuid()
{
    uuid_generate(_id);
}

uuid::uuid(const std::string &id)
{
    uuid_parse(id.c_str(), this->_id);
}

uuid::~uuid()
{
}

bool uuid::operator==(const uuid &other) const
{
    return uuid_compare(_id, other.getId()) == 0;
}

bool uuid::operator!=(const uuid &other) const
{
    return _id == other.getId();
}

std::string uuid::toString() const
{
    char str[37];
    uuid_unparse(_id, str);
    return std::string(str);
}

const uuid_t& uuid::getId() const
{
    return _id;
}
