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
#define OO (1LL<<60)

using namespace std;

vector <int> G[MAXN];
int P[MAXN];
ll S[MAXN], M[MAXN][2];

ll sum(int node, int parent = -1) {
    ll ans = P[node];
    for (int i = 0, v; i < G[node].size(); i++) {
        v = G[node][i];
        if (v == parent) continue;
        ans += sum(v, node);
    }
    return S[node] = ans;
}

ll dp(int node, bool all, int parent = -1) {
    if (M[node][all] != -1) {
        return M[node][all];
    }
    ll ans = -OO;
    if (all) {
        ans = S[node];
        for (int i = 0, v; i < G[node].size(); i++) {
            v = G[node][i];
            if (v == parent) continue;
            ans = max(ans, dp(v, 1, node));
        }
    } else {
        ll mx1 = -OO, mx2 = -OO, x;
        for (int i = 0, v; i < G[node].size(); i++) {
            v = G[node][i];
            if (v == parent) continue;
            ans = max(ans, dp(v, 0, node));
            x = dp(v, 1, node);
            if (x > mx2) {
                mx1 = mx2;
                mx2 = x;
            } else if (x > mx1) {
                mx1 = x;
            }
        }
        if (mx1 != -OO) {
            ans = max(mx1 + mx2, ans);
        }
    }

    return M[node][all]=ans;
}

int main(int nargs, char **args) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    sum(1);
    memset(M, -1, sizeof M);
    ll x = dp(1, 0);
    if (x == -OO) {
        cout << "Impossible" << endl;
    } else {
        cout << x << endl;
    }

    return 0;
}
