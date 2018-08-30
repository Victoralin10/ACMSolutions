/**
* Title:            Simple Game
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 601
#define MAXM 11

using namespace std;

int sumar(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) ans -= MOD;
    return ans;
}

int memo[MAXM][MAXN][MAXM], k, n, m;

int cnt(int m, int n, int p) {
    if (m == 0) {
        return n == 0;
    }
    int &ret = memo[m][n][p];

    if (ret == -1) {
        ret = 0;
        for (int x = min(k>>p, n>>p); x >= 0; x--) {
            ret = sumar(ret, cnt(m - 1, n - (x<<p), p));
        }
    }

    return ret;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    cin >> n >> m >> k;

    n -= m;
    memset(memo, -1, sizeof memo);
    
    int ans = 0;
    for (int pot = 0; (1<<pot) <= min(n, k); pot++) {
        for (int mask = (1<<m) - 1; mask > 0; mask--) {
            int cb = __builtin_popcount(mask);
            if ((cb&1) == 1 && (cb<<pot) <= n) {
                ans = sumar(ans, cnt(m, n - (cb<<pot), pot + 1));
            }
        }
    }

    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
