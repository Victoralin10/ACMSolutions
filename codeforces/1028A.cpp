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

const int N = 2e2 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

char M[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    REP(i, n) cin>>M[i];

    int r[] = {1000, -1}, c[] = {1000, -1};
    REP(i, n) REP(j, m) {
        if (M[i][j] == 'B') {
            r[0] = min(r[0], i);
            r[1] = max(r[1], i);
            c[0] = min(c[0], j);
            c[1] = max(c[1], j);
        }
    }

    cout << ((r[0] + r[1])/2 + 1)<< " " << ((c[0] + c[1])/2 + 1) << endl;

    return 0 ;
}
