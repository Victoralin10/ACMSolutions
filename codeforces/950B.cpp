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

int A[N], B[N];

int main() {
    int n, m;
    cin >>n>>m;
    REP(i, n) sc(A[i]);
    REP(i, m) sc(B[i]);

    int ans = 0;
    for (int i = 0, j = 0, s1 = 0, s2 = 0; i < n && j < m; ) {
        do {
            if (s1 < s2) s1 += A[i++];
            else s2 += B[j++];
        } while(s1 != s2);
        ans++;
        s1 = s2 = 0;
    }
    cout << ans <<endl;
    return 0 ;
}
