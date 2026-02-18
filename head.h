#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

// struct of data
typedef struct { 
    unsigned long long cmp, swp; 
} Stats;

// generator
void generateArray(int option, int n, long long *a);

// sorts
Stats bubbleSort(long long *a, int n);
Stats quickSort(long long *a, int low, int high);

#endif