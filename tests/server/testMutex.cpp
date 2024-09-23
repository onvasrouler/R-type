/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** mutex tests
*/

#include <gtest/gtest.h>
#include "Mutex.hpp"

TEST(Mutex, lock)
{
    Mutex mutex;

    mutex.lock();
    ASSERT_EQ(mutex.isLocked(), true);
}

TEST(Mutex, unlock)
{
    Mutex mutex;

    mutex.lock();
    mutex.unlock();
    ASSERT_EQ(mutex.isLocked(), false);
}

TEST(Mutex, isLocked)
{
    Mutex mutex;

    mutex.lock();
    ASSERT_EQ(mutex.isLocked(), true);
    mutex.unlock();
    ASSERT_EQ(mutex.isLocked(), false);
}

TEST(Mutex, isLockedFalse)
{
    Mutex mutex;

    ASSERT_EQ(mutex.isLocked(), false);
}
