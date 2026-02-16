#include <stdlib.h>

static void swap(long long *arr, int i, int j) {
    long long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

static unsigned long long myAbsll(long long x) {
    return (x < 0) ? (unsigned long long)(-(x + 1)) + 1ULL : (unsigned long long)x;
}

int partition(long long *arr, int low, int high) {

    // Initialize pivot to be the first element
    long long p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (i <= high - 1 && myAbsll(arr[i]) >= myAbsll(p)) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (j >= low + 1  && myAbsll(arr[j]) <  myAbsll(p)) {
            j--;
        }

        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

void quickSort(long long *a, int low, int high)  {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(a, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}