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

    new->parent = y;
    if (data < y->data)
        y->left = new;
    else
        y->right = new;
}

void bst_inorder(BST_Node *root, int *arr, int *i)
{
    if (root == NULL)
        return;

    bst_inorder(root->left, arr, i);
    arr[*i] = root->data;
    (*i)++;
    bst_inorder(root->right, arr, i);
}

void bst_sort(int *arr, int size)
{
    BST_Node *root = bst_mk(arr[0]);

    for (int i = 1; i < size; i++)
        bst_insert(root, arr[i]);

    int i = 0;
    bst_inorder(root, arr, &i);

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
