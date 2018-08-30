/**
* Title:            7344 - Numbered Cards
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1025

using namespace std;

int C[MAXN];

void calcular_cnt(int n) {
    for (int mask = (1<<n) - 1;mask > 0; mask--) {

    }
}

int dp2[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n;
    scanf("%d", &t);

    for (int caso = 1; caso <= t; caso++) {
        scanf("%d", &n);

        calcular_cnt(n);
        
        for (int i = 1;i < (1<<10);i++) {

        }

        printf("Case %d: %d\n", caso, ans);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
