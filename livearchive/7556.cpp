/**
* Title:            7556 - Jump on Buildings
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 5001

using namespace std;

int dp[MAXN][MAXN], H[MAXN];
pair <int, int> ord[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> H[i];
            ord[i] = make_pair(H[i], i);
        }
        sort(ord, ord + n);

        memset(dp, 0, sizeof dp);
        for (int i = 0;i < n;i++) {
            int ind = ord[i].second;
            for (int j = ind-1;j >= 0;j--) {
                dp[ind][j] = max(H[ind]>H[j]?1+dp[j][ind-1]:0, dp[ind][j+1]);
            }
            for (int j = ind+1;j < n;j++) {
                dp[ind][j] = max(H[ind]>H[j]?1+dp[j][ind+1]:0, dp[ind][j-1]);
            }
        }

        for (int i = 0;i < n;i++) {
            printf("%d ", max(dp[i][0], dp[i][n-1]));
        }
        printf("\n");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
