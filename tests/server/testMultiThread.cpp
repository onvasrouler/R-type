/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** multi thread tests
*/

#include <gtest/gtest.h>
#include "MultiThread.hpp"

TEST(MultiThreadData, test1)
{
    MultiThreadData data;

    data.setData(1);
    ASSERT_EQ(std::any_cast<int>(data.getData()), 1);
}

TEST(MultiThreadData, test2)
{
    MultiThreadData data = MultiThreadData("test");

    ASSERT_EQ(std::any_cast<std::string>(data.getData()), "test");
}
