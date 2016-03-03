/**
* Title:            3524.   Task Process
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 51
#define MAXY 201

using namespace std;

struct Worker {
    int tx, ty;
} T[MAXN];

int t, n, x, y;
int memo[MAXN][MAXY];

int dp(int px, int x, int t) {
    if (px == 0) {
        return x == 0? 0: -2;
    }
    int &ret = memo[px][x];

    if (ret == -1) {
        ret = -2;
        for (int i = min(x, t/T[px].tx); i >= 0; i--) {
            int j = (t - i*T[px].tx)/T[px].ty;
            int pa = dp(px - 1, x - i, t);
            if (pa != -2 && pa + j > ret) {
                ret = pa + j;
            }
        }
    }

    return ret;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d%d%d", &n, &x, &y);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &T[i].tx, &T[i].ty);
        }

        int lo = 0, hi = (400002), mid;
        while (hi - lo > 1) {
            mid = (hi + lo) >> 1;
            memset(memo, -1, sizeof memo);
            if (dp(n, x, mid) >= y) hi = mid;
            else lo = mid;
        }

        printf("Case %d: %d\n", caso, hi);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
