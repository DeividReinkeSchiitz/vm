//
// Created by deivid on 5/1/23.
//

#ifndef VM_DIJKSTRA_H
#define VM_DIJKSTRA_H

//
// Created by deivid on 4/23/23.
//

#include <limits.h>
#include <malloc.h>
#include <stdio.h>

/* **************************************************************
 * DYNAMIC GRAPH
 * **************************************************************/

#define MAX_EDGE_VALUE 100

typedef struct Edge
{
    char vertex[MAX_EDGE_VALUE];  // ip
    int weight;                   // priority/distance
    int visited;
    int distance;
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
    char vertex[MAX_EDGE_VALUE];
    int weight;
} HeapNode;

typedef struct Heap
{
    int capacity;
    int size;
    HeapNode *arr;
} Heap;

Edge *edge_mk(int weight, char *vertex);

DGraph *dgraph_mk(int capacity);
void dgraph_pushedge(DGraph *g, int src, char *vertex, int weight);

HeapNode createHeapNode(char *vertex, int weight);
Heap *createHeap(int capacity);

static int heap_lson(int i);  // heap left son
static int heap_rson(int i);  // heap right son

static void heap_swap(HeapNode *i, HeapNode *j);

static void heapify_down(Heap *heap, int i);
static void heapify_up(Heap *heap, int i);

void heap_insert(Heap *heap, char *vertex, int weight);
HeapNode heap_extractmin(Heap *heap);

void heap_decrease_key(Heap *g, int i, int key);

void dgraph_delete(DGraph *g);

unsigned int minCost(DGraph *graph);
void freeEdge(Edge *e);


int node_indexG(DGraph *graph, char *vertex);
int node_indexH(Heap *heap, char *vertex);
#endif  //VM_DIJKSTRA_H
