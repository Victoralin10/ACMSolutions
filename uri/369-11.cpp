#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)

using namespace std ;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/

struct Node {
    int up, down, parent, ord, cnt, h;
    set <Pair> st;
} Tree[N];

int n, T[4*N], HL[N];
vector <int> G[N];

int dfs(int node, int parent, int h = 0) {
    Node &cnode = Tree[node];
    cnode.h = h;
    cnode.parent = parent;
    cnode.down = 0;
    for (int &v: G[node]) {
        if (v == parent) continue;
        cnode.st.insert({dfs(v, node, h+1), v});
    }

    if (cnode.st.size() == 0) return 0;
    return cnode.st.rbegin()->first;
}

void dfs2(int node, int parent, int bup) {
    Node &cnode = Tree[node];
    cnode.up = bup;
    auto it = cnode.st.rbegin();
    for (int &v: G[node]) {
        if (v == parent) continue;
        if (it != cnode.st.rend() && it->second == v) it++;
        if (it == cnode.st.rend()) {
            dfs2(v, node, bup + 1);
        } else {
            dfs2(v, node, max(bup, it->first) + 1);
            Tree[v].down = it->first;
        }
    }
}

int dfs3(int node, int parent) {
    int ans = 1;
    for (int &v: G[node]) {
        if (v == parent) continue;
        ans += dfs(v, node);
    }
    Tree[node].cnt = ans;
    return ans;
}

int LCA[N][17];
// LCA
void initLca() {
    REP(i, n) {
        LCA[i][0] = Tree[i].parent;
    }
    FOR(j, 1, 17)
        REP(i, n)
            LCA[i][j] = LCA[LCA[i][j-1]][j-1];
}

int lca(int u, int v) {
    if (Tree[u].h < Tree[v].h) swap(u, v);
    for (int i = 16; i >= 0; i--)
        if (LCA[u][i] != -1 && Tree[LCA[u][i]].h >= Tree[v].h) 
            u = LCA[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--)
        if (LCA[u][i] != LCA[v][i])
            u = LCA[u][i], v = LCA[v][i];
    return LCA[u][0];
}

// Segment Tree
void initST(int node, int i, int j) {
    
}

int query(int node, int i, int j, int a, int b) {

}
// End Segment Tree

int solve(int u, int v) {

}

int main() {
    int t, q, u, v;
    sc(t);
    while (t--) {
        sc(n);
        REP(i, n) {
            Tree[i].st.clear();
            G[i].clear();
        }

        REP(i, n) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1, 0);
        dfs3(0, -1);


        CLR(T, 0);
        // init(0, 0, n-1);

        sc(q);
        while (q--) {
            scanf("%d%d", &u, &v);
            printf("%d\n", solve(u, v));
        }
    }
    return 0 ;
}
