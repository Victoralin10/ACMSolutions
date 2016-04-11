/**
* Title:            1580. Dean's Debts
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003

using namespace std;

int V[MAXN][2];
bool vis[MAXN][2];
vector <pair<int, int > > g[MAXN];

double VAL[MAXN];

void dfs(int n, int p) {
    vis[n][p] = 1;

    vector <pair <int, int> >::iterator it;
    for (it = g[n].begin(); it != g[n].end(); it++) {
        int nn = it->first, s = it->second;
        if (!vis[nn][1-p]) {
            V[nn][1-p] = s - V[n][p];
            dfs(nn, 1 - p);
        }
    }
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    vector <pair <pair <int, int>, int > > eqs;
    int n, m, u, v, s;
    scanf("%d%d", &n, &m);

    if (n > m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &s);
        g[u].push_back(make_pair(v, s));
        g[v].push_back(make_pair(u, s));
        eqs.push_back(make_pair(make_pair(u, v), s));
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i][0] && !vis[i][1]) {
            V[i][0] = 0;
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        VAL[i] = (V[i][0] + V[i][1])/2.0;
    }

    bool ok = true;
    vector <pair <pair <int, int>, int > >::iterator it;
    for (it = eqs.begin(); it != eqs.end(); it++) {
        if (VAL[it->first.first] + VAL[it->first.second] != it->second) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%.2f\n", VAL[i]);
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
