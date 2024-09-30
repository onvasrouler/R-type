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
    MultiThreadData data = MultiThreadData(std::string("test"));

    std::string dataStr = std::any_cast<std::string>(data.getData());
    ASSERT_EQ(dataStr, "test");
}
