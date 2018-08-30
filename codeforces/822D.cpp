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
#define MAXN 5000006

using namespace std;

int dp[MAXN];
int A[MAXN], p[MAXN], pc = 0;

void sieve(int r) {
    for (int i = 2; i <= r; i++) {
        if (!A[i]) {
            A[i] = ++pc;
            p[pc] = i;
        }
        for (int j = 1; j <= A[i] && i*p[j] <= r; j++) {
            A[i*p[j]] = j;
        }
    }
}

int main(int nargs, char **args) {
    int t, l, r;
    cin >> t >> l >> r;
    sieve(r);

    dp[1] = 0;
    for (int i = 2, mp; i <= r; i++) {
        mp = p[A[i]];
        dp[i] = (((ll)mp*(mp - 1))/2) % MOD;
        dp[i] = ((ll)(i/mp)*dp[i]) % MOD;
        dp[i] = (dp[i] + dp[i/mp]) % MOD;
    }

    ll ans = 0, pt = 1;
    for (int i = l; i <= r; i++) {
        ans += dp[i]*pt % MOD;
        if (ans >= MOD) ans -= MOD;
        pt = pt*t % MOD;
    }

    cout << ans << endl;

    return 0;
}
