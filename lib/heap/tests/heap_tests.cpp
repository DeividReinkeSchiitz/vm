extern "C"
{
#include "heap.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(HeapTest, MakeTest)
{
    int heap[]     = {26, 4, 12, 18, 16, 8, 9, 6};
    int expected[] = {26, 18, 12, 4, 16, 8, 9};
    int n          = 7;

    heap_make(heap, n);

    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(expected[i], heap[i]);
    }
}

TEST(HeapTest, MaxHeapTest)
{
    int heap[] = {10, 20, 15, 40, 50, 100, 25};
    int n      = 7;
    heap_make(heap, n);

    EXPECT_EQ(100, heap_maxv(heap));
    EXPECT_EQ(100, heap_pop(heap, &n));
    EXPECT_EQ(50, heap_maxv(heap));

    heap_insert(heap, &n, 90);
    EXPECT_EQ(90, heap_maxv(heap));
}

TEST(HeapTest, PromoteTest)
{
    int heap[] = {10, 20, 15, 40, 50, 100, 25};
    int n      = 7;
    heap_make(heap, n);

    heap_promote(heap, n, 2, 70);  // increase priority of 15 to 70
    EXPECT_EQ(100, heap_maxv(heap));
    EXPECT_EQ(100, heap_pop(heap, &n));
    EXPECT_EQ(70, heap_pop(heap, &n));
}

TEST(HeapTest, HeapSortTest)
{
    int unsorted[] = {10, 20, 15, 40, 50, 100, 25};
    int expected[] = {10, 15, 20, 25, 40, 50, 100};
    int n          = 7;

    heap_sort(unsorted, n);
    for (int i = 0; i < n; i++)
        EXPECT_EQ(expected[i], unsorted[i]);
}

TEST(HeapTest, HeapSortTest2)
{
    int unsorted[] = {10, 20, 12, 43, 50, 102, 27, 32, 35, 45, 55, 62, 65, 70, 75, 84, 85, 90};
    int expected[] = {10, 12, 20, 27, 32, 35, 43, 45, 50, 55, 62, 65, 70, 75, 84, 85, 90, 102};
    int n          = 18;

    heap_sort(unsorted, n);
    for (int i = 0; i < n; i++)
        EXPECT_EQ(expected[i], unsorted[i]);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}