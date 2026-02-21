#include <time.h>
#include <stdlib.h>
#include <limits.h>

static long long 
arr_elem(void) {
    /* A simple way to obtain a wider range than rand(). */
    long long x = rand();
    x *= rand();
    return x;
}

void 
generateArray(int option, int n, long long *a) {
    if (n <= 0) return;

    /*
     * The sorting in this project is by *non-increasing absolute value*.
     * So for options (1) and (2) we build arrays that are already ordered
     * (by |a[i]|) or ordered in reverse.
     */
    if (option == 1) { /* Case 1: already sorted by non-increasing |a[i]|. */
        long long step = LLONG_MAX / n;
        if (step == 0) {
            step = 1;
        }
        long long x = LLONG_MAX - step;
        for (int i = 0; i < n; ++i) {
            /* x decreases each iteration => |a[i]| tends to decrease too. */
            a[i] = x + llabs(arr_elem()) % step;

            /* Randomize the sign: sorting compares by absolute value only. */
            if (rand() & 1) {
                a[i] = -a[i];
            }
            x -= step;
        }
    } else if (option == 2) { /* Case 2: reverse order (non-decreasing |a[i]|). */
        long long step = LLONG_MAX / n;
        if (step == 0) {
            step = 1;
        }
        long long x = 0;
        for (int i = 0; i < n; ++i) {
            /* x increases each iteration => |a[i]| tends to increase. */
            a[i] = x + llabs(arr_elem()) % step;
            if (rand() & 1) {
                a[i] = -a[i];
            }
            x += step;
        }
    } else { /* Case 3/4: random array. */
        for (int i = 0; i < n; ++i) {
            a[i] = arr_elem();
        }
    }
}