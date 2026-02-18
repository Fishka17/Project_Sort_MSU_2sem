#include <stdlib.h>
#include "head.h"

static void swap(long long *arr, int i, int j) {
    long long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

static unsigned long long myAbsll(long long x) {
    return (x < 0) ? (unsigned long long)(-(x + 1)) + 1ULL : (unsigned long long)x;
}

Stats bubbleSort(long long *a, int n) {
    Stats data = {0, 0};
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            data.cmp++;
            if (myAbsll(a[j]) < myAbsll(a[j + 1])) {
                swap(a, j, j + 1);
                data.swp++;
            }
        }
    }
    return data;
}