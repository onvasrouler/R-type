/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ScopedLock.hpp"
#include <iostream>

ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    mutex.lock();
}

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}
