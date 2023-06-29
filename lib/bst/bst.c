//
// Created by deivid on 6/16/23.
//
#include "internal.h"

BST_Node *bst_mk(int data)
{
    BST_Node *n = (BST_Node *) malloc(sizeof(BST_Node));
    if (n == NULL)
        perror("Node Overflow");

    n->left   = NULL;
    n->right  = NULL;
    n->parent = NULL;
    n->data   = data;

    return n;
}

BST_Node *bst_searchNode(BST_Node *root, int data)
{
    BST_Node *x = root;
    BST_Node *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    return y;
}

void bst_insert(BST_Node *root, int data)
{
    BST_Node *new = bst_mk(data);

    // If the tree is empty, just add the new node.
    if (root == NULL)
    {
        root = new;
        return;
    }

    // If the tree is not empty, find the right place to add the new node.
    BST_Node *y = bst_searchNode(root, data);

    // Add the new node.
    new->parent = y;
    if (data < y->data)
        y->left = new;
    else
        y->right = new;
}

int bst_min(BST_Node *root)
{
    BST_Node *x = root;
    while (x->left != NULL)
        x = x->left;

    return x->data;
}

int bst_max(BST_Node *root)
{
    BST_Node *x = root;
    while (x->right != NULL)
        x = x->right;

    return x->data;
}

int bst_preorder(BST_Node *root, int *arr)
{
    if (root == NULL)
        return 0;

    int i  = 0;
    arr[i] = root->data;
    i++;

    i += bst_preorder(root->left, arr + i);
    i += bst_preorder(root->right, arr + i);

    return i;
}

int bst_inorder(BST_Node *root, int *arr)
{
    if (root == NULL)
        return 0;

    int i = 0;
    i += bst_inorder(root->left, arr);
    arr[i++] = root->data;
    i += bst_inorder(root->right, arr + i);

    return i;
}

int bst_postorder(BST_Node *root, int *arr)
{
    if (root == NULL)
        return 0;

    int i = 0;
    i += bst_postorder(root->left, arr);
    i += bst_postorder(root->right, arr + i);
    arr[i++] = root->data;

    return i;
}


int bst_lvlorder(BST_Node *root, int *arr, int size)
{
    if (root == NULL)
        return 0;

    // create the queue
    BST_Node *arr_add[size];

    int front       = 0;
    int rear        = 0;

    // add the root to the queue
    arr_add[rear++] = root;

    // while the queue is not empty
    BST_Node *node  = NULL;
    while (front != rear)
    {
        // get the first element of the queue
        node           = arr_add[front++];

        // add the node to the array
        arr[front - 1] = node->data;

        // if the node has a left child, add it to the queue
        if (node->left != NULL)
            arr_add[rear++] = node->left;

        // if the node has a right child, add it to the queue
        if (node->right != NULL)
            arr_add[rear++] = node->right;
    }

    return front;
}

void bst_sort(int *arr, int size)
{
    BST_Node *root = bst_mk(arr[0]);

    for (int i = 1; i < size; i++)
        bst_insert(root, arr[i]);

    bst_inorder(root, arr);

    bst_free(root);
}

void bst_free(BST_Node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        bst_free(root->left);

    if (root->right != NULL)
        bst_free(root->right);

    free(root);
}
