//
// Created by deivid on 11/25/22.
//

#include "d_structs.h"
#include "exceptions.h"

/**
  *           add     remove  start  end
  *  push      X                      X
  *  pop                X             X
  *  unshift   X                X
  *  shift              X       X
 */

/* **************************************************************
 * Singly Linked List
 * **************************************************************/

SLList *sllist_mk()
{
    SLList *list = (SLList *) malloc(sizeof(SLList) + 1);
    if (list == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Overflow");

    list->head     = NULL;
    list->tail     = NULL;
    list->size     = 0;
    list->str_size = 0;

    return list;
}

Node *sllist_mknd()
{
    Node *node = (Node *) malloc(sizeof(Node) + 1);
    if (node == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Node Overflow");

    node->data = "";
    node->next = NULL;

    return node;
}

int sllist_ismpty(SLList *list)
{
    return list->size == 0;
}

void sllist_clear(SLList *list)
{
    if (sllist_ismpty(list))
        return;

    Node *tmp = list->head;
    Node *next;

    while (tmp != NULL)
    {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }

    list->head     = NULL;
    list->tail     = NULL;
    list->size     = 0;
    list->str_size = 0;
}

void sllist_push(SLList *list, char *item, size_t len)
{
    if (strlen(item) == 0)
        log_msg(LOG_ERROR, "Empty item.");

    Node *node = sllist_mknd();

    if (len == 0)
        len = strlen(item);

    node->data = (char *) malloc(len + 1);
    bzero(node->data, len + 1);
    if (node->data == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Overflow");
    strncpy(node->data, item, len);

    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail       = node;
    }

    list->str_size += len;
    list->size += 1;
}

void sllist_unshift(SLList *list, char *item, size_t len)
{
    Node *node = sllist_mknd();

    if (len == 0)
        len = strlen(item);

    node->data = (char *) malloc(len + 1);
    bzero(node->data, len + 1);
    if (node->data == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Overflow");
    strncpy(node->data, item, len);

    if (list->head == NULL)
    {
        node->next = NULL;
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }

    list->str_size += len;
    list->size += 1;
}

void *sllist_pop(SLList *list)
{
    if (sllist_ismpty(list))
        return NULL;

    size_t len = strlen(list->tail->data);

    if (list->head == list->tail)
    {
        free(list->tail->data);
        free(list->tail);

        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        Node *prev = list->head;
        while (prev->next != list->tail)
            prev = prev->next;

        free(prev->next->data);
        free(prev->next);

        prev->next = NULL;
        list->tail = prev;
    }

    list->str_size -= len;
    list->size -= 1;
}

void *sllist_shift(SLList *list)
{
    if (sllist_ismpty(list))
        return NULL;

    Node *node = list->head;
    size_t len = strlen(node->data);

    if (list->head == list->tail)
    {
        free(node->data);
        free(node);

        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;

        free(node->data);
        free(node);
    }

    list->str_size -= len;
    list->size -= 1;
}

Node *sllist_peekl(SLList *list)
{
    if (sllist_ismpty(list))
        return NULL;

    return list->tail;
}

Node *sllist_peekf(SLList *list)
{
    if (sllist_ismpty(list))
        return NULL;

    return list->head;
}

size_t sllist_size(SLList *list)
{
    return list->size;
}

char *sllist_2str(SLList *list)
{
    if (sllist_ismpty(list))
        return NULL;

    size_t len  = 0;
    Node *node2 = list->head;
    while (node2 != NULL)
    {
        if (node2->data != NULL)
            len += strlen(node2->data);

        node2 = node2->next;
    }

    char *str = (char *) malloc(list->str_size + 1);
    if (str == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Overflow");
    bzero(str, list->str_size + 1);

    size_t i   = 0;
    Node *node = list->head;
    while (node != NULL)
    {
        strncpy(str + i, node->data, strlen(node->data));
        i += strlen(node->data);
        node = node->next;
    }

    return str;
}

void sllist_print(SLList *list)
{
    Node *node = NULL;

    node       = list->head;
    while (node != NULL)
    {
        char *str = node->data;
        node      = node->next;
    }
}

void sllist_free(SLList *list)
{
    Node *tmp = list->head;
    Node *next;

    while (tmp != NULL)
    {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }

    free(list);
}