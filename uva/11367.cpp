/**
* Title:            11367 - Full Tank?
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003
#define MAXC 102

using namespace std;

int n, m;
int P[MAXN];
vector <pair<int, int> > G[MAXN];
int D[MAXN][MAXC];

struct edge {
    int n, g, d;
    edge(){}
    edge(int n, int g, int d): n(n), g(g), d(d){}

    bool operator < (const edge &that) const {
        return d > that.d;
    }
};

int dijkstra(int s, int e, int c) {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXC; j++) {
            D[i][j] = INT_MAX;
        }
    }

    priority_queue <edge> Q;
    D[s][0] = 0;
    Q.push(edge(s, 0, 0));

    vector <pair <int, int> >::iterator it;

    while (!Q.empty()) {
        edge q = Q.top();
        Q.pop();

        if (q.d > D[q.n][q.g]) continue;
        if (q.n == e) {
            return q.d;
        }

        if (q.g < c && D[q.n][q.g+1] > D[q.n][q.g] + P[q.n]) {
            D[q.n][q.g+1] = D[q.n][q.g] + P[q.n];
            Q.push(edge(q.n, q.g + 1, D[q.n][q.g + 1]));
        }

        for (it = G[q.n].begin(); it != G[q.n].end(); it++) {
            if (q.g >= it->second && D[it->first][q.g - it->second] > D[q.n][q.g]) {
                D[it->first][q.g - it->second] = D[q.n][q.g];
                Q.push(edge(it->first, q.g - it->second, D[q.n][q.g]));
            }
        }
    }

    return INT_MAX;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock(); 
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    for (int i = 0, u, v, d; i < m; i++) {
        cin >> u >> v >> d;
        G[u].push_back(make_pair(v, d));
        G[v].push_back(make_pair(u, d));
    }

    int q, s, e, c;
    cin >> q;
    while (q--) {
        cin >> c >> s >> e;
        int ans = dijkstra(s, e, c);
        if (ans == INT_MAX) {
            cout << "impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
