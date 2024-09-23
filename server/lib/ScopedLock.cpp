/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex)
{
    _mutex.reset(&mutex);
    _mutex->lock();
}

ScopedLock::~ScopedLock()
{
    _mutex->unlock();
}
