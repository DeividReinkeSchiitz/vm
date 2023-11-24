//
// Created by deivid on 6/20/23.
//

extern "C"
{
#include "cep_avl.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(cavl, cavl_mk)
{
    CEPAVL_key key;
    key.index = 1;
    key.cep = 1;
    strcpy(key.city, "city");
    strcpy(key.street, "street");
    strcpy(key.complement, "complement");

    CEPAVL_Node *node = cavl_mk(key);

    EXPECT_EQ(node->key.index, 1);
    EXPECT_EQ(node->key.cep, 1);
    EXPECT_STREQ(node->key.city, "city");
    EXPECT_STREQ(node->key.street, "street");
    EXPECT_STREQ(node->key.complement, "complement");
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    EXPECT_EQ(node->dad, nullptr);
    EXPECT_EQ(node->height, 1);

    cavl_free(node);
}

TEST(cavl, cavl_insert)
{
    CEPAVL_key key1;
    key1.index = 3343;
    key1.cep = 90;
    strcpy(key1.city, "Três Lagoas");
    strcpy(key1.street, "Doutor Oscar Guimarães");
    strcpy(key1.complement, "Jardim Novo Aeroporto");

    CEPAVL_key key2;
    key2.index = 3344;
    key2.cep = 100;
    strcpy(key2.city, "Mato Grosso do Sul");
    strcpy(key2.street, "Campo Grande");
    strcpy(key2.complement, "Centro");

    CEPAVL_key key3;
    key3.index = 3345;
    key3.cep = 70;
    strcpy(key3.city, "Minas Gerais");
    strcpy(key3.street, "Belo Horizonte");
    strcpy(key3.complement, "Eldorado");

    CEPAVL_Node *root = cavl_mk(key1);
    root = cavl_insert(root, key2);
    root = cavl_insert(root, key3);

    EXPECT_EQ(root->key.index, 3343);
    EXPECT_EQ(root->key.cep, 90);
    EXPECT_STREQ(root->key.city, "Três Lagoas");
    EXPECT_STREQ(root->key.street, "Doutor Oscar Guimarães");
    EXPECT_STREQ(root->key.complement, "Jardim Novo Aeroporto");
    EXPECT_EQ(root->dad, nullptr);

    EXPECT_EQ(root->right->key.index, 3344);
    EXPECT_EQ(root->right->key.cep, 100);
    EXPECT_STREQ(root->right->key.city, "Mato Grosso do Sul");
    EXPECT_STREQ(root->right->key.street, "Campo Grande");
    EXPECT_STREQ(root->right->key.complement, "Centro");
    EXPECT_EQ(root->right->dad, root);

    EXPECT_EQ(root->left->key.index, 3345);
    EXPECT_EQ(root->left->key.cep, 70);
    EXPECT_STREQ(root->left->key.city, "Minas Gerais");
    EXPECT_STREQ(root->left->key.street, "Belo Horizonte");
    EXPECT_STREQ(root->left->key.complement, "Eldorado");
    EXPECT_EQ(root->left->dad, root);

    cavl_free(root);
}

TEST(cavl, cavl_insert2)
{
    CEPAVL_key key1;
    key1.index = 1;
    key1.cep = 10;
    strcpy(key1.city, "city");
    strcpy(key1.street, "street");
    strcpy(key1.complement, "complement");

    CEPAVL_key key2;
    key2.index = 2;
    key2.cep = 20;
    strcpy(key2.city, "city");
    strcpy(key2.street, "street");
    strcpy(key2.complement, "complement");

    CEPAVL_key key3;
    key3.index = 3;
    key3.cep = 30;
    strcpy(key3.city, "city");
    strcpy(key3.street, "street");
    strcpy(key3.complement, "complement");

    CEPAVL_key key4;
    key4.index = 4;
    key4.cep = 40;
    strcpy(key4.city, "city");
    strcpy(key4.street, "street");
    strcpy(key4.complement, "complement");

    CEPAVL_key key5;
    key5.index = 5;
    key5.cep = 50;
    strcpy(key5.city, "city");
    strcpy(key5.street, "street");
    strcpy(key5.complement, "complement");

    CEPAVL_key key6;
    key6.index = 6;
    key6.cep = 60;
    strcpy(key6.city, "city");
    strcpy(key6.street, "street");
    strcpy(key6.complement, "complement");

    CEPAVL_key key7;
    key7.index = 7;
    key7.cep = 70;
    strcpy(key7.city, "city");
    strcpy(key7.street, "street");
    strcpy(key7.complement, "complement");

    CEPAVL_Node *root = cavl_mk(key1);
    root = cavl_insert(root, key2);
    root = cavl_insert(root, key3);
    root = cavl_insert(root, key4);
    root = cavl_insert(root, key5);
    root = cavl_insert(root, key6);
    root = cavl_insert(root, key7);

    EXPECT_EQ(root->key.cep, 40);

    // left tree
    EXPECT_EQ(root->left->key.cep, 20);
    EXPECT_EQ(root->left->dad->key.cep, 40);

    EXPECT_EQ(root->left->left->key.cep, 10);
    EXPECT_EQ(root->left->left->dad->key.cep, 20);

    EXPECT_EQ(root->left->right->key.cep, 30);
    EXPECT_EQ(root->left->right->dad->key.cep, 20);

    // right tree
    EXPECT_EQ(root->right->key.cep, 60);
    EXPECT_EQ(root->right->dad->key.cep, 40);

    EXPECT_EQ(root->right->left->key.cep, 50);
    EXPECT_EQ(root->right->left->dad->key.cep, 60);

    EXPECT_EQ(root->right->right->key.cep, 70);
    EXPECT_EQ(root->right->right->dad->key.cep, 60);

    cavl_free(root);
}

TEST(cavl, cavl_sucessor)
{
    CEPAVL_key key1;
    key1.index = 1;
    key1.cep = 10;
    strcpy(key1.city, "city");
    strcpy(key1.street, "street");
    strcpy(key1.complement, "complement");

    CEPAVL_key key2;
    key2.index = 2;
    key2.cep = 20;
    strcpy(key2.city, "city");
    strcpy(key2.street, "street");
    strcpy(key2.complement, "complement");

    CEPAVL_key key3;
    key3.index = 3;
    key3.cep = 30;
    strcpy(key3.city, "city");
    strcpy(key3.street, "street");
    strcpy(key3.complement, "complement");

    CEPAVL_key key4;
    key4.index = 4;
    key4.cep = 40;
    strcpy(key4.city, "city");
    strcpy(key4.street, "street");
    strcpy(key4.complement, "complement");

    CEPAVL_key key5;
    key5.index = 5;
    key5.cep = 50;
    strcpy(key5.city, "city");
    strcpy(key5.street, "street");
    strcpy(key5.complement, "complement");

    CEPAVL_key key6;
    key6.index = 6;
    key6.cep = 60;
    strcpy(key6.city, "city");
    strcpy(key6.street, "street");
    strcpy(key6.complement, "complement");

    CEPAVL_key key7;
    key7.index = 7;
    key7.cep = 70;
    strcpy(key7.city, "city");
    strcpy(key7.street, "street");
    strcpy(key7.complement, "complement");

    CEPAVL_Node *root = cavl_mk(key1);
    root = cavl_insert(root, key2);
    root = cavl_insert(root, key3);
    root = cavl_insert(root, key4);
    root = cavl_insert(root, key5);
    root = cavl_insert(root, key6);
    root = cavl_insert(root, key7);

    CEPAVL_Node *node = cavl_sucessor(root);
    EXPECT_EQ(node->key.cep, 50);

    node = cavl_sucessor(node);
    EXPECT_EQ(node->key.cep, 60);

    node = cavl_sucessor(node);
    EXPECT_EQ(node->key.cep, 70);
}

TEST(cavl, cavl_search)
{
    CEPAVL_key key1;
    key1.index = 3343;
    key1.cep = 90;
    strcpy(key1.city, "Três Lagoas");
    strcpy(key1.street, "Doutor Oscar Guimarães");
    strcpy(key1.complement, "Jardim Novo Aeroporto");

    CEPAVL_key key2;
    key2.index = 3344;
    key2.cep = 100;
    strcpy(key2.city, "Mato Grosso do Sul");
    strcpy(key2.street, "Campo Grande");
    strcpy(key2.complement, "Centro");

    CEPAVL_key key3;
    key3.index = 3345;
    key3.cep = 70;
    strcpy(key3.city, "Minas Gerais");
    strcpy(key3.street, "Belo Horizonte");
    strcpy(key3.complement, "Eldorado");

    CEPAVL_Node *root = cavl_mk(key1);
    root = cavl_insert(root, key2);
    root = cavl_insert(root, key3);

    CEPAVL_Node *node = cavl_search(root, 100);
    EXPECT_EQ(node->key.cep, 100);

    node = cavl_search(root, 90);
    EXPECT_EQ(node->key.cep, 90);

    node = cavl_search(root, 70);
    EXPECT_EQ(node->key.cep, 70);

    node = cavl_search(root, 50);
    EXPECT_EQ(node, nullptr);

    cavl_free(root);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}