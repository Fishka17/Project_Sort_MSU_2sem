#include <time.h>
#include <stdlib.h>
#include <limits.h>

static long long 
arr_elem(void) {
    long long x = rand();
    x *= rand();
    return x;
}

void 
generateArray(int option, int n, long long *a) {
    if (n <= 0) return;
    if (option == 1) { // 1 случай, элементы упорядочены
        long long step = LLONG_MAX / n;
        if (step == 0) {
            step = 1;
        }
        long long x = LLONG_MAX - step;
        for (int i = 0; i < n; ++i) {
            a[i] = x + llabs(arr_elem()) % step;
            if (rand() & 1) {
                a[i] = -a[i];
            }
            x -= step;
        }
    } else if (option == 2) { // 2 случай, элемегты упорядочены в обратном порядке
        unsigned long long step = 0;
        long long l = (-LLONG_MAX) / n, r = LLONG_MAX / n;
        for (int i = 0; i < n; ++i) {
            step = r - l;
            a[i] = l + llabs(arr_elem()) % step;
            l -= LLONG_MAX / n;
            r += LLONG_MAX / n;
        }
    } else { // 3, 4 случай, рандом
        for (int i = 0; i < n; ++i) {
            a[i] = arr_elem();
        }
    }
}