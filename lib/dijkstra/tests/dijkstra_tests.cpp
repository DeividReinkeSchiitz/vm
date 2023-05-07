//
// Created by deivid on 04/23/23.
//

extern "C"
{
#include "dijkstra.h"
}

#include <gtest/gtest.h>
#include <iostream>


TEST(DijkstraTest, PushTest)
{
    DGraph *g = dgraph_mk(3);

    dgraph_pushedge(g, 0, "192.0.0.0", 0);
    dgraph_pushedge(g, 0, "10.1.0.99", 8);

    dgraph_pushedge(g, 1, "10.1.0.99", 0);
    dgraph_pushedge(g, 1, "10.1.0.8989", 11);

    EXPECT_EQ(g->num_vertices, 2);
    EXPECT_EQ(g->capacity, 3);

    EXPECT_EQ(g->adj[0]->weight, 0);
    EXPECT_TRUE(strcmp(g->adj[0]->vertex, "192.0.0.0") == 0);
    EXPECT_EQ(g->adj[0]->next->weight, 8);
    EXPECT_TRUE(strcmp(g->adj[0]->next->vertex, "10.1.0.99") == 0);

    EXPECT_EQ(g->adj[1]->weight, 0);
    EXPECT_TRUE(strcmp(g->adj[1]->vertex, "10.1.0.99") == 0);
    EXPECT_EQ(g->adj[1]->next->weight, 11);
    EXPECT_TRUE(strcmp(g->adj[1]->next->vertex, "10.1.0.8989") == 0);

    dgraph_delete(g);
}

TEST(DijkstraTest, HeapTest)
{
    static int n      = 8;

    int unexpected[8] = {26, 4, 12, 18, 16, 8, 9, 6};
    // min heap expected result
    int expected[8]   = {4, 6, 8, 16, 18, 12, 9, 26};

    Heap *h           = createHeap(n);

    char str[12];
    for (int i = 0; i < n; i++)
    {
        // convert integer to a const char*
        sprintf(str, "%d", unexpected[i]);
        heap_insert(h, str, unexpected[i]);
    }

    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(h->arr[i].weight, expected[i]);
        EXPECT_TRUE(strcmp(h->arr[i].vertex, std::to_string(expected[i]).c_str()) == 0);
    }

    HeapNode min = heap_extractmin(h);
    EXPECT_EQ(min.weight, 4);
    EXPECT_TRUE(strcmp(min.vertex, "4") == 0);

    min = heap_extractmin(h);
    EXPECT_EQ(min.weight, 6);
    EXPECT_TRUE(strcmp(min.vertex, "6") == 0);

    heap_decrease_key(h, 5, 1);


    free(h);
}

TEST(DijkstraTest, MinCostTest1)
{
    DGraph *g = dgraph_mk(10);

    dgraph_pushedge(g, 0, "A", 0);
    dgraph_pushedge(g, 0, "C", 3);
    dgraph_pushedge(g, 0, "F", 2);

    dgraph_pushedge(g, 1, "C", 0);
    dgraph_pushedge(g, 1, "A", 3);
    dgraph_pushedge(g, 1, "F", 2);
    dgraph_pushedge(g, 1, "D", 4);
    dgraph_pushedge(g, 1, "E", 1);

    dgraph_pushedge(g, 2, "F", 0);
    dgraph_pushedge(g, 2, "A", 2);
    dgraph_pushedge(g, 2, "C", 2);
    dgraph_pushedge(g, 2, "E", 3);
    dgraph_pushedge(g, 2, "B", 6);
    dgraph_pushedge(g, 2, "G", 5);

    dgraph_pushedge(g, 3, "D", 0);
    dgraph_pushedge(g, 3, "C", 4);
    dgraph_pushedge(g, 3, "B", 1);

    dgraph_pushedge(g, 4, "E", 0);
    dgraph_pushedge(g, 4, "C", 1);
    dgraph_pushedge(g, 4, "B", 2);
    dgraph_pushedge(g, 4, "F", 3);

    dgraph_pushedge(g, 5, "G", 0);
    dgraph_pushedge(g, 5, "F", 5);
    dgraph_pushedge(g, 5, "B", 2);

    dgraph_pushedge(g, 6, "B", 0);
    dgraph_pushedge(g, 6, "D", 1);
    dgraph_pushedge(g, 6, "E", 2);
    dgraph_pushedge(g, 6, "F", 6);
    dgraph_pushedge(g, 6, "G", 2);

    EXPECT_EQ(minCost(g), 8);

    dgraph_delete(g);
}

TEST(DijkstraTest, MinCostTest2)
{
    DGraph *g = dgraph_mk(10);

    dgraph_pushedge(g, 0, "192.0.0.0", 0);
    dgraph_pushedge(g, 0, "10.1.0.2", 4);
    dgraph_pushedge(g, 0, "10.10.10.1", 8);

    dgraph_pushedge(g, 1, "10.1.0.2", 0);
    dgraph_pushedge(g, 1, "192.0.0.0", 4);
    dgraph_pushedge(g, 1, "10.11.1.7", 8);
    dgraph_pushedge(g, 1, "10.10.10.1", 11);

    dgraph_pushedge(g, 2, "10.11.1.7", 0);
    dgraph_pushedge(g, 2, "192.1.1.1", 7);
    dgraph_pushedge(g, 2, "10.5.3.2", 4);
    dgraph_pushedge(g, 2, "10.2.92.6", 2);
    dgraph_pushedge(g, 2, "10.1.0.2", 8);

    dgraph_pushedge(g, 3, "10.10.10.1", 0);
    dgraph_pushedge(g, 3, "192.0.0.0", 8);
    dgraph_pushedge(g, 3, "10.1.0.2", 11);
    dgraph_pushedge(g, 3, "10.2.92.6", 7);
    dgraph_pushedge(g, 3, "192.192.1.1", 1);

    dgraph_pushedge(g, 4, "10.2.92.6", 0);
    dgraph_pushedge(g, 4, "10.11.1.7", 2);
    dgraph_pushedge(g, 4, "10.10.10.1", 7);
    dgraph_pushedge(g, 4, "192.192.1.1", 6);

    dgraph_pushedge(g, 5, "192.1.1.1", 0);
    dgraph_pushedge(g, 5, "10.1.7.7", 9);
    dgraph_pushedge(g, 5, "10.5.3.2", 14);
    dgraph_pushedge(g, 5, "10.11.1.7", 7);

    dgraph_pushedge(g, 6, "10.1.7.7", 0);
    dgraph_pushedge(g, 6, "192.1.1.1", 9);
    dgraph_pushedge(g, 6, "10.5.3.2", 10);

    dgraph_pushedge(g, 7, "10.5.3.2", 0);
    dgraph_pushedge(g, 7, "192.1.1.1", 14);
    dgraph_pushedge(g, 7, "10.1.7.7", 10);
    dgraph_pushedge(g, 7, "10.11.1.7", 4);
    dgraph_pushedge(g, 7, "192.192.1.1", 2);

    dgraph_pushedge(g, 8, "192.192.1.1", 0);
    dgraph_pushedge(g, 8, "10.5.3.2", 2);
    dgraph_pushedge(g, 8, "10.2.92.6", 6);
    dgraph_pushedge(g, 8, "10.10.10.1", 1);

    EXPECT_EQ(minCost(g), 37);

    dgraph_delete(g);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}