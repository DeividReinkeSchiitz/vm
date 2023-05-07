//
// Created by deivid on 4/23/23.
//

#include "dijkstra.h"
#include "string.h"
/* **************************************************************
 * DYNAMIC GRAPH
 * **************************************************************/

Edge *edge_mk(int weight, char *vertex)
{
    Edge *new_edge = malloc(sizeof(Edge));
    if (new_edge == NULL)
        perror("Edge Overflow");

    strcpy(new_edge->vertex, vertex);
    new_edge->weight = weight;
    new_edge->next   = NULL;

    return new_edge;
}

void dgraph_pushedge(DGraph *g, int src, char *vertex, int weight)
{
    if (src >= g->capacity)
        perror("Dynamic Graph Overflow");

    Edge *new_edge = edge_mk(weight, vertex);

    if (g->adj[src] == NULL)
    {
        g->adj[src] = new_edge;
        g->num_vertices++;
        return;
    }

    Edge *last = g->adj[src];
    while (last->next != NULL)
        last = last->next;

    last->next = new_edge;
}

DGraph *dgraph_mk(int capacity)
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

HeapNode createHeapNode(char *vertex, int weight)
{
    HeapNode node;
    strcpy(node.vertex, vertex);
    node.weight = weight;
    return node;
}

Heap *createHeap(int capacity)
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

static int heap_dad(int i)
{
    return (i - 1) / 2;
}

static int heap_lson(int i)  // heap left son
{
    return 2 * (i + 1) - 1;
}

static int heap_rson(int i)  // heap right son
{
    return 2 * (i + 1);
}

static void heap_swap(HeapNode *i, HeapNode *j)
{
    HeapNode save = *j;
    *j            = *i;
    *i            = save;
}

static void heapify_down(Heap *heap, int i)
{
    int left     = heap_lson(i);
    int right    = heap_rson(i);
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
        heap_swap(&heap->arr[i], &heap->arr[smallest]);
        heapify_down(heap, smallest);
    }
}

static void heapify_up(Heap *heap, int i)
{
    while (i > 0 && heap->arr[heap_dad(i)].weight > heap->arr[i].weight)
    {
        heap_swap(&heap->arr[heap_dad(i)], &heap->arr[i]);
        i = heap_dad(i);
    }
}

void heap_insert(Heap *heap, char *vertex, int weight)
{
    if (heap->size == heap->capacity)
    {
        perror("Heap Overflow");
    }

    heap->size++;
    int i = heap->size - 1;
    strcpy(heap->arr[i].vertex, vertex);
    heap->arr[i].weight = weight;

    heapify_up(heap, i);
}

HeapNode heap_extractmin(Heap *heap)
{
    if (heap->size == 0)
        perror("Heap Underflow");

    if (heap->size > 0)
    {
        HeapNode min = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapify_down(heap, 0);

        return min;
    }
}

void heap_decrease_key(Heap *g, int i, int key)
{
    if (key > g->arr[i].weight)
    {
        perror("New key is greater than current key");
    }

    g->arr[i].weight = key;

    heapify_up(g, i);
}

//convert a vertex name to its corresponding index in the adjacency list
int node_indexG(DGraph *graph, char *vertex)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcmp(graph->adj[i]->vertex, vertex) == 0)
            return i;
    }
    return -1;
}

int node_indexH(Heap *heap, char *vertex)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (strcmp(heap->arr[i].vertex, vertex) == 0)
            return i;
    }
    return -1;
}


unsigned int minCost(DGraph *graph)
{
    int cost = 0;

    //  Initialize the distances to infinity and the root to zero
    for (int i = 0; i < graph->num_vertices; i++)
        graph->adj[i]->weight = INT_MAX;

    graph->adj[0]->weight  = 0;
    graph->adj[0]->visited = 1;

    //  Initialize the heap
    Heap *heap             = createHeap(graph->num_vertices);

    for (int i = 0; i < graph->num_vertices; i++)
        heap_insert(heap, graph->adj[i]->vertex, graph->adj[i]->weight);

    while (heap->size > 0)
    {
        HeapNode min                         = heap_extractmin(heap);
        int cur_graph_index                  = node_indexG(graph, min.vertex);
        graph->adj[cur_graph_index]->visited = 1;

        cost += min.weight;

        Edge *tmp = graph->adj[cur_graph_index]->next;
        while (tmp != NULL)
        {
            int v = node_indexG(graph, tmp->vertex);

            if (graph->adj[v]->visited == 0 && tmp->weight + min.weight < graph->adj[v]->weight)
            {
                graph->adj[v]->weight = tmp->weight + min.weight;
                heap_decrease_key(heap, node_indexH(heap, tmp->vertex), tmp->weight);
            }

            tmp = tmp->next;
        }
    }

    return cost;
}
void dgraph_delete(DGraph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
        freeEdge(g->adj[i]);

    free(g);
}

void freeEdge(Edge *e)
{
    // free the edge
    Edge *tmp = e;
    while (tmp != NULL)
    {
        Edge *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}