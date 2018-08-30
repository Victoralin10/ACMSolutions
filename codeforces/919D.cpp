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

int n, m;
vector <int> G[MAXN], GI[MAXN];
char s[MAXN];

int O[MAXN], cnt;
bool vis[MAXN];

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = 1;
    for (int i = 0, v; i < G[node].size(); i++) {
        dfs(G[node][i]);
    }
    O[cnt++] = node;
}

int dfs2(int node) {
    if (vis[node]) return 0;
    vis[node] = 1;
    int ans = 1;
    for (int i = 0, v; i < GI[node].size(); i++) {
        ans += dfs2(GI[node][i]);
    }
    return ans;
}

int M[MAXN][26];

int dp(int node, int c) {
    int &dx = M[node][c];
    if (dx == -1) {
        dx = 0;
        for (int i = 0; i < G[node].size(); i++) {
            dx = max(dx, dp(G[node][i], c));
        }
        dx += ((s[node-1]-'a')==c);
    }
    return dx;
}

int main(int nargs, char **args) {
    scanf("%d%d%s", &n, &m, s);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (u == v) {
            puts("-1");
            return 0;
        }
        G[u].pb(v);
        GI[v].pb(u);
    }

    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof vis);
    bool ok = 1;
    for (int i = n-1; i >= 0 && ok; i--) {
        if (dfs2(O[i]) > 1) {
            ok = 0;
        }
    }
    if (!ok) {
        puts("-1");
        return 0;
    }

    memset(M, -1, sizeof M);
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            ans = max(ans, dp(i, c));
        }
    }
    cout << ans << endl;

    return 0;
}
