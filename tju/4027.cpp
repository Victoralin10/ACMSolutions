#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
#define MOD 10007

char s[MAXN];
int dp[MAXN][MAXN];

int main() {
    int tc;
    scanf("%d", &tc);
    for (int caso = 1; caso <= tc; caso++) {
    scanf("%s", s);
    int l = strlen(s);
    dp[0][0] = 1;
    for (int i = 1; i < l; i++) {
        dp[i][i] = 1;
        dp[i - 1][i] = 2 + (s[i-1] == s[i]);
        for (int j = i - 2; j >= 0; j--) {
            if (s[j] == s[i]) {
                dp[j][i] = dp[j][i-1] + dp[j+1][i] + 1;
                if (dp[j][i] >= MOD) {
                    dp[j][i] -= MOD;
                }
            } else {
                dp[j][i] = (dp[j][i-1] + dp[j+1][i] - dp[j+1][i-1] + MOD) % MOD;
            }
        }
    }
    cout << "Case " << caso << ": " << dp[0][l-1] << endl;
    }
}
