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

int C[102], F[102];

bool vis[102];

int dfs(int node) {
    if (vis[node]) return 0;
    vis[node] = 1;
    return 1 + dfs(F[node]);
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n;
    cin >> n;
    for (int i = 1, f; i <= n; i++) {
        cin >> f;
        F[i] = f;
        C[f]++;
    }

    bool ok = 1;
    for (int i = 1; i <= n && ok; i++) {
        if (C[i] != 1) {
            ok = 0;
        }
    }

    if (!ok) {
        puts("-1");
        return 0;
    }

    Long t = 1;
    for (int i = 1, l; i <= n; i++) {
        if (!vis[i]) {
            l = dfs(i);
            if (!(l&1)) {
                l >>= 1;
            }
            t = (t*l)/__gcd(t, (long long)l);
        }
    }

    cout << t << endl;


    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
