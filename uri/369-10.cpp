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

int f(int n) {
    int ans = 0;
    while (n) {
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int F[200];
int P[10][11];
int DP[10][N];

int main() {
    string b, e;
    cin >> b >> e;

    REP(i, 10) F[i] = i;
    FOR(i, 10, 200) F[i] = F[f(i)];

    FOR (i, 1, 10) {
        P[i][0] = 1;
        FOR(j, 1, 11) {
            P[i][j] = F[i*P[i][j-1]];
        }
    }

    REP(i, 10) {
        DP[i][0] = i;
    }
    FOR(j, 1, N) {
        FOR(i, 1, 10) {
            DP[i][j] = F[P[DP[i][j-1]][10]];
        }
    }

    int s1 = 0;
    REP(i, SZ(b)) s1 += b[i] - '0';
    while (s1 > 9) s1 = f(s1);

    reverse(ALL(e));

    int ans = 1;
    REP(i, SZ(e)) {
        ans = F[ans*DP[P[s1][e[i]-'0']][i]];
    }
    cout << ans << endl;


    return 0 ;
}
