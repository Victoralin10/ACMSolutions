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

const int N = 7e2 + 2 ;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/

int A[N];
bool ok[N][N];
bool dpr[N][N], dpl[N][N];

bool solve_case() {
    int n;
    if (!(cin >> n)) return false;

    CLR(dpr, 0);
    CLR(dpl, 0);
    CLR(ok, 0);

    REP(i, n) cin>>A[i];

    REP(i, n) {
        FOR(j, i+1, n)  if(__gcd(A[i], A[j]) > 1) {
            ok[i][j] = 1;
            ok[j][i] = 1;
        }

        if (i < n-1) dpr[i][i] = ok[i][i+1];
        if (i) dpl[i][i] = ok[i-1][i];
    }

    FOR(d, 1, n-1) {
        for (int j = d, i; j < n; j++) {
            i = j - d;
            for (int mid = i; mid <= j; mid++) {
                bool check = (mid>i?dpr[i][mid-1]:1) && (mid<j?dpl[mid+1][j]:1);
                if (!check) continue;

                if (j < n-1 && ok[mid][j+1]) dpr[i][j] = 1;
                if (i > 0 && ok[i-1][mid]) dpl[i][j] = 1;
            }
        }
    }

    REP(i, n) {
        if ((i>0?dpr[0][i-1]:1) && (i+1<=n-1?dpl[i+1][n-1]:1)) {
            puts("Yes");
            return true;
        }
    }

    puts("No");
    return true;
}

int main() {
    while (solve_case());
}