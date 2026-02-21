#include "head.h"
#include "../utils.h"

Stats 
bubbleSort(long long *a, int n) {
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
            if (abs_ll(a[j]) < abs_ll(a[j + 1])) {
                swap_ll(a, (size_t)j, (size_t)j + 1);
                data.swp++;
            }
        }
    }
    return data;
}