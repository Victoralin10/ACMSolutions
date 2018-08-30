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

int C[MAXN], n;
vector <int> G[MAXN];
pair <bool, int> CST[MAXN];

void dfs1(int node, int parent) {
    set <int> st;
    for (int i = 0; i < G[node].size(); i++) {
        if (G[node][i] == parent) continue;

        dfs1(G[node][i], node);
        st.insert(CST[G[node][i]].se);
    }

    if ((st.size() == 1 && *st.begin() == C[node]) || st.size() == 0) {
        CST[node] = mp(1, C[node]);
    } else {
        CST[node] = mp(0, -1);
    }
}

int dfs2(int node, int ant, int c) {
    if (CST[node].fi) return node;

    map <int, int> mp;
    int cok = 0, nd;
    bool ok = 1;
    for (int i = 0; i < G[node].size(); i++) {
        if (ant == G[node][i]) continue;

        mp[C[G[node][i]]]++;

        if (!CST[G[node][i]].fi) {
            nd = G[node][i];
            cok++;
        } else {
            if (C[G[node][i]] != c) ok = 0;
        }
    }

    if (cok == 0) return node;

    if (!ok || cok != 1 || c != C[node]) return -1;
    return dfs2(nd, node, c);
}

int main(int nargs, char **args) {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        u--; v--;

        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    dfs1(0, -1);

    // for (int i = 0; i < 4; i++) {
    //     cout << CST[i].fi << " " << CST[i].se << endl;
    // }

    int nd = dfs2(0, -1, C[0]);
    if (nd != -1) {
        cout << "YES \n" << nd+1 << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
