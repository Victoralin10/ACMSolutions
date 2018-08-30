#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

int n, m;
vector <int> G[MAXN];
int D[MAXN][MAXN];
int DP[MAXN][MAXN], BEST[MAXN][MAXN];

void readGraph() {
    cin >> n >> m;
    memset(D, 63, sizeof D);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        D[u][v] = 1;
        D[v][u] = 1;
    }
}

void computeD() {
    for (int i = 1; i <= n; i++) {
        D[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            for (int k = 1; k <= n; k++) {
                if (k == j || k == i) continue;
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
            }
        }
    }
}

int dp(int cn, int b) {
    if (cn == b) return 0;
    if (DP[cn][b] != -1) return DP[cn][b];
    int &ret = DP[cn][b], best = -1;
    ret = (1<<30);
    for (int i = 0; i < (int)G[cn].size(); i++) {
        int nn = G[cn][i];
        if (nn == b) {
            BEST[cn][b] = b;
            return ret=1;
        }
        if (D[nn][b] >= D[cn][b]) continue;
        int mx = -1;
        for (int j = 0, nb; j <= (int)G[b].size(); j++) {
            nb = (j==(int)G[b].size()?b:G[b][j]);
            mx = max(mx, 2 + dp(nn, nb));
        }
        if (mx < ret) {
            ret = mx;
            best = nn;
        }
    }
    BEST[cn][b] = best;
    return ret;
}

void computeDp() {
    memset(DP, -1, sizeof DP);
}

int getFirst() {
    int ans = -1, b = (1<<30);
    for (int i = 1; i <= n; i++) {
        int mx = -1;
        for (int j = 1; j <= n; j++) {
            mx = max(mx, dp(i, j));
        }
        if (mx < b) {
            b = mx;
            ans = i;
        }
    }

    return ans;
}

int getNext(int cn, int b) {
    return BEST[cn][b];
}

int main() {
    readGraph();
    computeD();
    computeDp();

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << DP[1][i][j] << " ";
        }
        cout << endl;
        for (int j = 1; j <= n; j++) {
            cout << BEST[1][i][j] << " ";
        }
        cout << endl;
    }*/

    int cn = getFirst(), b;
    cout << cn << endl;
    do {
        cin >> b;
        if (cn == b) {
            cout << cn << endl;
            return 0;
        }

        cn = getNext(cn, b);
        cout << cn << endl;
        // exit(0);
    } while (cn != b);
    return 0;
}
