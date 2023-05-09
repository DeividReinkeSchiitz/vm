//
// Created by deivid on 5/9/23.
//

#pragma once
#include "dijkstra.h"

/* **************************************************************
 * DIJKSTRA GRAPH
 * **************************************************************/

/**
 * @brief Make a new edge.
 * @param weight The weight of the edge.
 * @param vertex The vertex name of the edge.
 * @return return a new edge.
*/
static Edge *dijkstra_emk(int weight, char *vertex);  // Dijkstra Edge Make


/* **************************************************************
 * DIJKSTRA HEAP.
 * This heap is a min heap exclusive for Dijkstra algorithm.
 * **************************************************************/

/**
 * @brief Make a new heap with capacity.
 * @param capacity The maximum capacity of the heap.
 * @return return a new heap.
 */
static Heap *dijkstra_heap_mk(int capacity);  // Dijkstra Heap Make

/**
 * @brief Get the heap parent index.
 * @param i The index of the heap.
 * @return return the parent index.
 */
static int dijkstra_heap_dad(int i);  // heap dad

/**
 * @brief Get the heap parent index.
 * @param i The index of the heap.
 * @return return the left son index.
 */
static int dijkstra_heap_lson(int i);  // heap left son

/**
 * @brief Get the heap parent index.
 * @param i The index of the heap.
 * @return return the right son index.
 */
static int dijkstra_heap_rson(int i);  // heap right son

/**
 * @brief Swap two heap nodes.
 * @param i The first node.
 * @param j The second node.
 * @return void.
 */
static void dijkstra_heap_swap(HeapNode *i, HeapNode *j);

/**
 * @brief Heapify down the heap.
 * @param heap The heap to be heapified.
 * @param i The index of the heap.
 * @return void.
 */
static void dijkstra_heapify_down(Heap *heap, int i);

/**
 * @brief Heapify up the heap.
 * @param heap The heap to be heapified.
 * @param i The index of the heap.
 * @return void.
 */
static void dijkstra_heapify_up(Heap *heap, int i);

/**
 * @brief Insert a new node in the heap.
 * @param heap The heap to be inserted.
 * @param vertex The vertex name of the node to be inserted.
 * @param weight The weight of the node to be inserted.
 * @return void.
 */
static void dijkstra_heap_insert(Heap *heap, char *vertex, int weight);

/**
 * @brief Extract the minimum node of the heap.
 * @param heap The heap to be extracted.
 * @return return the minimum node.
 */
static HeapNode dijkstra_heap_extract_min(Heap *heap);

/**
 * @brief Decrease the key of a node in the heap.
 * @param heap The heap to be decreased.
 * @param i The index of the node to be decreased.
 * @param key The new key of the node to be decreased.
 * @param distance The new distance of the node to be decreased.
 * @return void.
 */
static void dijkstra_heap_decrease_key(Heap *g, int i, int key, int distance);

/**
 * @brief Free the heap.
 * @param heap The heap to be freed.
 * @return void.
 */
static void dijkstra_heap_free(Heap *heap);

static int node_indexG(DGraph *graph, char *vertex);
static int node_indexH(Heap *heap, char *vertex);