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
    long long *a = calloc(n, sizeof(long long));

    generateArray(option, n, a);
    
    for (int i = 0; i < n; ++i) {
        printf("%lld ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}