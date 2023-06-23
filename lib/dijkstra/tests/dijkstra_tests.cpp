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
    DGraph *g = dijkstra_gmk(3);

    dijkstra_pushe(g, 0, "192.0.0.0", 0);
    dijkstra_pushe(g, 0, "10.1.0.99", 8);

    dijkstra_pushe(g, 1, "10.1.0.99", 0);
    dijkstra_pushe(g, 1, "10.1.0.8989", 11);

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

    dijkstra_free(g);
}

TEST(DijkstraTest, MinCostTest1)
{
    DGraph *g = dijkstra_gmk(10);

    dijkstra_pushe(g, 0, "A", 0);
    dijkstra_pushe(g, 0, "C", 3);
    dijkstra_pushe(g, 0, "F", 2);

    dijkstra_pushe(g, 1, "C", 0);
    dijkstra_pushe(g, 1, "A", 3);
    dijkstra_pushe(g, 1, "F", 2);
    dijkstra_pushe(g, 1, "D", 4);
    dijkstra_pushe(g, 1, "E", 1);

    dijkstra_pushe(g, 2, "F", 0);
    dijkstra_pushe(g, 2, "A", 2);
    dijkstra_pushe(g, 2, "C", 2);
    dijkstra_pushe(g, 2, "E", 3);
    dijkstra_pushe(g, 2, "B", 6);
    dijkstra_pushe(g, 2, "G", 5);

    dijkstra_pushe(g, 3, "D", 0);
    dijkstra_pushe(g, 3, "C", 4);
    dijkstra_pushe(g, 3, "B", 1);

    dijkstra_pushe(g, 4, "E", 0);
    dijkstra_pushe(g, 4, "C", 1);
    dijkstra_pushe(g, 4, "B", 2);
    dijkstra_pushe(g, 4, "F", 3);

    dijkstra_pushe(g, 5, "G", 0);
    dijkstra_pushe(g, 5, "F", 5);
    dijkstra_pushe(g, 5, "B", 2);

    dijkstra_pushe(g, 6, "B", 0);
    dijkstra_pushe(g, 6, "D", 1);
    dijkstra_pushe(g, 6, "E", 2);
    dijkstra_pushe(g, 6, "F", 6);
    dijkstra_pushe(g, 6, "G", 2);

    EXPECT_EQ(dijkstra_min_cost(g, "A", NULL), 17);
    EXPECT_EQ(dijkstra_min_cost(g, "A", "B"), 8);

    dijkstra_free(g);
}

TEST(DijkstraTest, MinCostTest2)
{
    DGraph *g = dijkstra_gmk(10);

    dijkstra_pushe(g, 0, "192.0.0.0", 0);
    dijkstra_pushe(g, 0, "10.1.0.2", 4);
    dijkstra_pushe(g, 0, "10.10.10.1", 8);

    dijkstra_pushe(g, 1, "10.1.0.2", 0);
    dijkstra_pushe(g, 1, "192.0.0.0", 4);
    dijkstra_pushe(g, 1, "10.11.1.7", 8);
    dijkstra_pushe(g, 1, "10.10.10.1", 11);

    dijkstra_pushe(g, 2, "10.11.1.7", 0);
    dijkstra_pushe(g, 2, "192.1.1.1", 7);
    dijkstra_pushe(g, 2, "10.5.3.2", 4);
    dijkstra_pushe(g, 2, "10.2.92.6", 2);
    dijkstra_pushe(g, 2, "10.1.0.2", 8);

    dijkstra_pushe(g, 3, "10.10.10.1", 0);
    dijkstra_pushe(g, 3, "192.0.0.0", 8);
    dijkstra_pushe(g, 3, "10.1.0.2", 11);
    dijkstra_pushe(g, 3, "10.2.92.6", 7);
    dijkstra_pushe(g, 3, "192.192.1.1", 1);

    dijkstra_pushe(g, 4, "10.2.92.6", 0);
    dijkstra_pushe(g, 4, "10.11.1.7", 2);
    dijkstra_pushe(g, 4, "10.10.10.1", 7);
    dijkstra_pushe(g, 4, "192.192.1.1", 6);

    dijkstra_pushe(g, 5, "192.1.1.1", 0);
    dijkstra_pushe(g, 5, "10.1.7.7", 9);
    dijkstra_pushe(g, 5, "10.5.3.2", 14);
    dijkstra_pushe(g, 5, "10.11.1.7", 7);

    dijkstra_pushe(g, 6, "10.1.7.7", 0);
    dijkstra_pushe(g, 6, "192.1.1.1", 9);
    dijkstra_pushe(g, 6, "10.5.3.2", 10);

    dijkstra_pushe(g, 7, "10.5.3.2", 0);
    dijkstra_pushe(g, 7, "192.1.1.1", 14);
    dijkstra_pushe(g, 7, "10.1.7.7", 10);
    dijkstra_pushe(g, 7, "10.11.1.7", 4);
    dijkstra_pushe(g, 7, "192.192.1.1", 2);

    dijkstra_pushe(g, 8, "192.192.1.1", 0);
    dijkstra_pushe(g, 8, "10.5.3.2", 2);
    dijkstra_pushe(g, 8, "10.2.92.6", 6);
    dijkstra_pushe(g, 8, "10.10.10.1", 1);

    EXPECT_EQ(dijkstra_min_cost(g, "192.0.0.0", NULL), 42);
    EXPECT_EQ(dijkstra_min_cost(g, "192.0.0.0", "192.1.1.1"), 32);
    dijkstra_free(g);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}