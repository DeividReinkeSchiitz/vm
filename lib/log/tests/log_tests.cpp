//
// Created by deivid on 1/30/23.
//

extern "C"
{
#include "log.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(LogTest, LogTest)
{
    log_msg(LOG_INFO, (char *) "This is a test message");
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}