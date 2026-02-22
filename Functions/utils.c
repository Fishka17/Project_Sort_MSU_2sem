#include "utils.h"

/*
 * Absolute value for long long without overflow on LLONG_MIN.
 * For LLONG_MIN, -x overflows, so we compute it via a safe transformation.
 */
unsigned long long abs_ll(long long x) {
    if (x >= 0) {
        return (unsigned long long)x;
    }
    if (x == LLONG_MIN) {
        return (unsigned long long)(-(x + 1)) + 1ULL;
    }
    return (unsigned long long)(-x);
}

/* Swap two elements in-place. */
void swap_ll(long long *a, size_t i, size_t j) {
    long long tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}