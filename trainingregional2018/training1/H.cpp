#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)

using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

/************************************/

void smod(int &a, int v) {
    a += v;
    if (a>= MOD) a -= MOD;
}

vector<Pair> G[N];
int A[N], C[N], S[N], SS[N];

void pre(int node, int parent, int w) {
    C[node] = 1;
    for (auto &p: G[node]) {
        if (p.first == parent) continue;
        pre(p.first, node, p.second);
        C[node] += C[p.first];
    }
    S[node] = ((Long)w*C[node])%MOD;
    SS[node] = S[node];
    for (auto &p: G[node]) {
        if (p.first == parent) continue;
        smod(SS[node], SS[p.first]);
    }
}


void solve(int node, int parent) {
    A[node] = 0;

    for (auto &p: G[node]) {
        if (p.first == parent) continue;
        solve(p.first, node);
        smod(A[node], A[p.first]);
        smod(A[node], ((Long)SS[p.first]*(C[node] - C[p.first])) % MOD);
    }
}


int main() {
    fast_io();
    int t, n=0, u, v, w;
    cin>>t;
    REP(caso, t) {
        REP(i,n+1) G[i].clear();
        cin>>n;
        FOR(i,1,n) {
            cin>>u>>v>>w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }

        pre(1, -1, 0);
        solve(1, -1);

        int ans=0;
        REP(i,n) {
            smod(ans, A[i+1]);
            //cerr<<A[i+1]<<" ";
        }
        //cerr<<endl;
        cout << "Case "<<caso+1<<": "<<ans<<endl;
    }

    return 0 ;
}
