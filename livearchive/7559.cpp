/**
* Title:            7559 - Similar Strings
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 5003

using namespace std;

int P25[MAXN];
int memo[MAXN][MAXN];

int suma(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) {
        ans -= MOD;
    }

    return ans;
}

int cmb(int a, int b) {
    if (a == b || b == 0) {
        return 1;
    }

    int &ret = memo[a][b];
    if (ret == -1) {
        ret = suma(cmb(a - 1, b), cmb(a - 1, b - 1));
    }

    return ret;
}

int memo2[MAXN][MAXN];

int dp(int n, int l) {
    if (n < l) {
        return 0;
    }

    int &ret = memo2[n][l];
    if (ret == -1) {
        ret = suma(cmb(n - 1, l - 1), dp(n - 1, l));
    }
    return ret;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);

    P25[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        P25[i] = (P25[i-1]*25LL) % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        for (int l = 1; l <= n; l++) {
            int sumc = dp(n, l);
            sumc = (long long)sumc*sumc % MOD;
            ans = suma(ans, ((sumc*26LL % MOD)*P25[l - 1]) % MOD);
        }

        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
