/**
* Title:            7365 - Composition
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10004

using namespace std;

pair <pair <int, int>, pair <int, int> > T[MAXN];
pair <int, long long> A[MAXN];

long long dp[40];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int p;
    cin >> p;

    for (int i = 0, K, n, m, k;i < p;i++) {
        cin >> K >> n >> m >> k;
        T[i] = make_pair(make_pair(m, k), make_pair(K, n));
    }
    sort(T, T + p);

    for (int i = 0;i < p;i++) {
        if (i == 0 || T[i].first != T[i-1].first) {
            memset(dp, 0, sizeof dp);
            dp[0] = 1;

            int m = T[i].first.first, k = T[i].first.second;
            for (int j = 1;j <= 30;j++) {
                for (int x = 0;x <= j;x++) {
                    if (x >= m && (x - m)%k == 0) continue;
                    dp[j] += dp[j - x];
                }
            }
        }
        A[i] = make_pair(T[i].second.first, dp[T[i].second.second]);
    }
    sort(A, A + p);

    for (int i = 0; i < p; i++) {
        cout << A[i].first << " " << A[i].second << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
