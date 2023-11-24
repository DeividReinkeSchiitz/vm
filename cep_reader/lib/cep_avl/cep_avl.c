//
// Created by deivid on 6/20/23.
//

#include "cep_avl.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

CEPAVL_Node *cavl_mk(CEPAVL_key key)
{
    CEPAVL_Node *node = (CEPAVL_Node *) malloc(sizeof(CEPAVL_Node));
    if (node == NULL)
        perror("AVL_Node Overflow");

    node->key    = key;
    node->left   = NULL;
    node->right  = NULL;
    node->dad    = NULL;
    node->height = 1;

    return node;
}

int cavl_height(CEPAVL_Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int cavl_max(int a, int b)
{
    return (a > b) ? a : b;
}

CEPAVL_Node *avl_rightRotate(CEPAVL_Node *y)
{
    CEPAVL_Node *x  = y->left;
    CEPAVL_Node *T2 = x->right;

    // Perform rotation.
    x->right        = y;
    y->dad          = x;
    y->left         = T2;
    if (T2 != NULL)
        T2->dad     = y;

    // Update heights.
    y->height       = cavl_max(cavl_height(y->left), cavl_height(y->right)) + 1;
    x->height       = cavl_max(cavl_height(x->left), cavl_height(x->right)) + 1;

    // Return new root.
    return x;
}

CEPAVL_Node *avl_leftRotate(CEPAVL_Node *x)
{
    CEPAVL_Node *y  = x->right;
    CEPAVL_Node *T2 = y->left;

    // Perform rotation.
    y->left         = x;
    x->dad          = y;

    x->right        = T2;
    if (T2 != NULL)
        T2->dad     = x;

    // Update heights.
    x->height       = cavl_max(cavl_height(x->left), cavl_height(x->right)) + 1;
    y->height       = cavl_max(cavl_height(y->left), cavl_height(y->right)) + 1;

    // Return new root.
    return y;
}

int avl_balanceFactor(CEPAVL_Node *node)
{
    if (node == NULL)
        return 0;
    else
        return cavl_height(node->left) - cavl_height(node->right);
}

CEPAVL_Node *cavl_insert(CEPAVL_Node *root, CEPAVL_key key)
{
    if (root == NULL)
    {
        return cavl_mk(key);
    }
    else if (key.cep < root->key.cep)
    {
        root->left      = cavl_insert(root->left, key);
        root->left->dad = root;
    }
    else if (key.cep > root->key.cep)
    {
        root->right      = cavl_insert(root->right, key);
        root->right->dad = root;
    }
    else
    {
        // Duplicate key. Do nothing.
    }

    // Update avl_height of the current node.
    root->height = cavl_max(cavl_height(root->left), cavl_height(root->right)) + 1;

    // Balance the current node.
    int balance  = avl_balanceFactor(root);
    if (balance > 1)
    {
        if (key.cep < root->left->key.cep)
        {
            return avl_rightRotate(root);
        }
        else
        {
            root->left      = avl_leftRotate(root->left);
            root->left->dad = root;

            return avl_rightRotate(root);
        }
    }
    else if (balance < -1)
    {
        if (key.cep > root->right->key.cep)
        {
            return avl_leftRotate(root);
        }
        else
        {
            root->right      = avl_rightRotate(root->right);
            root->right->dad = root;

            return avl_leftRotate(root);
        }
    }

    return root;
}

CEPAVL_Node *cavl_sucessor(CEPAVL_Node *node)
{
    if(node == NULL)
        return NULL;

    if (node->right != NULL)
    {
        // MINIMUM
        CEPAVL_Node *aux = node->right;
        while (aux->left != NULL)
            aux = aux->left;

        return aux;
    }

    CEPAVL_Node *dad = node->dad;
    while (dad != NULL && node == dad->right)
    {
        node = dad;
        dad  = dad->dad;
    }

    return dad;
}

CEPAVL_Node *cavl_search(CEPAVL_Node *root, int cep)
{
    if (root == NULL || root->key.cep == cep)
        return root;

    if (root->key.cep < cep)
        return cavl_search(root->right, cep);

    return cavl_search(root->left, cep);
}

void cavl_printNode(CEPAVL_Node *node)
{
    printf("CEP: %d\n", node->key.cep);
    printf("Cidade: %s\n", node->key.city);
    printf("Rua: %s\n", node->key.street);
    printf("Bairro: %s\n", node->key.neighbor);
    printf("Complemento: %s\n", node->key.complement);
    printf("\n");
}

void cavl_free(CEPAVL_Node *root)
{
    if (root == NULL)
        return;

    cavl_free(root->left);
    cavl_free(root->right);
    free(root);
}
