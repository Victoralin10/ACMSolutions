#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

const int N = 1e3+3;
char M[N][N];
int U[N][N], D[N][N], L[N][N], R[N][N];

int main(int nargs, char **args) {
    int r, c;
    cin >> r >> c;
    REP(i, r) cin >> M[i];

    REP(j, c) {
        int lu = 1e8, ld = 1e8;
        REP(i, r) {
            if (M[i][j] == '@') lu = -1;
            U[i][j] = ++lu;
            if (M[r-i-1][j] == '@') ld = -1;
            D[r-i-1][j] = ++ld;
        }
    }
    REP(i, r) {
        int ll = 1e8, lr = 1e8;
        REP(j, c) {
            if (M[i][j] == '@') ll = -1;
            L[i][j] = ++ll;
            if (M[i][c-j-1] == '@') lr = -1;
            R[i][c-j-1] = ++lr;
        }
    }

    int ans = -1;
    bool ok = 1;
    REP(i, r) {
        REP(j, c) {
            int x = min(min(R[i][j], D[i][j]), min(L[i][j], U[i][j]));
            ans = max(ans, x);
            if (x > 10000) ok = 0;
        }
    }
    if (ok) cout << ans << endl;
    else puts("-1");

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
