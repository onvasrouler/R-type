/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <csignal>
#include <pthread.h>
#include <memory>

class Mutex {
    public :
        Mutex();
        ~Mutex();
        void lock();
        void unlock();
        bool isLocked();
    private :
        std::unique_ptr<pthread_mutex_t> _mutex;
};
