#pragma once

//
// Created by deivid on 4/22/23.
//

#include "heap.h"
#include <limits.h>
#include <stdio.h>

/* **************************************************************
 * STATIC -HEAP
 * **************************************************************/

/**
 * @brief Return the Father
 * @return father index
 */
int heap_dad(int i);

/**
 * @brief Return the index of left son
 * @return left son index from i index
 */
int heap_lson(int i);  // heap left son

/**
 * @brief Return the index of the right son.
 * @param i The father index.
 * @return right son index from i index
 */
int heap_rson(int i);  // heap right son


/**
 * @brief Change the values from pointer i to j and j to i.
 * @param i first pointer.
 * @param j second pointer.
 * @return void.
 */
void change(int *i, int *j);

/**
 * @brief recursively compare between a father and his 2 sons which is the biggest.
 * put the biggest as a father.
 * @param S The heap array.
 * @param n The size of the S array.
 * @param i The root index.
 * @return void.
 */
void heapify(int S[], int n, int i);

/**
 * @brief Change value between father and soon.
 * recursively until the father be small the the current index.
 * @param S[] The heap array.
 * @param n The size of the S array.
 * @param i The current index.
 * @return void.
 */
void heap_up(int S[], int n, int i);

/**
 * @brief Create the max-heap.
 * @param S[] The heap array.
 * @param n The size of the S array.
 * @return void.
 */
void heap_make(int *S, int n);

/**
 * @brief Get the biggest value from the max heap.
 * @param S The heap array.
 * @return max max value from the max heap.
 */
int heap_maxv(int *S);

/**
 * @brief Remove the element the last element from the max heap.
 * @param *S The heap array.
 * @param n The size pointer of the S array.
 * @return The max value from the max heap.
 */
int heap_pop(int *S, int *n);

/**
 * @brief Increase the priority from a element in the max heap.
 * @param *S The heap array.
 * @param n The size of the S array.
 * @param i index of the cell that will be changed.
 * @param p new priority.
 * @return The max value from the max heap.
 */
void heap_promote(int *S, int n, int i, int p);

/**
 * @brief Insert a new element in the max heap.
 * @param *S The heap array.
 * @param n The size of the S array.
 * @param p new element.
 * @return The max value from the max heap.
 */
void heap_insert(int *S, int *n, int p);

/**
 * @brief Sort the max heap array in a ascending order.
 * @param *S The heap array.
 * @param n The size of the S array.
 * @return void
 */
void heap_sort(int *S, int n);