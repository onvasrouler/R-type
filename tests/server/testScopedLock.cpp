/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** buffer tests
*/

#include <gtest/gtest.h>
#include "ScopedLock.hpp"

TEST(ScopedLock, lock)
{
    Mutex mutex;

    ScopedLock lock(mutex);
    ASSERT_EQ(mutex.isLocked(), true);
}

TEST(ScopedLock, unlock)
{
    Mutex mutex;

    {
        ScopedLock lock(mutex);
    }
    ASSERT_EQ(mutex.isLocked(), false);
}

TEST(ScopedLock, lock)
{
    Mutex mutex;

    ScopedLock lock(mutex);
    ASSERT_EQ(mutex.isLocked(), true);
    lock.~ScopedLock();
    ASSERT_EQ(mutex.isLocked(), false);
}
