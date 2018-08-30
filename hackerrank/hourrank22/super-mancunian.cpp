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

int n, m;
int H[MAXN], C[MAXN];

int F(int x) { return x==H[x]?x:H[x]=F(H[x]); }

void U(int x, int y) {
    C[F(y)] += C[F(x)];
    C[F(x)] += C[F(y)];
    H[F(x)] = F(y);
}

vector < painr <int, int> > G[MAXN];
int NH[MAXN];

void upNh(int node, int parent) {
    NH[node] = 1;
    for (int i = 0; i < G[node].size(); i++) {
        int nn = G[node][i].fi;
        if (nn != parent) {
            upNh(nn, node);
            NH[node] += NH[nn];
        }
    }
}

int cp

int main(int nargs, char **args) {
    cin >> n >> m;
    vector < pair <int, pair <int, int> > > edges;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        edges.pb(mp(w, mp(u, v)));
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i <= n; i++) {
        H[i] = i;
        C[i] = 1;
    }

    ll costo = 0;
    int wg;
    vector < pair <int, pair <int, int> > >::iterator it;
    for (it = edges.begin(); it != edges.end(); it++) {
        int u = it->se.fi, v = it->se.se;
        if (F(u) == F(v)) continue;
        wg = it->fi;
        U(u, v);
        G[u].pb(mp(v, wg));
        G[v].pb(mp(u, wg));
        costo += it->fi;
    }

    upNh(1, -1);

    cout << costo - wg << " " << cnt/2 << endl;
    return 0;
}
