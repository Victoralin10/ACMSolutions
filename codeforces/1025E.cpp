#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)
#define fi first
#define se second

using namespace std ;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 52;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/

int n, T[N][N];
Pair S[N], D[N];

bool vis[N][N];
int M[N][N];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool isValid(int r, int c) {
    return r > 0 && c > 0 && r <= n && c <= n;
}

vector <int> bfs(int r0, int c0, int r1, int c1) {
    vector <int> ans;
    if (r0 == r1 && c1 == c0) return ans;

    queue <Pair> Q;
    Q.push({r0, c0});

    CLR(vis, 0);
    vis[r0][c0] = 1;
    bool ok = 0;
    while (!Q.empty() && !ok) {
        Pair q = Q.front(); Q.pop();
        REP(i, 4) {
            int nr = q.first + dr[i];
            int nc = q.second + dc[i];
            if (isValid(nr, nc) && T[nr][nc] == 0) {
                vis[nr][nc] = 1;
                M[nr][nc] = i;
                Q.push({nr, nc});

                if (nr == r1 && nc == c1) {
                    ok = 1;
                    break;
                }
            }
        }
    }

    assert(ok);
    do {
        ans.push_back(M[r1][c1]);
        int mv = M[r1][c1];
        r1 -= dr[mv];
        c1 -= dc[mv];
    } while (r1 != r0 || c1 != c0);

    reverse(ALL(ans));
    return ans;
}

Pair fl() {
    FOR(i, 1, n+1)
        FOR (j, 1, n+1)
            if (T[i][j] == 0) {
                return {i, j};
            }
    return {-1, -1};
}

int main() {
    int r, c, m;
    cin >> n >> m;
    REP(i, m) {
        cin >> r >> c;
        S[i] = {r, c};
        T[r][c] = 1;
    }
    REP(i, m) cin >> D[i].first >> D[i].second;

    map <Pair, int> mp;
    queue <int> Q;

    REP(i, m) {
        if (S[i] != D[i] && T[D[i].fi][D[i].se] > 0) {
            mp[D[i]] = i;
        } else Q.push(i);
    }

    vector <pair <Pair, vInt> > ans;
    if (Q.empty()) {
        Pair flp = fl();
        ans.push_back({S[0], bfs(S[0].fi, S[0].se, flp.fi, flp.se)});
        T[S[0].fi][S[0].se] = 0;
        T[flp.fi][flp.se] = 1;
        S[0] = flp;
        Q.push(0);
        Q.push(mp[S[0]]);
    }

    while (!Q.empty()) {
        int q = Q.front(); Q.pop();
        ans.push_back({S[q], bfs(S[q].fi, S[q].se, D[q].fi, D[q].se)});
        T[S[q].fi][S[q].se] = 0;
        T[D[q].fi][D[q].se] = 1;
        if (mp.find(S[q]) != mp.end()) {
            Q.push(mp[S[q]]);
        }
    }

    int k = 0;
    for (auto &x: ans) {
        k += SZ(x.se);
    }
    cout << k << endl;
    for (auto &x: ans) {
        int r = x.fi.fi, c = x.fi.se, nr, nc;
        for (int d: x.se) {
            nr = r + dr[d];
            nc = c + dc[d];
            cout << r << " " << c << " " << nr << " " << nc << endl;
            r = nr;
            c = nc;
        }
    }


    return 0 ;
}
