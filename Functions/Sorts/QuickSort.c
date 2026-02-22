#include "head.h"
#include "../utils.h"

static int 
partition(long long *arr, int low, int high, Stats *data) {
    /*
     * Partition step:
     *   - pivot is the first element
     *   - after partition, elements with |x| >= |pivot| tend to be on the left
     *   - elements with |x| <  |pivot| tend to be on the right
     */
    long long p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        /* Move "i" right while elements already belong to the left part.
         * Condition for left part: |arr[i]| >= |pivot|.
         */
        while (i <= high - 1) {
            data->cmp++;
            if (abs_ll(arr[i]) >= abs_ll(p)) {
                i++;
            } else {
                break;
            }
        }

        /* Move "j" left while elements already belong to the right part.
         * Condition for right part: |arr[j]| < |pivot|.
         */
        while (j >= low + 1) {
            data->cmp++;
            if (abs_ll(arr[j]) <  abs_ll(p)) {
                j--;
            } else {
                break;
            }
        }

        /* Swap the misplaced pair. */
        if (i < j) {
            swap_ll(arr, (size_t)i, (size_t)j);
            data->swp++;
        }
    }

    /* Put the pivot into its final position (index j). */
    if (j != low) {
        swap_ll(arr, (size_t)low, (size_t)j);
        data->swp++;
    }

    return j;
}

static void 
quickSort_impl(long long *a, int low, int high, Stats *data) {
    if (low < high) {
        int pi = partition(a, low, high, data);

        /* Recursively sort the two partitions. */
        quickSort_impl(a, low, pi - 1, data);
        quickSort_impl(a, pi + 1, high, data);
    }
}

Stats 
quickSort(long long *a, int low, int high) {
    Stats data = {0, 0};

    /* Stores statistics. */
    quickSort_impl(a, low, high, &data);

    return data;
}