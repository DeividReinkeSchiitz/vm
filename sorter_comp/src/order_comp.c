/**************************************************
*
* Deivid Reinke Schutz
* Trabalho 2
* Professor(a): Fabio Henrique Viduani Martinez
*
*/

#include "stdio.h"
#include "avl.h"
#include "bst.h"
#include "heap.h"
#include <time.h>
#include <stdlib.h>

int main() {
    clock_t start, end;

    int inc = 0;
    int max = 0;
    int step = 0;

    printf("Enter the initial value: ");
    scanf("%d", &inc);

    printf("Enter the maximum value (1-2147483647): ");
    scanf("%d", &max);

    printf("Enter the step value: ");
    scanf("%d", &step);


    double abb_time_spent = 0;
    double avl_time_spent = 0;
    double heap_time_spent = 0;
    printf(" n         ABB         AVL         Heapsort\n"
           "--------------------------------------------\n");

    for (int i = inc; i <= max; i += step)
    {
        int arr1[i];
        int arr2[i];
        int arr3[i];

        // fill the array with random numbers between 0 and 2147483647
        for (int j = 0; j < i; j++) {
            int r = rand() % 2147483647;
            arr1[j] = r;
            arr2[j] = r;
            arr3[j] = r;
        }

        // Heap
        start = clock();
        heap_sort(arr3, i);
        end = clock();
        heap_time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        // ABB
        start = clock();
        bst_sort(arr1, i);
        end = clock();
        abb_time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        // AVL
        start = clock();
        avl_sort(arr2, i);
        end = clock();
        avl_time_spent = (double)(end - start) / CLOCKS_PER_SEC;


        printf("%2d %11.6f %11.6f %11.6f\n", i, abb_time_spent, avl_time_spent, heap_time_spent);
    }

    return 0;
}