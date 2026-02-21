#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "head.h"

int
main(void) {
    /* RNG once for array generation. */
    srand(time(NULL));

    /* Read input:
     * n      - array size
     * option - type of generated array (see generateArray() in MassiveGenerator.c)
     */
    int n;
    scanf("%d", &n);
    int option;
    scanf("%d", &option);

    /* Allocate two identical arrays: each sorting algorithm must process
     * the same initial data to make the comparison fair.
     */
    long long *arr_first_sort = calloc(n, sizeof(long long));
    long long *arr_second_sort = calloc(n, sizeof(long long));

    /* Generate the initial array and copy it. */
    generateArray(option, n, arr_first_sort);
    for (int i = 0; i < n; ++i) {
        arr_second_sort[i] = arr_first_sort[i];
    }
    
    /* Print the initial array (for debugging / demonstration). */
    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_first_sort[i]);
    }
    printf("\n");

    /* Run both sorting algorithms and collect statistics. */
    Stats data1 = bubbleSort(arr_first_sort, n);
    Stats data2 = quickSort(arr_second_sort, 0, n - 1);

    printf("Bubble sort res:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_first_sort[i]);
    }
    printf("\n");
    printf("Quick sort res:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_second_sort[i]);
    }
    printf("\n");

    printf("data:\n");
    printf("rs1_bubble: cmp = %llu swp = %llu\n", data1.cmp, data1.swp);
    printf("rs_quick: cmp = %llu swp = %llu\n", data2.cmp, data2.swp);

    /* Free allocated memory. */
    free(arr_first_sort);
    free(arr_second_sort);
    return 0;
}