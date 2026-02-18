#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "head.h"

int
main(void) {
    srand(time(NULL));

    int n;
    scanf("%d", &n);
    int option;
    scanf("%d", &option);
    long long *arr_first_sort = calloc(n, sizeof(long long));
    long long *arr_second_sort = calloc(n, sizeof(long long));

    generateArray(option, n, arr_first_sort);
    for (int i = 0; i < n; ++i) {
        arr_second_sort[i] = arr_first_sort[i];
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_first_sort[i]);
    }
    printf("\n");

    Stats data1 = {0, 0};
    Stats data2 = {0, 0};

    data1 = bubbleSort(arr_first_sort, n);
    data2 = quickSort(arr_second_sort, 0, n - 1);

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
    printf("rs1: cmp = %llu swp = %llu\n", data1.cmp, data1.swp);
    printf("rs2: cmp = %llu swp = %llu\n", data2.cmp, data2.swp);

    free(arr_first_sort);
    free(arr_second_sort);
    return 0;
}