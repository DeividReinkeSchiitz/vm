//
// Created by deivid on 4/23/23.
//

#include "dijkstra.h"
#include "internal.h"
#include "string.h"

DGraph *dijkstra_gmk(int capacity)
{
    DGraph *new_graph = malloc(sizeof(DGraph));
    if (new_graph == NULL)
        perror("Dynamic Graph Overflow");

    new_graph->adj = malloc(sizeof(Edge *) * capacity);
    if (new_graph->adj == NULL)
        perror("Dynamic Graph Overflow");

    for (int i = 0; i < capacity; i++)
        new_graph->adj[i] = NULL;

    new_graph->capacity     = capacity;
    new_graph->num_vertices = 0;

    return new_graph;
}

static Edge *dijkstra_emk(int weight, char *vertex)
{
    Edge *new_edge = malloc(sizeof(Edge));
    if (new_edge == NULL)
        perror("Edge Overflow");

    strcpy(new_edge->vertex, vertex);
    new_edge->weight = weight;
    new_edge->next   = NULL;

    return new_edge;
}

void dijkstra_pushe(DGraph *graph, int index, char *vertex, int weight)
{
    if (index >= graph->capacity)
        perror("Dynamic Graph Overflow");

    Edge *new_edge = dijkstra_emk(weight, vertex);

    if (graph->adj[index] == NULL)
    {
        graph->adj[index] = new_edge;
        graph->num_vertices++;
        return;
    }

    Edge *last = graph->adj[index];
    while (last->next != NULL)
        last = last->next;

    last->next = new_edge;
}

static Heap *dijkstra_heap_mk(int capacity)
{
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    if (heap == NULL)
        perror("Heap Overflow");

    heap->size     = 0;
    heap->capacity = capacity;
    heap->arr      = (HeapNode *) malloc(capacity * sizeof(HeapNode));
    if (heap->arr == NULL)
        perror("Heap Overflow");

    return heap;
}

static int dijkstra_heap_dad(int i)
{
    return (i - 1) / 2;
}

static int dijkstra_heap_lson(int i)  // heap left son
{
    return 2 * (i + 1) - 1;
}

static int dijkstra_heap_rson(int i)  // heap right son
{
    return 2 * (i + 1);
}

static void dijkstra_heap_swap(HeapNode *i, HeapNode *j)
{
    HeapNode save = *j;
    *j            = *i;
    *i            = save;
}

static void dijkstra_heapify_down(Heap *heap, int i)
{
    int left     = dijkstra_heap_lson(i);
    int right    = dijkstra_heap_rson(i);
    int smallest = i;

    if (left < heap->size && heap->arr[left].weight < heap->arr[smallest].weight)
    {
        smallest = left;
    }

    if (right < heap->size && heap->arr[right].weight < heap->arr[smallest].weight)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        dijkstra_heap_swap(&heap->arr[i], &heap->arr[smallest]);
        dijkstra_heapify_down(heap, smallest);
    }
}

static void dijkstra_heapify_up(Heap *heap, int i)
{
    while (i > 0 && heap->arr[dijkstra_heap_dad(i)].weight > heap->arr[i].weight)
    {
        dijkstra_heap_swap(&heap->arr[dijkstra_heap_dad(i)], &heap->arr[i]);
        i = dijkstra_heap_dad(i);
    }
}

static void dijkstra_heap_insert(Heap *heap, char *vertex, int weight)
{
    if (heap->size == heap->capacity)
    {
        perror("Heap Overflow");
    }

    heap->size++;
    int i = heap->size - 1;
    strcpy(heap->arr[i].vertex, vertex);
    heap->arr[i].weight   = weight;
    heap->arr[i].distance = 0;

    dijkstra_heapify_up(heap, i);
}

static HeapNode dijkstra_heap_extract_min(Heap *heap)
{
    if (heap->size == 0)
        perror("Heap Underflow");

    if (heap->size > 0)
    {
        HeapNode min = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        dijkstra_heapify_down(heap, 0);

        return min;
    }

    return heap->arr[0];
}

static void dijkstra_heap_decrease_key(Heap *g, int i, int key, int distance)
{
    if (key > g->arr[i].weight)
        perror("New key is greater than current key");

    g->arr[i].weight   = key;
    g->arr[i].distance = distance;

    dijkstra_heapify_up(g, i);
}

//convert a vertex name to its corresponding index in the adjacency list
// TODO: Implement a better node_indexG
static int node_indexG(DGraph *graph, char *vertex)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcmp(graph->adj[i]->vertex, vertex) == 0)
            return i;
    }
    return -1;
}

// TODO: Reduce node_indexH time complexity
static int node_indexH(Heap *heap, char *vertex)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (strcmp(heap->arr[i].vertex, vertex) == 0)
            return i;
    }
    return -1;
}

unsigned int dijkstra_min_cost(DGraph *graph, char *src, char *dest)
{
    int cost       = 0;
    int src_index  = -1;
    int dest_index = -1;

    //  Initialize the distances to infinity and the root to zero
    for (int i = 0; i < graph->num_vertices; i++)
    {
        graph->adj[i]->weight  = INT_MAX;
        graph->adj[i]->visited = 0;

        if (strcmp(graph->adj[i]->vertex, src) == 0)
            src_index = i;

        if (dest != NULL && strcmp(graph->adj[i]->vertex, dest) == 0)
            dest_index = i;
    }

    // Check if the source vertex exists
    if (src_index == -1)
    {
        perror("Source vertex not found");
        return UINT_MAX;
    }

    //    // Check if the destination vertex exists
    if (dest != NULL && dest_index == -1)
    {
        perror("Destination vertex not found");
        return UINT_MAX;
    }

    // Set the root distance to zero
    graph->adj[src_index]->weight  = 0;
    graph->adj[src_index]->visited = 1;

    //  Initialize the heap
    Heap *heap                     = dijkstra_heap_mk(graph->num_vertices);

    for (int i = 0; i < graph->num_vertices; i++)
        dijkstra_heap_insert(heap, graph->adj[i]->vertex, graph->adj[i]->weight);

    while (heap->size > 0)
    {
        // Extract the minimum distance vertex from the heap
        HeapNode min                         = dijkstra_heap_extract_min(heap);
        // Get the index of the vertex in the adjacency list / graph
        int cur_graph_index                  = node_indexG(graph, min.vertex);
        // Mark the vertex as visited
        graph->adj[cur_graph_index]->visited = 1;

        // Update the cost
        cost                                 = cost + min.distance;

        // Update the distances of the adjacent vertices
        Edge *tmp                            = graph->adj[cur_graph_index]->next;
        while (tmp != NULL)
        {
            // Get the index of the adjacent vertex in the adjacency list / graph
            int v = node_indexG(graph, tmp->vertex);

            if (graph->adj[v]->visited == 0 && tmp->weight + min.weight < graph->adj[v]->weight)
            {
                graph->adj[v]->weight = tmp->weight + min.weight;
                dijkstra_heap_decrease_key(heap, node_indexH(heap, tmp->vertex), tmp->weight + min.weight, tmp->weight);
            }

            tmp = tmp->next;
        }

        if (dest != NULL && strcmp(min.vertex, dest) == 0)
            break;
    }

    dijkstra_heap_free(heap);

    return cost;
}
void dijkstra_free(DGraph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        Edge *tmp = g->adj[i];
        while (tmp != NULL)
        {
            Edge *next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }

    free(g);
}

void dijkstra_heap_free(Heap *heap)
{
    free(heap->arr);
    free(heap);
}
