#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

// generator
void generateArray(int option, int n, long long *a);

// sorts
void bubbleSort(long long *a, int n);
void quickSort(long long *a, int n);

#endif