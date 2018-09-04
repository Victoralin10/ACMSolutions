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
int v[N];
map<int, int> f;
int main() {
    fast_io();
    int tc;
    sc(tc);
    REP (itc, tc) {
        int n;
        sc(n);
        bool there_are_2_equal = 0;
        f.clear();
        Long ans = 0;
        REP (i, n) {
            int x;
            sc(x);
            v[i] = x;

            int mf = 0;
            if (f.find(x) != f.end()) {
                mf = f[x];
            }
            if (mf > 0) there_are_2_equal = 1;
            ans += (i - mf);

            f[x]++;
        }

        ans += there_are_2_equal;
        printf("%d\n", ans);
    }
    return 0 ;
}
