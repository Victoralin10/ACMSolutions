/**
* Title:            11426 - GCD - Extreme (II)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <cstdio>
#include <cmath>
#define MAXN 4000001

using namespace std;

int mu[MAXN];

void mobius() {
    for (int i = 1; i < MAXN; i++)
        mu[i] = 1;

    for (int i = 2; i <= 2000; i++) {
        if (mu[i] == 1) {
            for (int j = i;j < MAXN; j += i)
                mu[j] *= -i;
            for (int j = i*i;j < MAXN; j += i*i)
                mu[j] = 0;
        }
    }

    for (int i = 2; i < MAXN; i++) {
        if (mu[i] == i) mu[i] = 1;
        else if (mu[i] == -i) mu[i] = -1;
        else if (mu[i] < 0) mu[i] = 1;
        else if (mu[i] > 0) mu[i] = -1;
    }
}

int f[MAXN];
long long AC[MAXN];

void function() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            f[j] += i*mu[j/i];
        }

        AC[i] = AC[i-1] + f[i];
    }
}

int main(int nargs, char **args) {
    //clock_t _inicio = clock();
    mobius();
    function();

    int n;
    while (scanf("%d", &n) != EOF && n > 0) {
        long long ans = 0;

        int rt = (int)sqrt(n + 0.5);
        for (int i = 1, last = n, nxt, xd; i <= rt; i++) {
            nxt = n/(i+1);
            ans += ((i*(i - 1))/2)*(AC[last] - AC[nxt]);
            last = nxt;

            if (i < n/i) {
                xd = n/i;
                ans += f[i]*(xd*(xd - 1LL))/2;
            }
        }

        printf("%lld\n", ans);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
