/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

vector < pair <int, int> > G[MAXN];
vector <int> C;
bool vis[MAXN], pc[MAXN];

bool dfs(int n) {
    if (vis[n]) {
        C.push_back(n);
        pc[n] = true;
        return true;
    }
    vis[n] = true;

    for (int i = 0; i < G[i].size(); i++) {
        int nv = G[i][i].first;
        if (dfs(nv)) {
            if (C[0] == n) return false;
            C.push_back(n);
            pc[n] = true;
            return true;
        }
    }

    return false;
}

pair <int, int> dfs2(int n) {
    if (pc[n]) {
        return make_pair(n, 0);
    }

    vis[n] = true;
    pair <int, int> ans = make_pair(-1, -1);
    for (int i = 0; i < G[n].size(); i++) {
        int nv = G[n][i].first;
        if (!vis[nv]) {
            pair <int, int> tmp = dfs2(nv);
            if (tmp.first != -1) {
                ans = tmp;
                ans.second += G[n][i].second;
                break;
            }
        }
    }
    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    cin >> n;

    map <pair <int, int>, int> mp;
    for (int i = 0, u, v, x; i < n; i++) {
        cin >> u >> v >> x;
        G[u].push_back(make_pair(v, x));
        G[v].push_back(make_pair(u, -x));

        mp[make_pair(u, v)] = x;
        mp[make_pair(v, u)] = -x;
    }

    dfs(0);
    long long cst = 0;
    for (int i = 0; i < C.size(); i++) {
        cst += mp[make_pair(C[i], C[(i+1)%C.size()])];
    }

    int q, s, e, m;
    cin >> q;
    while (q--) {
        memset(vis, 0, sizeof vis);
        cin >> s >> e >> m;

        pair <int, int> d1 = dfs2(s), d2 = dfs2(e);
        if (d1.first == d2.first) {

        } else {

        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
