//
// Created by deivid on 1/30/23.
//

extern "C"
{
#include "sllist.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(LogTest, LogTest)
{
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}