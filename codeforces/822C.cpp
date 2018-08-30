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
#define MAXN 200005

using namespace std;

vector < pair <int, int > > tikets[MAXN];
int mn[MAXN];

int main(int nargs, char **args) {
    int n, x;
    cin >> n >> x;

    for (int i = 0, l, r, w; i < n; i++) {
        cin >> l >> r >> w;
        tikets[r-l+1].pb(mp(l, w));
    }

    for (int i = 0; i <= x; i++) {
        sort(tikets[i].begin(), tikets[i].end());
    }

    int ans = (1L<<31) - 1;
    for (int d1 = 1, d2 = x - 1; d1 <= d2; d1++, d2--) {
        mn[tikets[d2].size()] = (1<<30);
        for (int i = (int)tikets[d2].size() - 1; i >= 0; i--) {
            mn[i] = min(tikets[d2][i].se, mn[i+1]);
        }

        for (int i = 0, j = 0; i < tikets[d1].size(); i++) {
            while (j < tikets[d2].size() && tikets[d2][j].fi < tikets[d1][i].fi + d1) {
                j++;
            }
            if (j < tikets[d2].size()) {
                ans = min(ans, tikets[d1][i].se + mn[j]);
            }
        }

        mn[tikets[d1].size()] = (1<<30);
        for (int i = (int)tikets[d1].size() - 1; i >= 0; i--) {
            mn[i] = min(tikets[d1][i].se, mn[i+1]);
        }

        for (int i = 0, j = 0; i < tikets[d2].size(); i++) {
            while (j < tikets[d1].size() && tikets[d1][j].fi < tikets[d2][i].fi + d2) {
                j++;
            }
            if (j < tikets[d1].size()) {
                ans = min(ans, mn[j] + tikets[d2][i].se);
            }
        }
    }

    if (ans != (1L<<31) - 1) cout << ans << endl;
    else puts("-1");

    return 0;
}
