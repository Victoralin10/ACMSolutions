#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 100005

using namespace std;

int M[MAXN][3], dp[MAXN][3];

int main(int nargs, char **args) {
    int n, caso = 1;
    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> M[i][j];
            }
        }
        dp[0][0] = (1<<30);
        dp[0][1] = M[0][1];
        dp[0][2] = M[0][1] + M[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                if (j < 2) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                }
                dp[i][j] += M[i][j];
            }
        }

        cout << (caso++) << ". " << dp[n-1][1] << endl;
    }
    return 0;
}
