//
// Created by deivid on 1/30/23.
//

extern "C"
{
#include "bst.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(bstOrder, bst_preorder)
{
    BST_Node *root = bst_mk(6);

    // print root address
    bst_insert(root, 5);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);

    int arr[10] = {};
    int i       = 0;

    i           = bst_preorder(root, arr);

    EXPECT_EQ(arr[0], 6);
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 5);
    EXPECT_EQ(arr[4], 7);
    EXPECT_EQ(arr[5], 8);

    EXPECT_EQ(i, 6);

    bst_free(root);
}

TEST(bstOrder, bst_postorder)
{
    BST_Node *root = bst_mk(6);

    // print root address
    bst_insert(root, 5);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);

    int arr[10] = {};
    int i       = 0;

    i           = bst_postorder(root, arr);

    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 5);
    EXPECT_EQ(arr[3], 8);
    EXPECT_EQ(arr[4], 7);
    EXPECT_EQ(arr[5], 6);

    EXPECT_EQ(i, 6);

    bst_free(root);
}
TEST(bstOrder, bst_inorder)
{
    BST_Node *root = bst_mk(6);

    // print root address
    bst_insert(root, 5);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);

    int arr[10] = {};
    int i       = 0;

    i           = bst_inorder(root, arr);

    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 5);
    EXPECT_EQ(arr[3], 6);
    EXPECT_EQ(arr[4], 7);
    EXPECT_EQ(arr[5], 8);

    EXPECT_EQ(i, 6);

    bst_free(root);
}

TEST(bstOrder, bst_lvlorder)
{
    BST_Node *root = bst_mk(6);

    // print root address
    bst_insert(root, 5);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);

    int arr[10] = {};
    int size    = 10;
    int i       = 0;

    i           = bst_lvlorder(root, arr, size);

    EXPECT_EQ(arr[0], 6);
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 7);
    EXPECT_EQ(arr[3], 2);
    EXPECT_EQ(arr[4], 5);
    EXPECT_EQ(arr[5], 8);
    EXPECT_EQ(i, 6);

    bst_free(root);
    EXPECT_TRUE(true);
}


TEST(bstSort, sort)
{
    int array[]    = {50, 30, 20, 40, 70, 60, 80};
    int expected[] = {20, 30, 40, 50, 60, 70, 80};
    int n          = 7;

    bst_sort(array, n);

    for (int i = 0; i < n; i++)
        EXPECT_EQ(expected[i], array[i]);
}

TEST(bstMinMax, min)
{
    BST_Node *root = bst_mk(6);

    // print root address
    bst_insert(root, 5);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);

    EXPECT_EQ(bst_min(root), 2);
    EXPECT_EQ(bst_max(root), 8);

    bst_free(root);
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}