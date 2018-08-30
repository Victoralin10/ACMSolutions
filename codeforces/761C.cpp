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
#define MAXN 51

using namespace std;

int D[MAXN], L[MAXN], E[MAXN];
int n, m;

int memo[MAXN][2][2][2];

int dp(int p, bool d, bool l, bool e) {
    if (p == n) {
        if (d && l && e) return 0;
        return (1<<20);
    }

    if (memo[p][d][l][e] != -1) return memo[p][d][l][e];

    int ans = dp(p + 1, d, l, e);
    if (!d) {
        ans = min(ans, D[p] + dp(p + 1, 1, l, e));
    }

    if (!l) {
        ans = min(ans, L[p] + dp(p + 1, d, 1, e));
    }
    
    if (!e) {
        ans = min(ans, E[p] + dp(p + 1, d, l, 1));
    }

    return memo[p][d][l][e] = ans;
}

int main(int nargs, char **args) {

    cin >> n >> m;

    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;

        D[i] = L[i] = E[i] = (1<<20);
        for (int j = 0; j < m; j++) {
            int c = min((m - j)%m, j);
            if (isdigit(line[j])) {
                D[i] = min(D[i], c);
            } else if (isalpha(line[j])) {
                L[i] = min(L[i], c);
            } else {
                E[i] = min(E[i], c);
            }
        }

        // cout << D[i] << " " << L[i] << " " << E[i] << endl;
    }

    memset(memo, -1, sizeof memo);
    cout << dp(0, 0, 0, 0) << endl;

    return 0;
}
