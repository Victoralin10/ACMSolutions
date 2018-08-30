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

int main() {
    clock_t _inicio = clock();
    for (int m = 1; m < 305000; m++) {
        int mn = m, cs = 2;
        while (mn > cs && mn%cs != 0) {
            mn -= mn/cs;
            cs++;
        }
        if ((mn%cs)>0) cout << m << " " << cs << endl;
    }
    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0 ;
}
