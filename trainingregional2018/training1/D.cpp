#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)
#define endl "\n"

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

int main() {
    //fast_io();
    int tc;
    sc(tc);
    REP (itc, tc) {
    int n;
        sc(n);
        vector<int> v(n + 1);
        int res = 0;
        REP( i, n) {
            sc(v[i]);
            res = res ^ v[i];
        }
        int p = 31 - (int)(__builtin_clz(res));
        int ans = 0;
        if (res != 0 && p >= 0) {
            REP (i, n) {
                if (v[i] & (1<<p)) {
                    ans++;
                }
            }
        }
        printf("Case %d: %d\n", itc + 1, ans);
    }
    
    return 0 ;
}
