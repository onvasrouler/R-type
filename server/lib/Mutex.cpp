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
    _mutex = std::make_unique<pthread_mutex_t>();
    pthread_mutex_init(_mutex.get(), NULL);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(_mutex.get());
}

void Mutex::lock()
{
    pthread_mutex_lock(_mutex.get());
}

void Mutex::unlock()
{
    pthread_mutex_unlock(_mutex.get());
}

bool Mutex::isLocked()
{
    return pthread_mutex_trylock(_mutex.get()) != 0;
}
