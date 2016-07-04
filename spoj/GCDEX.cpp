/**
* Title:            GCDEX - GCD Extreme
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <cstdio>
#include <cmath>
#define MAXN 1000001

using namespace std;
int phi[MAXN], f1[MAXN];
long long f2[MAXN];

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    for (int i = 1; i < MAXN; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                phi[j] /= i;
                phi[j] *= i-1;
            }
        }
    }

    f1[0] = f1[1] = 0;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 2*i; j < MAXN; j += i) {
            f1[j] += (long long)i*phi[j/i];
        }
        f2[i] = f2[i-1] + f1[i];
    }

    int n;
    while (scanf("%d", &n) != EOF && n > 0) {
        printf("%lld\n", f2[n]);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
