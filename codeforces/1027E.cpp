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

const int N = 5e2 + 2 ;
const int INF = 1e9 + 7 ;
const int MOD = 998244353;
const double EPS = 1e-8 ;

/************************************/

int memo[N][N][2];

int dp(int t, int cnt, bool prev) {
    if (cnt == 0) return 0;
    if (t == 0) return 1;

    int &ans = memo[t][cnt][prev];
    if (ans == -1) {
        ans = dp(t - 1, cnt, !prev);
        ans += dp(t - 1, cnt - 1, prev);
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    CLR(memo, -1);

    int ans = 0;
    Long aux;
    FOR(i, 1, n+1) {
        FOR (j, 1, n+1) {
            if (i*j >= k) {
                break;
            }
            aux = (dp(n-1, i, 0) - dp(n - 1, i-1, 0) + MOD)%MOD;
            aux *= (dp(n - 1, j, 0) - dp(n-1, j-1, 0) + MOD)%MOD;
            ans = (ans + 2*aux)%MOD;
        }
    }
    cout << ans << endl;

    return 0 ;
}
