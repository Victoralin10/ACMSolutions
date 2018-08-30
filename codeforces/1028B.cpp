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

char A[N], B[N];

int main() {
    int n, m, l;
    cin >> n >> m;

    l = 1e3;

    A[0] = B[0] = '5';
    FOR(i, 1, l) A[i] = '4', B[i] = '5';
    A[l] = B[l] = 0;
    
    reverse(B, B + l);
    reverse(A, A + l);

    cout << A << endl << B << endl;

    return 0 ;
}
