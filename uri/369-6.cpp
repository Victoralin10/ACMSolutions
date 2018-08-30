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

const int N = 3e5 + 5e3 + 5;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/
int A[N];

int main() {
    int n, x, m;
    while (sc(n) != EOF) {
        map <int, int> mp;
        REP(i, n) sc(A[i]);
        sc(m);
        int mn, cs = 2;
        REP(i, n) if (A[i] == m) {
            mn = i+1;
            break;
        }
        while (mn > cs && mn%cs != 0) {
            mn -= mn/cs;
            cs++;
        }
        puts((mn%cs>0)?"Y":"N");
    }

    return 0 ;
}
