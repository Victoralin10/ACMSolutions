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
#define MAXN 1003

using namespace std;

int n, A[26];
char s[MAXN];

int dp[MAXN];
int dp2[MAXN];
bool L[27];

int main(int nargs, char **args) {
    cin >> n >> s;
    for (int i = 0; i < 26; i++) {
        cin >> A[i];
    }

    memset(dp2, 63, sizeof dp2);
    dp[0] = 1;
    dp2[0] = 0;

    int ans2 = -1;
    for (int i = 1; i <= n; i++) {
        memset(L, 0, sizeof L);
        for (int j = i-1; j >= 0; j--) {
            L[s[j] - 'a'] = 1;
            bool ok = 1;
            for (int k = 0; k < 26; k++) {
                if (L[k] && A[k] < i - j) ok = 0;
            }
            if (!ok) break;
            dp[i] = (dp[i] + dp[j])%MOD;
            ans2 = max(ans2, i - j);
            dp2[i] = min(dp2[i], 1 + dp2[j]);
        }
    }

    cout << dp[n] << endl;
    cout << ans2 << endl;
    cout << dp2[n] << endl;

    return 0;
}
