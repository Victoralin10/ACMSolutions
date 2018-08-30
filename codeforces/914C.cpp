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

int P[MAXN];

char s[MAXN];
int l, k;

int memo[MAXN][MAXN][2];

int dp(int px, int cnt, bool less) {
    if (px == l) return P[cnt] == k;
    if (memo[px][cnt][less] != -1) return memo[px][cnt][less];

    int ans = dp(px + 1, cnt, less || s[px] == '1');
    if (s[px] == '1' || less) {
        ans += dp(px + 1, cnt + 1, less);
    }

    if (ans >= MOD) ans -= MOD;
    return memo[px][cnt][less] = ans;
}

int main(int nargs, char **args) {
    P[0] = -5;
    P[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        P[i] = P[__builtin_popcount(i)] + 1;
    }
    cin >> s >> k;
    if (k == 0) {
        puts("1");
        return 0;
    }
    
    l = strlen(s);
    k--;
    memset(memo, -1, sizeof memo);
    cout << (dp(0, 0, 0) - (k==0) + MOD)%MOD << endl;

    return 0;
}
