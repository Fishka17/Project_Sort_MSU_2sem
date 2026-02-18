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

int partition(long long *arr, int low, int high, Stats *data) {
    // Initialize pivot to be the first element
    long long p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (i <= high - 1) {
            data->cmp++;
            if (myAbsll(arr[i]) >= myAbsll(p)) {
                i++;
            } else {
                break;
            }
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (j >= low + 1) {
            data->cmp++;
            if (myAbsll(arr[j]) <  myAbsll(p)) {
                j--;
            } else {
                break;
            }
        }

        if (i < j) {
            swap(arr, i, j);
            data->swp++;
        }
    }

    if (j != low) {
        swap(arr, low, j);
        data->swp++;
    }

    return j;
}

static void quickSort_impl(long long *a, int low, int high, Stats *data) {
    if (low < high) {
        int pi = partition(a, low, high, data);
        quickSort_impl(a, low, pi - 1, data);
        quickSort_impl(a, pi + 1, high, data);
    }
}

Stats quickSort(long long *a, int low, int high) {
    Stats data = {0, 0};
    quickSort_impl(a, low, high, &data);

    return data;
}