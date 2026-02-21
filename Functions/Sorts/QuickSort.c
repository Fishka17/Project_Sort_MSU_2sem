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

static int partition(long long *arr, int low, int high, Stats *data) {
    /*
     * Partition step:
     *   - pivot is the first element
     *   - after partition, elements with |x| >= |pivot| tend to be on the left
     *   - elements with |x| <  |pivot| tend to be on the right
     *
     * Sorting order: non-increasing absolute value.
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
            if (myAbsll(arr[i]) >= myAbsll(p)) {
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
            if (myAbsll(arr[j]) <  myAbsll(p)) {
                j--;
            } else {
                break;
            }
        }

        /* Swap the misplaced pair. */
        if (i < j) {
            swap(arr, i, j);
            data->swp++;
        }
    }

    /* Put the pivot into its final position (index j). */
    if (j != low) {
        swap(arr, low, j);
        data->swp++;
    }

    return j;
}

static void quickSort_impl(long long *a, int low, int high, Stats *data) {
    if (low < high) {
        int pi = partition(a, low, high, data);

        /* Recursively sort the two partitions. */
        quickSort_impl(a, low, pi - 1, data);
        quickSort_impl(a, pi + 1, high, data);
    }
}

Stats quickSort(long long *a, int low, int high) {
    Stats data = {0, 0};

    /* Stores statistics. */
    quickSort_impl(a, low, high, &data);

    return data;
}