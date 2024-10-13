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

/*
*
* @class uuid
* @brief Class that encapsulate the uuid_t struct from the uuid.h library
*/
class uuid {
    public:
        /*
        *
        * @brief Default constructor of uuid
        */
       uuid();

       uuid(const uuid &id);
        /*
        *
        * @brief Constructor of uuid
        * @param id
        */
        uuid(const std::string& id);
        /*
        *
        * @brief Destructor of uuid
        */
        ~uuid();
        /*
        *
        * @brief Operator == of uuid
        * @param other
        */
        bool operator==(const uuid& other) const;
        /*
        *
        * @brief Operator != of uuid
        * @param other
        */
        bool operator!=(const uuid& other) const;
        /*
        *
        * @brief Return the uuid as a string
        */
       uuid &operator=(const uuid &id);
        std::string toString() const;
        /*
        *
        * @brief Return the uuid as a const object
        */
        const uuid_t& getId() const;
        /*
        *
        * @brief Return the uuid
        */
        uuid_t& getId();
    private:
        uuid_t _id; //the uuid
};
