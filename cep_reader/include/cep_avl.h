//
// Created by deivid on 10/30/23.
//

#pragma once

typedef struct CEPAVL_key
{
    signed int index;
    signed int cep;

    char city[255];
    char street[255];
    char complement[255];
    char neighbor[255];
} CEPAVL_key;

typedef struct CEPAVL_Node
{
    CEPAVL_key key;
    struct CEPAVL_Node *left;
    struct CEPAVL_Node *right;
    struct CEPAVL_Node *dad;
    int height;
} CEPAVL_Node;

/**
 * @brief Make a new node.
 * @param key The key to be inserted in the node.
 * @return A new node.
 */
CEPAVL_Node *cavl_mk(CEPAVL_key key); // cep AVL Make

/**
 * @brief Insert a new node in the AVL tree.
 * @param root The root of the AVL tree.
 * @param key The key to be inserted.
 * @return The root of the AVL tree.
 */
CEPAVL_Node *cavl_insert(CEPAVL_Node *root, CEPAVL_key key); // cep AVL Insert

/**
 * @brief Search a node sucessor in the AVL tree.
 * @param root The root of the AVL tree.
 * @param key The key to be searched.
 * @return The node if found, NULL otherwise.
 */
CEPAVL_Node *cavl_sucessor(CEPAVL_Node *node); // cep AVL Sucessor

/**
 * @brief Search a node in the AVL tree.
 * @param root The root of the AVL tree.
 * @param cep The cep to be searched.
 * @return The node if found, NULL otherwise.
 */
CEPAVL_Node *cavl_search(CEPAVL_Node *root, int cep); // cep AVL Search

/**
 * @brief Print a node.
 * @param node The node to be printed.
 */
void cavl_printNode(CEPAVL_Node *node);

/**
 * @brief Free the AVL tree.
 * @param root The root of the AVL tree.
 */
void cavl_free(CEPAVL_Node *root); // cep AVL Free