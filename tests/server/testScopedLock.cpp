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

void test(Mutex mutex)
{
    ScopedLock lock(mutex);
    ASSERT_EQ(mutex.isLocked(), true);
}

TEST(ScopedLock, unlock)
{
    Mutex mutex;

    test(mutex);
    ASSERT_EQ(mutex.isLocked(), false);
}
