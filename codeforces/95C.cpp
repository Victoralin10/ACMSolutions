/**
* Title:            C. Volleyball
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003

using namespace std;

vector <pair <int, int> > G[MAXN], G2[MAXN];
pair <int, int> N[MAXN];
long long D[MAXN][MAXN], D2[MAXN];
bool vis[MAXN];

void dijkstra(int nd) {
    memset(vis, 0, sizeof vis);

    D[nd][nd] = 0;
    priority_queue<pair <int, int> > Q;
    Q.push(make_pair(0, nd));

    while (!Q.empty()) {
        pair <int, int> q = Q.top();
        Q.pop();

        int cur = q.second;
        if (vis[cur]) continue;
        vis[cur] = true;

        for (typeof G[cur].begin() it = G[cur].begin(); it != G[cur].end(); it++) {
            if (D[nd][it->first] > D[nd][cur] + it->second) {
                D[nd][it->first] = D[nd][cur] + it->second;
                Q.push(make_pair(-D[nd][it->first], it->first));
            }
        }
    }
}

long long solve(int x, int y) {
    memset(D2, 63, sizeof D2);
    memset(vis, 0, sizeof vis);

    D2[x] = 0;
    priority_queue <pair <int, int> > Q;
    Q.push(make_pair(0, x));

    while (!Q.empty()) {
        pair <int, int> q = Q.top();
        Q.pop();
        
        int cur = q.second;
        if (vis[cur]) continue;
        vis[cur] = true;

        for (typeof G2[cur].begin() it = G2[cur].begin(); it != G2[cur].end(); it++) {
            if (D2[it->first] > D2[cur] + it->second) {
                D2[it->first] = D2[cur] + it->second;
                Q.push(make_pair(-D2[it->first], it->first));
            }
        }
    }

    return D2[y];
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = 0, u, v, d; i < m; i++) {
        cin >> u >> v >> d;
        G[u].push_back(make_pair(v, d));
        G[v].push_back(make_pair(u, d));
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> N[i].first >> N[i].second;
    }

    memset(D, 63, sizeof D);
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) continue;
            if (D[i][j] <= N[i].first) {
                G2[i].push_back(make_pair(j, N[i].second));
            }
        }
    }

    long long ans = solve(x, y);
    if (ans > 1e12) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
