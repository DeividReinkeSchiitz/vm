//
// Created by deivid on 6/20/23.
//

extern "C"
{
#include "avl.h"
}


#include <gtest/gtest.h>
#include <iostream>

TEST(LogTest, LogTest)
{
    int arr[]     = {10, 5, 15, 3, 7, 12, 9};
    int arr_exp[] = {3, 5, 7, 9, 10, 12, 15};
    int n         = sizeof(arr) / sizeof(arr[0]);

    avl_sort(arr, n);

    for (int i = 0; i < n; i++)
        EXPECT_EQ(arr_exp[i], arr[i]);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}