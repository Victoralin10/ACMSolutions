#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1003

using namespace std;

int M[MAXN][MAXN], DP[MAXN][MAXN];

int main(int nargs, char **args) {
    int t, n, m;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        DP[0][0] = M[0][0];
        for (int c = 1; c < m; c++) {
            DP[0][c] = M[0][c] + DP[0][c-1];
        }
        for (int r = 1; r < n; r++) {
            DP[r][0] = M[r][0] + DP[r-1][0];
            for (int c = 1; c < m; c++) {
                DP[r][c] = M[r][c] + max(DP[r - 1][c], DP[r][c - 1]);
            }
        }

        printf("Case %d: %d\n", caso, DP[n-1][m-1]);
    }
    return 0;
}
