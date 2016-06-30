/**
* Title:            Coloring A Tree
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 55

using namespace std;

int memo[MAXN][MAXN];

int cmb(int a, int b) {
    if (b <= 0 || a <= b) return 1;

    int &ret = memo[a][b];
    if (ret == -1) {
        ret = cmb(a - 1, b) + cmb(a - 1, b - 1);
        if (ret >= MOD) {
            ret -= MOD;
        }
    }

    return ret;
}

long long fact[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    memset(memo, -1, sizeof memo);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1]*i % MOD;
    }

    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
        }

        long long ans = 0;
        for (int i = min(n, k); i > 0; i--) {
            ans += (fact[i]*cmb(n - 1, i - 1) % MOD)*cmb(k, i) % MOD;
        }

        cout << ans % MOD << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
