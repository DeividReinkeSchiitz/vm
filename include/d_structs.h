//
// Created by deivid on 11/25/22.
//
#pragma once

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"

/***************************************************************
  *           add     remove  start  end
  *  push      X                      X
  *  pop                X             X
  *  unshift   X                X
  *  shift              X       X
 ***************************************************************/

/************************ Linked List *************************
 * Is a linear data structure, in which the elements are not
 * stored at contiguous memory locations. The elements in a
 * linked list are linked using pointers.
 **************************************************************/

/**
 * Singly Linked List structure
 */
typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

typedef struct SLList
{
    Node *head;
    Node *tail;

    size_t str_size;
    size_t size;
} SLList;

/**
 * @brief Create a new linked list.
 * @return return a new linked list.
*/
SLList *sllist_mk();  // Singly Linked List Make

/**
 * @brief Create a new node.
 * @return Node created.
*/
Node *sllist_mknd();  // Singly Linked List Make Node


/**
 * @brief Check if the Singly Linked List is empty.
 * @param list The list to check.
 * @return 1 if the list is empty, 0 otherwise.
 */
int sllist_ismpty(SLList *list);  // Singly Linked List Empty

/**
 * @brief Clear the Singly Linked List.
 * @param list The list to clear.
 */
void sllist_clear(SLList *list);  // Singly Linked List Clear

/**
 * @brief Push/Add an item to the Singly Linked List in the last position.
 * @param list The list to push the item.
 * @param item The item to push.
 * @param len The length of the item. If 0, the length will be calculated.
 */
void sllist_push(SLList *list, char *item, size_t len);  // Singly Linked List Push

/**
 * @brief Unshift/Add an item from the Singly Linked List in the first position.
 * @param list The list to add the item.
 * @param item The item to add.
 * @param len The length of the item.
 */
void sllist_unshift(SLList *list, char *item, size_t len);  // Singly Linked List Unshift

/**
 * @brief Pop/remove an item from the Singly Linked List in the last position.
 * @param list The list to pop the item.
 */
void *sllist_pop(SLList *list);  // Singly Linked List Pop

/**
 * @brief Pop/remove an item from the Singly Linked List in the first position.
 * @param list The list to shift the item.
 */
void *sllist_shift(SLList *list);  // Singly Linked List Shift

/**
 * @brief Peek the top item of the Singly Linked List.
 * @param list The list to peek the item.
 * @return If the list is empty, return NULL, otherwise return the item peeked.
 */
Node *sllist_peekl(SLList *list);  // Singly Linked List Peek Last

/**
 * @brief Peek the first item of the Singly Linked List.
 * @param list The list to peek the item.
 * @return If the list is empty, return NULL, otherwise return the item peeked.
 */
Node *sllist_peekf(SLList *list);  // Singly Linked List Peek First

/**
 * @brief Get the size of the Singly Linked List.
 * @param list The list to get the size.
 * @return The size of the list.
 */
size_t sllist_size(SLList *list);  // Singly Linked List Size

/**
 * @brief Concat all the items of the Singly Linked List.
 * @param list The list to concat.
 * @return Return the concatenated strings.
 * @note The returned string must be freed. Use free() to free it.
 */
char *sllist_2str(SLList *list);  // Singly Linked List to String

/**
 * @brief Print the Singly Linked List.
 */
void sllist_print(SLList *list);  // Singly Linked Print

/**
 * @brief Free the Singly Linked List.
 * @param list The list to free.
 */
void sllist_free(SLList *list);  // Singly Linked List Free

/*************************** Stack ****************************
 * Is a Linear Data Structure which follows a particular
 * order in which the operations are performed. The order
 * IS LIFO(Last In First Out).
 **************************************************************/

/**
 * Stack data structure.
 */

typedef struct Stack
{
    unsigned capacity;
    int top;
    int *array;
} Stack;

/**
 * Create a new stack.
 * @param capacity
 * @return Stack
 */
Stack *new_stack(unsigned capacity);  // Stack Make

/**
 * Check if the stack is full.
 * @param stack
 * @return int
 */
int stack_full(Stack *stack);  // Stack is Full

/**
 * Check if the stack is empty.
 * @param stack
 * @return int
 */
int stack_mpty(Stack *stack);  // Stack Empty

/**
 * Push an item to the stack.
 * @param stack
 * @param item
 * @return int
 */
int stack_push(Stack *stack, int item);  // Stack Push

/**
 * Pop an item from the stack.
 * @param stack
 * @return int
 */
int stack_pop(Stack *stack);  // Stack Pop

/**
 * Peek the top item of the stack.
 * @param stack
 * @return int
 */
int stack_peek(Stack *stack);  // Stack Peek

/**
 * Get the size of the stack.
 * @param stack
 * @return
 */
int stack_size(Stack *stack);  // Stack Size

/**
 * Free the stack.
 * @param stack
 */
void stack_free(Stack *stack);  // Stack Free

/**
 ************************* Queue *****************************
 * Is a linear structure which follows a particular order in
 * which the operations are performed. The order is First In
 * First Out (FIFO).
 **************************************************************
 */

/**
 * Queue data structure.
 */
typedef struct Queue
{
    unsigned capacity;
    size_t size;
    int front;
    int rear;
    int *array;
} Queue;

/**
 * Create a new queue.
 * @param capacity
 * @return Queue
 */
Queue *queue_mk(int capacity);  // Queue Make

/**
 * Check if the queue is full.
 * @param queue
 * @return int
 */
int queue_full(Queue *queue);  // Queue is Full

/**
 * Check if the queue is empty.
 * @param queue
 * @return int
 */
int queue_mpty(Queue *queue);  // Queue Empty

/**
 * Enqueue an item to the queue.
 * @param queue
 * @param item
 * @return int
 */
int queue_push(Queue *queue, int item);  // Queue Enqueue

/**
 * Dequeue an item to the queue.
 * @param queue
 * @param item
 * @return int
 */
int queue_pop(Queue *queue);  // DeQueue Enqueue

/**
 * Peek the first item of the stack.
 * without removing it.
 * @param queue
 * @return int
 */
int queue_peek(Queue *queue);  // Queue Peek

/**
 * Get the size of the queue.
 * @param queue
 * @return
 */
int queue_size(Queue *queue);  // Queue Size

/**
 * Free the queue.
 * @param queue
 */
void queue_free(Queue *queue);  // Queue Free