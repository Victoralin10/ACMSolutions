#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

const int N = 2e5 + 5;
int n, C[N], A[N];
int vis[N], nv = 0;

int dfs(int room) {
    nv++;

    int cr = room;
    while (!vis[cr]) {
        vis[cr] = nv;
        cr = A[cr] - 1;
    }

    if (vis[cr] != nv) return 0;
    int ans = C[cr];
    for (int i = A[cr] - 1; i != cr; i = A[i] - 1) {
        ans = min(ans, C[i]);
    }

    return ans;
}

int main(int nargs, char **args) {
    cin >> n;
    REP(i, n) scanf("%d", C+i);
    REP(i, n) scanf("%d", A + i);

    int ans = 0;
    REP(i, n) if(!vis[i]) ans += dfs(i);
    cout << ans << endl;

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
