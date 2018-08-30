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

/************************************/

int main() {
    int k;
    Long n, a, p;
    cin>>n>>k;
    Long ans = -1, t, c;
    REP(i,k) {
        cin>>a;
        p = n - (n%a);
        if (p > ans) {
            ans = p;
            t = i+1;
            c = p/a;
        }
    }
    cout << t << " " << c << endl;

    return 0 ;
}
