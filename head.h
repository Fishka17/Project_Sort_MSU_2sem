#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

/*
 * Statistics collected during sorting.
 *
 * cmp  - number of element comparisons (here: comparisons of absolute values)
 * swp  - number of swaps (each swap exchanges two array elements)
 */
typedef struct { 
    unsigned long long cmp, swp; 
} Stats;

/*
 * Generates an array for experiments.
 *
 * option:
 *   1 - elements are already ordered by non-increasing absolute value
 *   2 - elements are ordered in the reverse order (non-decreasing |a[i]|)
 *   3/4 - random elements
 *
 * n     - length of array (n >= 1 expected)
 * a     - output array of length n
 */
void generateArray(int option, int n, long long *a);

/* Bubble sort by non-increasing absolute value (|a[i]|). */
Stats bubbleSort(long long *a, int n);

/* Quick sort by non-increasing absolute value (|a[i]|). */
Stats quickSort(long long *a, int low, int high);

#endif