/**
* Title:            558 - Wormholes
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003

using namespace std;

int D[MAXN], n;
vector <pair <int, int> > adj[MAXN];

bool refresh() {
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j].first, d = adj[i][j].second;
            if (D[v] > D[i] + d) {
                ans = true;
                D[v] = D[i] + d;
            }
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    memset(D, 31, sizeof D);

    int c, m, u, v, t;
    n = 0;
    scanf("%d", &c);
    while (c--) {
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            D[i] = 1<<30;
        }

        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &t);
            adj[u].push_back(make_pair(v, t));
        }

        D[0] = 0;
        for (int i = 1; i < n; i++) {
            if (!refresh()) break;
        }

        puts(refresh()? "possible":"not possible");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
