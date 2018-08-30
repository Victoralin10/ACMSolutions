#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 200005

#define pb push_back
#define mp make_pair
#define all(v) (v).begin() (v).end()
#define ll long long
#define ull unsigned long long
#define pii pair <int, int>
#define pllll pair <long long, long long>

using namespace std;

struct Edge {
     int node, w, p;
     Edge(){}
     Edge(int node, int w, int p):node(node), w(w), p(p){}
};

int n;
vector <Edge> G[MAXN];
vector <pii> E;
ll X[MAXN];
bool success = true;

map <pii, pii> A;

ll dfs1(int node, int ant, int p) {
    ll ans = 0;
    for (int i = 0; i < G[node].size(); i++) {
        Edge edge = G[node][i];

        if (edge.node == ant) continue;
        ans += dfs1(edge.node, node, edge.p);
        ans += edge.w;
    }

    if (ans > p) {
        X[node] = ans - p;
        ans = p;
    }

    return ans;
}

pllll dfs2(int node, int ant, ll mxp) {
    if (!success) return mp(0, 0);

    pllll ans = mp(0, 0);
    for (int i = 0; i < G[node].size(); i++) {
        Edge edge = G[node][i];
        if (edge.node == ant) continue;

        pllll tmp = dfs2(edge.node, node, max(mxp + X[edge.node] - ans.second, 0LL));
        if (tmp.second < X[edge.node]) {
            success = false;
            // cout << node << " " << tmp.second << endl;
            return mp(0, -1);
        }

        ans.second += tmp.second - X[edge.node];
        X[edge.node] = 0;

        ll pr = max(0LL, edge.p - tmp.first);
        pr = min(pr, edge.w - 1LL);
        pr = min(pr, mxp - ans.second);
        pr = max(pr, 0LL);

        // cout << edge.node << " " << pr << endl; 

        G[node][i].p -= pr;
        G[node][i].w -= pr;
        ans.second += pr;

        ans.first += tmp.first;
        ans.first += G[node][i].w;

        A[mp(node, edge.node)] = mp(G[node][i].w, G[node][i].p);
    }

    return ans;
}

int main(int nargs, char **args) {
    cin >> n;

    for (int i = 1, u, v, w, p; i < n; i++) {
        cin >> u >> v >> w >> p;
        u--; v--;
        E.pb(mp(u, v));
        G[u].pb(Edge(v, w, p));
        G[v].pb(Edge(u, w, p));
    }

    dfs1(0, -1, (1<<30));
    dfs2(0, -1, 0);

    if (success) {
        cout << n << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << E[i].first + 1 << " " << E[i].second + 1;
            
            pii xd = A[E[i]];
            cout << " " << xd.first << " " << xd.second << endl;
        }
    } else {
        cout << "-1" << endl;
    }
}
