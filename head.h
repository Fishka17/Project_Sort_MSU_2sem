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
 * option:
 *   1 - elements are already ordered by non-increasing absolute value
 *   2 - elements are ordered in the reverse order
 *   3/4 - random elements
 *
 * n     - length of array
 * a     - output array of length n
 */
void 
generateArray(int option, int n, long long *a);

/* Bubble sort by non-increasing absolute value (|a[i]|). */
Stats 
bubbleSort(long long *a, int n);

/* Quick sort by non-increasing absolute value (|a[i]|). */
Stats 
quickSort(long long *a, int low, int high);

#endif