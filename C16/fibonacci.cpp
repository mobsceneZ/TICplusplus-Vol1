#include "../require.h"

int fibonacci(int n) {
    const int sz = 100;
    require(n < sz);
    static int f[sz];
    f[0] = f[1] = 1;
    int i;
    for (i = 0; i < sz; i++)
        if (f[i] == 0) break;
    while (i <= n) {
        f[i] = f[i-1] + f[i-2];
        i++;
    }
    return f[n];
}