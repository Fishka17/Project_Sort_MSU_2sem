#include <stdlib.h>
#include "head.h"

/* Swap two elements in-place. */
static void swap(long long *arr, int i, int j) {
    long long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
 * Absolute value for long long without overflow on LLONG_MIN.
 *
 * For LLONG_MIN, -x overflows, so we compute it via a safe transformation.
 */
static unsigned long long myAbsll(long long x) {
    return (x < 0) ? (unsigned long long)(-(x + 1)) + 1ULL : (unsigned long long)x;
}

Stats bubbleSort(long long *a, int n) {
    Stats data = {0, 0};

    /*
     * Bubble sort for order by non-increasing absolute value:
     *   |a[0]| >= |a[1]| >= ... >= |a[n-1]|.
     */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            /* One comparison of adjacent elements (by absolute value). */
            data.cmp++;

            /* If the left element is smaller, swap to move bigger |.| left. */
            if (myAbsll(a[j]) < myAbsll(a[j + 1])) {
                swap(a, j, j + 1);
                data.swp++;
            }
        }
    }
    return data;
}