//
// Created by deivid on 4/22/23.
//

#include "heap.h"
#include <limits.h>
#include <stdio.h>

int heap_dad(int i)
{
    return (i - 1) / 2;
}

int heap_lson(int i)  // heap left son
{
    return 2 * (i + 1) - 1;
}

int heap_rson(int i)  // heap right son
{
    return 2 * (i + 1);
}

void change(int *i, int *j)
{
    int save = *j;
    *j       = *i;
    *i       = save;
}

void heapify(int *S, int n, int i)
{
    int l       = heap_lson(i);
    int r       = heap_rson(i);
    int biggest = i;

    //  if the left children is bigger then the root
    if (l < n && S[l] > S[i])
        biggest = l;

    //  if the right children is bigger then the root
    if (r < n && S[r] > S[biggest])
        biggest = r;

    if (biggest == i)
        return;

    // Swap the root with the biggest element
    change(&S[i], &S[biggest]);

    // make it again recursively
    heapify(S, n, biggest);
}

void heap_up(int *S, int n, int i)
{
    while (S[heap_dad(i)] < S[i])
    {
        change(&S[i], &S[heap_dad(i)]);
        i = heap_dad(i);
    }
}

void heap_make(int *S, int n)
{
    // Index of the last non-leaf node
    int i = n / 2 - 1;

    for (; i >= 0; i--)
        heapify(S, n, i);
}

int heap_maxv(int *S)
{
    return S[0];
}

int heap_pop(int *S, int *n)
{
    int biggest;
    if (*n <= 0)
        perror("Heap is empty.");

    biggest = S[0];
    S[0]    = S[*n - 1];
    *n      = *n - 1;
    heapify(S, *n, 0);
    return biggest;
}

void heap_promote(int *S, int n, int i, int p)
{
    if (p < S[i])
        perror("New priority is smaller than the current value");
    else
    {
        S[i] = p;
        heap_up(S, n, i);
    }
}

void heap_insert(int *S, int *n, int p)
{
    S[*n] = p;
    *n    = *n + 1;
    heap_up(S, *n, *n - 1);
}

void heap_sort(int *S, int n)
{
    int i;
    heap_make(S, n);
    for (i = n - 1; i > 0; i--)
    {
        change(&S[0], &S[i]);
        n--;
        heapify(S, n, 0);
    }
}