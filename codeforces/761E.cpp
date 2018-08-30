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
#define MAXN 50

using namespace std;

int n, X[MAXN], Y[MAXN];
vector <int> G[MAXN];

int P[MAXN];
bool vis[2*MAXN][2*MAXN], visn[MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dd[] = {0, 1, 3, 2};

bool bfs() {
    
    queue <int> Q;
    Q.push(0);
    X[0] = Y[0] = 50;
    vis[50][50] = true;
    visn[0] = true;
    P[0] = 0;

    while (!Q.empty()) {
        int q = Q.front(); Q.pop();

        for (int i = 0; i < G[q].size(); i++) {
            int nq = G[q][i];

            if (!visn[nq]) {
                visn[nq] = 1;
                Q.push(nq);

                bool ok = 0;
                for (int j = 0; j < 4 && !ok; j++) {
                    int nd = (P[q] + dd[j])%4;
                    int nx = X[q] + dx[nd];
                    int ny = Y[q] + dy[nd];

                    if (!vis[nx][ny]) {
                        vis[nx][ny] = true;
                        X[nq] = nx;
                        Y[nq] = ny;
                        ok = true;
                        P[nq] = nd;
                    }
                }

                if (!ok) return false;
            }
        }
    }

    return true;
}

int main(int nargs, char **args) {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        u--; v--;

        G[u].pb(v);
        G[v].pb(u);
    }

    if (bfs()) {
        cout << "YES" << endl;

        for (int i = 0; i < n; i++) {
            cout << X[i] << " " << Y[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
