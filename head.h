#ifndef HEAD_H
#define HEAD_H

#include <stddef.h>

/*
 * Collect statistic
 * cmp  - number of element comparisons
 * swp  - number of swaps
 */
typedef struct { 
    unsigned long long cmp;
    unsigned long long swp;
} Stats;

/*
 * Generates an array for experiments.
 *
 * n     - length of array
 * a     - output array of length n
 */
void 
generateArray(int option, int n, long long *a);

/* Bubble sort, n - lenght of array, a - array */
Stats 
bubbleSort(long long *a, int n);

/* Quick sort, a - array, low - start pos for sort, high - end pos for sort */
Stats 
quickSort(long long *a, int low, int high);

#endif