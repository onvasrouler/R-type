/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <pthread.h>
#include <memory>

class Mutex {
    public :
        Mutex();
        Mutex(const Mutex &mutex);
        ~Mutex();
        void lock();
        void unlock();
        bool isLocked();
        Mutex &operator=(const Mutex &mutex);
    private :
        pthread_mutex_t _mutex{};
};
