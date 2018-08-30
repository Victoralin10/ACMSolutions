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
#define MAXN 300005

using namespace std;

int p[MAXN];
char c[MAXN];
int left_g[MAXN], right_g[MAXN];
int left_r[MAXN];
int left_b[MAXN];

int h[MAXN];
int F(int x) { return x==h[x]?x:h[x]=F(h[x]); }
void U(int x, int y) { h[F(x)] = F(y); }

int main(int nargs, char **args) {
    int n;
    cin >> n;
    left_g[0] = left_r[0] = left_b[0] = -1;
    right_g[n-1] = INT_MAX;

    for (int i = 0;i < n;i++) {
        cin >> p[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        if (c[i-1] == 'G') {
            left_g[i] = i-1;
        } else {
            left_g[i] = left_g[i-1];
        }
        if (c[i-1] == 'R') {
            left_r[i] = i-1;
        } else {
            left_r[i] = left_r[i-1];
        }
        if (c[i-1] == 'B') {
            left_b[i] = i-1;
        } else {
            left_b[i] = left_b[i-1];
        }
    }
    for (int i = n-2; i >= 0; i--) {
        if (c[i+1] == 'G') {
            right_g[i] = i+1;
        } else {
            right_g[i] = right_g[i+1];
        }
    }
    for (int i = 0; i < n; i++) {
        h[i] = i;
    }
    ll ans = 0;
    for (int i = 0, prg = -1; i < n; i++) {
        if (c[i] != 'G') continue;
        if (prg >= 0) {
            ans += p[i] - p[prg];
            U(i, prg);
        }
        prg = i;
    }
    vector <pair <int, pair <int, int> > > verts;
    for (int i = 0; i < n; i++) {
        if (c[i] != 'R') continue;
        if (left_r[i] != -1) {
            verts.pb(mp(p[i] - p[left_r[i]], mp(i, left_r[i])));
        }
        if (left_g[i] != -1) {
            verts.pb(mp(p[i] - p[left_g[i]], mp(left_g[i], i)));
        }
        if (right_g[i] != INT_MAX) {
            verts.pb(mp(p[right_g[i]] - p[i], mp(i, right_g[i])));
        }
    }
    for (int i = 0; i < n; i++) {
        if (c[i] != 'B') continue;
        if (left_b[i] != -1) {
            verts.pb(mp(p[i] - p[left_b[i]], mp(i, left_b[i])));
        }
        if (left_g[i] != -1) {
            verts.pb(mp(p[i] - p[left_g[i]], mp(left_g[i], i)));
        }
        if (right_g[i] != INT_MAX) {
            verts.pb(mp(p[right_g[i]] - p[i], mp(i, right_g[i])));
        }
    }
    sort(verts.begin(), verts.end());
    for (int i = 0, u, v; i < verts.size(); i++) {
        u = verts[i].se.fi; v = verts[i].se.se;
        if (F(u) != F(v)) {
            ans += verts[i].fi;
            U(u, v);
        }
    }
    cout << ans << endl;
    
    return 0;
}
