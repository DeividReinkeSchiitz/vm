//
// Created by deivid on 6/20/23.
//

#pragma once

struct AVL_Node
{
    int key;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
};

/**
 * @brief Sorts an array using AVL tree.
 * @param arr Array to be sorted.
 * @param size Size of the array.
 */
void avl_sort(int *arr, int size);

/**
 * @brief Insert a new node in the AVL tree.
 * @param root The root of the AVL tree.
 * @param key The key to be inserted.
 * @return The root of the AVL tree.
 */
struct AVL_Node *avl_insert(struct AVL_Node *root, int key);

/**
 * @brief Inorder traversal of the AVL tree.
 * @param root The root of the AVL tree.
 * @param arr The array to store the AVL tree.
 * @param i The index of the array.
 */
void avl_inorder(struct AVL_Node *root, int *arr, int *i);

/**
 * @brief Get the balance factor of the node.
 * @param node The node to get the balance factor.
 * @return The balance factor of the node.
 */
int avl_balanceFactor(struct AVL_Node *node);

/**
 * @brief Left rotate the subtree.
 * @param x The root of the subtree.
 * @return The new root of the subtree.
 */
struct AVL_Node *avl_leftRotate(struct AVL_Node *x);

/**
 * @brief Right rotate the subtree.
 * @param y The root of the subtree.
 * @return The new root of the subtree.
 */
struct AVL_Node *avl_rightRotate(struct AVL_Node *y);

/**
 * @brief Get the maximum between two numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The maximum between two numbers.
 */
int cavl_max(int a, int b);

/**
 * @brief Get the height of the node.
 * @param node The node to get the height.
 * @return The height of the node.
 */
int avl_height(struct AVL_Node *node);

/**
 * @brief Make a new node.
 * @param key The key to be inserted in the node.
 * @return A new node.
 */
struct AVL_Node *avl_mk(int key);

/**
 * @brief Free the AVL tree.
 * @param root The root of the AVL tree.
 */
void avl_free(struct AVL_Node *root);