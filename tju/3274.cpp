/**
* Title:            3274.   Rescue Me II
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1023
#define MAXN 900005

using namespace std;

int A2[MAXN], I[MAXN], F[MAXN];

int pow(int b, int e) {
    int ans = 1;
    while (e) {
        if ((e&1)) ans = (ans*b) & MOD;
        b = (b*b) & MOD;
        e >>= 1;
    }
    return ans;
}

int cmb(int n, int m) {
    int nrd = A2[n] - A2[m] - A2[n-m];
    if (nrd >= 10) return 0;

    int ans = (F[n]*I[m]) & MOD;
    ans = (ans*I[n-m]) & MOD;
    ans = (ans*(1<<nrd)) & MOD;
    return ans;
}

int solve(int x, int y, int z) {
    int ans = 0;
    for (int i = 1; i < x; i++) {
        ans += cmb(z + i - 1, i)*cmb(y + x - i, y);
        ans += cmb(y + i - 1, i)*cmb(z + x - i, z);
        ans &= MOD;
    }
    for (int i = 1; i < y; i++) {
        ans += cmb(z + i - 1, i)*cmb(x + y - i, x);
        ans += cmb(x + i - 1, i)*cmb(z + y - i, z);
        ans &= MOD;
    }
    for (int i = 1; i < z; i++) {
        ans += cmb(x + i - 1, i)*cmb(y + z - i, y);
        ans += cmb(y + i - 1, i)*cmb(x + z - i, x);
        ans &= MOD;
    }

    ans += cmb(y + z, y);
    ans += cmb(y + x, y);
    ans += cmb(x + z, x);

    return ans & MOD;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    A2[0] = 0;
    I[0] = 1;
    F[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        int nrd = 0, ci = i;
        while (!(ci&1)) {
            nrd++;
            ci >>= 1;
        }
        A2[i] = A2[i-1] + nrd;
        F[i] = (F[i-1]*ci) & MOD;
        I[i] = pow(F[i], 511);
    }

    int x, y, z;
    while (scanf("%d%d%d", &x, &y, &z) != EOF) {
        printf("%d\n", solve(x, y, z));
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
