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
    // long long *arr_second_sort = calloc(n, sizeof(long long));

    generateArray(option, n, arr_first_sort);
    // for (int i = 0; i < n; ++i) {
    //     arr_second_sort[i] = arr_first_sort[i];
    // }
    
    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_first_sort[i]);
    }
    printf("\n");

    bubbleSort(arr_first_sort, n);

    for (int i = 0; i < n; ++i) {
        printf("%lld ", arr_first_sort[i]);
    }
    printf("\n");

    free(arr_first_sort);
    // free(arr_second_sort);
    return 0;
}