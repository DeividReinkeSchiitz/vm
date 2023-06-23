//
// Created by deivid on 4/23/23.
//

#include "hashTable.h"
#include <limits.h>
#include <stdio.h>

#define MAX_HASH_SIZE 100

/* **************************************************************
 * STATIC HASH TABLE
 * **************************************************************/

int hashT_hash(int key, int size)
{
    return key % size;
}

int hashT_insert(int size, int S[MAX_HASH_SIZE], int value)
{
    int i = 0;
    int j = 0;

    do
    {
        // get the hash index
        j = hashT_hash(value, i);

        // if the position is not empty
        if (S[j] != INT_MIN)
        {
            i++;
            continue;
        }

        S[j] = value;
        return j;
    } while (i != size);

    return -1;
}

int hashT_search(int size, int S[MAX_HASH_SIZE], int value)
{
    int i = 0;
    int j = 0;

    do
    {
        // get the hash index
        j = hashT_hash(value, i);

        // if the position is not empty
        if (S[j] == value)
            return j;

        i++;
    } while (i != size);


    return -1;
}
