/**
* Title:            Synchronous Shopping
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003

using namespace std;

vector <pair<int, int> > G[MAXN];
int T[MAXN];
long long D[MAXN][1<<10];
bool vis[MAXN][1<<10];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1, t, ti; i <= n; i++) {
        cin >> t;
        while (t--) {
            cin >> ti;
            T[i] |= (1<<(ti - 1));
        }
    }

    for (int i = 0, u, v, z; i < m; i++) {
        cin >> u >> v >> z;
        G[u].push_back(make_pair(v, z));
        G[v].push_back(make_pair(u, z));
    }

    memset(D, 63, sizeof D);

    priority_queue <pair <int, pair <int, int> > > Q;
    Q.push(make_pair(0, make_pair(T[1], 1)));
    D[1][T[1]] = 0;

    while (!Q.empty()) {
        pair <int, pair <int, int> > q = Q.top();
        Q.pop();

        int nodo = q.second.second;
        int mka = q.second.first;
        
        if (vis[nodo][mka]) continue;
        vis[nodo][mka] = true;

        for (int i = 0; i < G[nodo].size(); i++) {
            int nv = G[nodo][i].first;
            int z = G[nodo][i].second;
            int tt = mka|T[nv];

            if (D[nodo][mka] + z < D[nv][tt]) {
                D[nv][tt] = D[nodo][mka] + z;
                Q.push(make_pair(-D[nv][tt], make_pair(tt, nv)));
            }
        }
    }

    long long ans = (1LL<<50);
    for (int mask = (1<<k) - 1; mask >= 0; mask--) {
        for (int j = (1<<k) - 1; j >= 0; j--) {
            if ((mask|j) == (1<<k) - 1) {
                ans = min(ans, max(D[n][mask], D[n][j]));
            }
        }
    }

    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
