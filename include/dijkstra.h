//
// Created by deivid on 5/1/23.
//

#pragma once

#include <limits.h>
#include <malloc.h>
#include <stdio.h>

/* **************************************************************
 * DIJKSTRA GRAPH
 * **************************************************************/

#define MAX_VERTEX_NAME 100

typedef struct Edge
{
    char vertex[MAX_VERTEX_NAME];  // ip
    int weight;                    // priority/distance
    int visited;
    struct Edge *next;
} Edge;

typedef struct DGraph
{
    int num_vertices;
    int capacity;
    Edge **adj;
} DGraph;

typedef struct HeapNode
{
    char vertex[MAX_VERTEX_NAME];
    int weight;
    int distance;
} HeapNode;

typedef struct Heap
{
    int capacity;
    int size;
    HeapNode *arr;
} Heap;

/**
 * @brief Make a new graph with capacity.
 * @param capacity The maximum capacity of the graph.
 * @return return a new graph.
*/
DGraph *dijkstra_gmk(int capacity);  // Dijkstra Graph Make

/**
 * @brief Push a new edge in the graph.
 * @param graph The Dijkstra graph created with dijkstra_gmk to push the edge.
 * @param index The index vertex of the edge.
 * @param vertex The vertex name of the edge to be pushed.
 * @param weight The weight of the edge to be pushed.
 * @return void.
 */
void dijkstra_pushe(DGraph *graph, int index, char *vertex, int weight);  // Dijkstra Push Edge

/**
 * @brief Dijkstra algorithm to find the minimum cost between two vertex.
 * If dest is NULL, the algorithm will find the minimum cost between src and all other vertex.
 * if dest or src is not in the graph, the algorithm will return UINT_MAX.
 * @param graph The graph to be searched.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return return the minimum cost.
 */
unsigned int dijkstra_min_cost(DGraph *graph, char *src, char *dest);

/**
 * @brief Free the heap.
 * @param heap The heap to be freed.
 * @return void.
 */
void dijkstra_free(DGraph *g);
