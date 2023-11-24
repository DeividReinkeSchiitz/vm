//
// Created by deivid on 6/20/23.
//

#pragma once
#include "cep_avl.h"

/**
 * @brief Get the maximum between two numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The maximum between two numbers.
 */
int cavl_max(int a, int b); // cep avl max

/**
 * @brief Get the height of the node.
 * @param node The node to get the height.
 * @return The height of the node.
 */
int cavl_height(CEPAVL_Node *node); // cep avl height

/**
 * @brief Left rotate the subtree.
 * @param x The root of the subtree.
 * @return The new root of the subtree.
 */
CEPAVL_Node *avl_leftRotate(CEPAVL_Node *x); // cep avl left rotate

/**
 * @brief Right rotate the subtree.
 * @param y The root of the subtree.
 * @return The new root of the subtree.
 */
CEPAVL_Node *avl_rightRotate(CEPAVL_Node *y); // cep avl right rotate

/**
 * @brief Get the balance factor of the node.
 * @param node The node to get the balance factor.
 * @return The balance factor of the node.
 */
int avl_balanceFactor(CEPAVL_Node *node); // cep avl balance factor