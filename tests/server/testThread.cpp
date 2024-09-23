/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** mutex tests
*/

#include <gtest/gtest.h>
#include <Thread.hpp>

void *func(void *arg)
{
    int *ret = new int(42);
    return ret;
}

void *powerTwo(void *arg)
{
    int *ret = new int(2);

    *ret *= *static_cast<int *>(arg);
    return ret;
}

void *powerTwoArg(void *arg)
{
    int *ret = new int(2);

    *static_cast<int *>(arg) *= *ret;
    return nullptr;
}

TEST(Thread, test1)
{
    Thread thread;

    thread.start(func, nullptr);
    thread.join();
}

TEST(Thread, test2)
{
    Thread thread;

    thread.start(func, nullptr);
    thread.detach();
}

TEST(Thread, test3)
{
    Thread thread;

    thread.start(func, nullptr);
    pthread_t thread_id = thread.getThread();
    EXPECT_EQ(thread_id, thread.getThread());
}

TEST(Thread, test4)
{
    Thread thread;

    thread.start(powerTwo, new int(2));
    thread.join();
}

TEST(Thread, test5)
{
    Thread thread;
    int *ret = new int(2);

    thread.start(powerTwoArg, ret);
    thread.join();
    EXPECT_EQ(*ret, 4);
}
