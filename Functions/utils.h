#ifndef UTILS_H
#define UTILS_H

#include <limits.h>   /* LLONG_MIN */
#include <stddef.h>   /* size_t */

unsigned long long abs_ll(long long x);
void swap_ll(long long *a, size_t i, size_t j);

#endif /* UTILS_H */