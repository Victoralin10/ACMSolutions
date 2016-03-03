/**
* Title:            4027.   Palindrome subsequence
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 10007
#define MAXN 1003

using namespace std;

char line[MAXN];

int dp[MAXN][MAXN];

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    for (int i = 0; i < MAXN; i++) {
        dp[i][i] = 1;
    }

    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%s", line);
        int l = strlen(line);

        for (int len = 2; len <= l; len++) {
            for (int i = 0, j; i + len <= l; i++) {
                j = i + len - 1;
                dp[i][j] = dp[i][j-1] + dp[i+1][j];
                if (len > 2) {
                    dp[i][j] -= dp[i+1][j-1];
                }
                if (line[i] == line[j]) {
                    dp[i][j] += 1;
                    if (len > 2) {
                        dp[i][j] += dp[i+1][j-1];
                    }
                }
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }

        printf("Case %d: %d\n", caso, dp[0][l-1]);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
