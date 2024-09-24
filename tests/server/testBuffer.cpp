/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** buffer tests
*/

#include <gtest/gtest.h>
#include "Buffer.hpp"

// TEST(Buffer, constructor)
// {
//     Buffer buffer = Buffer(10, "\t", "\n");
//     EXPECT_EQ(buffer.getData(), "");
//     EXPECT_EQ(buffer.getSize(), 10);
//     EXPECT_EQ(buffer.getStartSentence(), "\t");
//     EXPECT_EQ(buffer.getEndSentence(), "\n");
// }

TEST(Buffer, append)
{
    Buffer buffer = Buffer(10, "\t", "\n");
    EXPECT_EQ(buffer.append("Hello"), true);
    EXPECT_EQ(buffer.getData(), "Hello");
    EXPECT_EQ(buffer.append("Worl"), true);
    EXPECT_EQ(buffer.getData(), "HelloWorl");
    EXPECT_EQ(buffer.append("d"), true);
    EXPECT_EQ(buffer.getData(), "HelloWorld");
    EXPECT_EQ(buffer.append("HelloWorld"), false);
    EXPECT_EQ(buffer.getData(), "HelloWorld");
}

TEST(Buffer, getNext)
{
    Buffer buffer = Buffer(15, "\t", "\n");
    EXPECT_EQ(buffer.append("Hello\tWorld\n"), true);
    std::string ret = buffer.getNext();
    EXPECT_EQ(ret, "World");
    EXPECT_EQ(buffer.getNext(), "");
}

TEST(Buffer, reset)
{
    Buffer buffer = Buffer(10, "\t", "\n");
    buffer.append("Hello\tWorld\n");
    buffer.reset();
    EXPECT_EQ(buffer.getData(), "");
    EXPECT_EQ(buffer.getNext(), "");
}

TEST(Buffer, setSize)
{
    Buffer buffer = Buffer(10, "\t", "\n");
    buffer.setSize(5);
    EXPECT_EQ(buffer.getSize(), 5);
    EXPECT_EQ(buffer.append("HelloWorld"), false);
    EXPECT_EQ(buffer.getData(), "");
    EXPECT_EQ(buffer.append("Hello"), true);
    EXPECT_EQ(buffer.getData(), "Hello");
}

TEST(Buffer, setStartSentence)
{
    Buffer buffer = Buffer(15, "\t", "\n");
    buffer.setStartSentence("Hello");
    EXPECT_EQ(buffer.getStartSentence(), "Hello");
    buffer.append("Hello\tWorld\n");
    std::string ret = buffer.getNext();
    EXPECT_EQ(ret, "\tWorld");
}

TEST(Buffer, setEndSentence)
{
    Buffer buffer = Buffer(15, "\t", "\n");
    buffer.setEndSentence("ld\n");
    EXPECT_EQ(buffer.getEndSentence(), "ld\n");
    buffer.append("Hello\tWorld\n");
    std::string ret = buffer.getNext();
    EXPECT_EQ(ret, "Wor");
}

TEST(Buffer, copyConstructor)
{
    Buffer buffer = Buffer(15, "\t", "\n");
    buffer.append("Hello\tWorld\n");
    Buffer buffer2 = Buffer(buffer);
    EXPECT_EQ(buffer2.getData(), "Hello\tWorld\n");
    EXPECT_EQ(buffer2.getSize(), 15);
    EXPECT_EQ(buffer2.getStartSentence(), "\t");
    EXPECT_EQ(buffer2.getEndSentence(), "\n");
}
