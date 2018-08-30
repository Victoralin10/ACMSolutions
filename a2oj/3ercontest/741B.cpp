#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

const int N = (int)1e3 + 3;

int n, m, w;
int W[N], B[N];
vInt G[N];

bool vis[N];
int O[N], C[N], cnt = 0;

void dfs(int node, int c) {
    if (vis[node]) return;
    vis[node] = 1;
    C[cnt] = c;
    O[cnt++] = node;
    for (int i: G[node]) {
        dfs(i, c);
    }
}

int memo[N][N];

int dp(int p, int wa) {
    if (p == n) {
        return 0;
    }

    int &dx = memo[p][wa];
    if (dx == -1) {
        int px = p, sw = 0, sb = 0;
        while (px < n && C[px] == C[p]){
            sw += W[O[px]];
            sb += B[O[px]];
            px++;
        }
        dx = dp(px, wa);
        for (int i = p; i < px; i++) {
            if (wa + W[O[i]] <= w) {
                dx = max(dx, B[O[i]] +  dp(px, wa + W[O[i]]));
            }
        }
        if (wa + sw <= w) {
            dx = max(dx, sb + dp(px, wa + sw));
        }
    }
    return dx;
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1, c = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, c++);
        }
    }

    clr(memo, -1);
    
    cout << max(dp(0, 0), 0) << endl;

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
