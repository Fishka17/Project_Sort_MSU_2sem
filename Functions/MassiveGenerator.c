#include <time.h>
#include <stdlib.h>
#include <limits.h>

static long long arr_elem() {
    long long x = rand();
    x *= rand();
    return x;
}

void generateArray(int option, int n, long long *a) {
    if (n <= 0) return;
    if (option == 1) { // 1 случай, элемегты упорядочены
        unsigned long long span = 0;
        long long l = -LLONG_MAX, r = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            span = r - l;
            if (span == 0) {
                span = 2;
            }
            a[i] = l + llabs(arr_elem()) % span;
            l += LLONG_MAX / n;
            r -= LLONG_MAX / n;
        }
    } else if (option == 2) { // 2 случай, элемегты упорядочены в обратном порядке
        unsigned long long span = 0;
        long long l = (-LLONG_MAX) / n, r = LLONG_MAX / n;
        for (int i = 0; i < n; ++i) {
            span = r - l;
            a[i] = l + llabs(arr_elem()) % span;
            l -= LLONG_MAX / n;
            r += LLONG_MAX / n;
        }
    } else { // 3, 4 случай, рандом
        for (int i = 0; i < n; ++i) {
            a[i] = arr_elem();
        }
    }
}