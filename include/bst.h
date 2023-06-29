//
// Created by deivid on 6/16/23.
//

#pragma once

#include "malloc.h"

struct BST_Node
{
    int data;

    struct BST_Node *left;
    struct BST_Node *right;
    struct BST_Node *parent;
};
typedef struct BST_Node BST_Node;

/**
 * @brief Make a new node.
 * @param data The data to be inserted in the node.
 * @return return a new node.
 * @note The first node created will be the root of the binary search tree.
*/
BST_Node *bst_mk(int data);  // Binary Search Tree Make

/**
 * @brief Insert a new node in the binary search tree.
 * @param root The root of the binary search tree.
 * @return void.
*/
void bst_insert(BST_Node *root, int data);  // Binary Search Tree Insert

/**
 * @brief Save the binary search tree in the arr param in preorder.
 * @param root The root of the binary search tree.
 * @param arr The array to store the binary search tree.
 * @return The index of the array.
*/
int bst_preorder(BST_Node *root, int *arr);

/**
 * @brief Save the binary search tree in the arr param in inorder.
 * @param root The root of the binary search tree.
 * @param arr The array to store the binary search tree.
 * @return The index of the array.
*/
int bst_inorder(BST_Node *root, int *arr);  // Binary Search Tree Inorder

/**
 * @brief Save the binary search tree in the arr param in postorder.
 * @param root The root of the binary search tree.
 * @param arr The array to store the binary search tree.
 * @return The index of the array.
*/
int bst_postorder(BST_Node *root, int *arr);  // Binary Search Tree Postorder

/**
 * @brief Save the binary search tree in the arr param in level order.
 * @param root The root of the binary search tree.
 * @param arr The array to store the binary search tree.
 * @param size The size of the array.
 * @return The index of the array.
*/
int bst_lvlorder(BST_Node *root, int *arr, int size);  // Binary Search Tree Level Order

/**
 * @brief Sort an array using binary search tree.
 * @param arr The array to be sorted.
 * @param size The size of the array.
 * @return void.
*/
void bst_sort(int *arr, int size);  // Binary Search Tree Sort

/**
 * @brief Get the maximum value of the binary search tree.
 * @param root The root of the binary search tree.
 * @return The maximum value of the binary search tree.
*/
int bst_max(BST_Node *root);  // Binary Search Tree Maximum

/**
 * @brief Get the minimum value of the binary search tree.
 * @param root The root of the binary search tree.
 * @return The minimum value of the binary search tree.
*/
int bst_min(BST_Node *root);  // Binary Search Tree Minimum

/**
 * @brief Get the maximum node of the binary search tree.
 * @param root The root of the binary search tree.
 * @return The maximum node of the binary search tree.
*/
BST_Node *bst_maxNode(BST_Node *root);  // Binary Search Tree Maximum Node

/**
 * @brief Get the minimum node of the binary search tree.
 * @param root The root of the binary search tree.
 * @return The minimum node of the binary search tree.
*/
BST_Node *bst_minNode(BST_Node *root);  // Binary Search Tree Minimum Node

/**
 * @brief Find the node by data .
 * @param root The root of the binary search tree.
 * @return The node with the data.
*/
BST_Node *bst_searchNode(BST_Node *root, int data);  // Binary Search Tree Find Node

/**
 * @brief Find the node successor of the data.
 * @param root The root of the binary search tree.
 * @param data The data to find the successor.
*/
BST_Node *bst_successor(BST_Node *root, int data);  // Binary Search Tree Successor


/**
 * @brief Delete a node from the binary search tree.
 * @param root The root of the binary search tree.
 * @param data The data of the Node to be deleted.
 * @return The root of the binary search tree.
*/
BST_Node *bst_delete(BST_Node *root, int data);  // Binary Search Tree Delete

/**
 * @brief Free the binary search tree.
 * @param root The root of the binary search tree.
 * @return void.
*/
void bst_free(BST_Node *root);  // Binary Search Tree Free
