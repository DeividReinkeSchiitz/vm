extern "C"
{
#include "heap.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(HeapTest, MaxHeapTest)
{
    int heap[MAX_HEAP_SIZE] = {10, 20, 15, 40, 50, 100, 25};
    int n                   = 7;
    heap_make(n, heap);

    EXPECT_EQ(100, heap_maxv(heap));
    EXPECT_EQ(100, heap_pop(&n, heap));
    EXPECT_EQ(50, heap_maxv(heap));

    heap_insert(&n, heap, 90);
    EXPECT_EQ(90, heap_maxv(heap));
}

TEST(HeapTest, PromoteTest)
{
    int heap[MAX_HEAP_SIZE] = {10, 20, 15, 40, 50, 100, 25};
    int n                   = 7;
    heap_make(n, heap);

    heap_promote(n, heap, 2, 70);  // increase priority of 15 to 70
    EXPECT_EQ(100, heap_maxv(heap));
    EXPECT_EQ(100, heap_pop(&n, heap));
    EXPECT_EQ(70, heap_pop(&n, heap));
}

TEST(HeapTest, HeapSortTest)
{
    int unsorted[MAX_HEAP_SIZE] = {10, 20, 15, 40, 50, 100, 25};
    int expected[MAX_HEAP_SIZE] = {10, 15, 20, 25, 40, 50, 100};
    int n                       = 7;

    heapsort(n, unsorted);
    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(expected[i], unsorted[i]);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}