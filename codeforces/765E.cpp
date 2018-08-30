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
#define MAXN 10

using namespace std;

int n;
vector <int> G[MAXN];

int dfs(int node, int patern, int ls) {
    cout << node << " " << patern << endl;
    int cnt = 0;
    for (int i = 0; i < G[node].size(); i++) {
        cnt += (G[node][i] != patern);
    }
    if (cnt == 0) {
        return 1;
    } else if (cnt == 1) {
        if (G[node][0] != patern) cnt = 0;
        dfs(G[node][cnt], node, ls + 1);
    } else {
        vector <int> ds, dmu;

        for (int i = 0; i < G[node].size(); i++) {
            if (G[node][i] == patern) continue;

            int p = dfs(G[node][i], node, 0);
            if (p == -1) {
                dmu.pb(i);
            } else {
                ds.pb(p);
            }
        }

        if (dmu.size() > 1) return -1;
        sort(ds.begin(), ds.end());

        int j = 0;
        for (int i = 0; i < ds.size(); i++) {
            if (j > 0 && ds[i] == ds[j]) j--;
            else ds[j++] = ds[i];
        }

        if (j > 1) return -1;
        if (dmu.size() > 0 && j > 0) return -1;
        if (j > 0) return ds[0] + 1;

        return dfs(G[node][dmu[0]], node, ls + 1);
    }
}

int main(int nargs, char **args) {
    cin >> n;
    for (int i = 1, u, v;i < n;i++) {
        cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    cout << dfs(0, -1, 0) << endl;

    return 0;
}
