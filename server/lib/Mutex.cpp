/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Mutex.hpp"
#include <iostream>

Mutex::Mutex()
{
    pthread_mutex_init(&_mutex, NULL);
}

Mutex::Mutex(const Mutex &mutex)
{
    _mutex = mutex._mutex;
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

bool Mutex::isLocked()
{
    return pthread_mutex_trylock(&_mutex) != 0;
}

Mutex &Mutex::operator=(const Mutex &mutex)
{
    if (this == &mutex)
        return *this;
    _mutex = mutex._mutex;
    return *this;
}
