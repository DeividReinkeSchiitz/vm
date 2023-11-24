//
// Created by deivid on 6/20/23.
//
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct AVL_Node
{
    int key;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
};

struct AVL_Node *avl_mk(int key)
{
    struct AVL_Node *node = (struct AVL_Node *) malloc(sizeof(struct AVL_Node));
    if (node == NULL)
        perror("AVL_Node Overflow");

    node->key    = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;

    return node;
}

int avl_height(struct AVL_Node *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int cavl_max(int a, int b)
{
    return (a > b) ? a : b;
}

struct AVL_Node *avl_rightRotate(struct AVL_Node *y)
{
    struct AVL_Node *x  = y->left;
    struct AVL_Node *T2 = x->right;

    // Perform rotation.
    x->right            = y;
    y->left             = T2;

    // Update heights.
    y->height           = cavl_max(avl_height(y->left), avl_height(y->right)) + 1;
    x->height           = cavl_max(avl_height(x->left), avl_height(x->right)) + 1;

    // Return new root.
    return x;
}

struct AVL_Node *avl_leftRotate(struct AVL_Node *x)
{
    struct AVL_Node *y  = x->right;
    struct AVL_Node *T2 = y->left;

    // Perform rotation.
    y->left             = x;
    x->right            = T2;

    // Update heights.
    x->height           = cavl_max(avl_height(x->left), avl_height(x->right)) + 1;
    y->height           = cavl_max(avl_height(y->left), avl_height(y->right)) + 1;

    // Return new root.
    return y;
}

int avl_balanceFactor(struct AVL_Node *node)
{
    if (node == NULL)
        return 0;
    else
        return avl_height(node->left) - avl_height(node->right);
}

struct AVL_Node *avl_insert(struct AVL_Node *root, int key)
{
    if (root == NULL)
    {
        return avl_mk(key);
    }
    else if (key < root->key)
    {
        root->left = avl_insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = avl_insert(root->right, key);
    }
    else
    {
        // Duplicate key. Do nothing.
    }

    // Update avl_height of the current node.
    root->height = cavl_max(avl_height(root->left), avl_height(root->right)) + 1;

    // Balance the current node.
    int balance  = avl_balanceFactor(root);
    if (balance > 1)
    {
        if (key < root->left->key)
        {
            return avl_rightRotate(root);
        }
        else
        {
            root->left = avl_leftRotate(root->left);
            return avl_rightRotate(root);
        }
    }
    else if (balance < -1)
    {
        if (key > root->right->key)
        {
            return avl_leftRotate(root);
        }
        else
        {
            root->right = avl_rightRotate(root->right);
            return avl_leftRotate(root);
        }
    }

    return root;
}

void avl_inorder(struct AVL_Node *root, int *arr, int *i)
{
    if (root == NULL)
        return;

    avl_inorder(root->left, arr, i);
    arr[*i] = root->key;
    (*i)++;
    avl_inorder(root->right, arr, i);
}

void avl_free(struct AVL_Node *root)
{
    if (root == NULL)
        return;

    avl_free(root->left);
    avl_free(root->right);
    free(root);
}

void avl_sort(int *arr, int size)
{
    struct AVL_Node *root = NULL;
    for (int i = 0; i < size; i++)
        root = avl_insert(root, arr[i]);

    int i = 0;
    avl_inorder(root, arr, &i);

    avl_free(root);
}
