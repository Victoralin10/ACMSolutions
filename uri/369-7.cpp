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

const int N = int(1e3) + 1;
int X[N], Y[N], T[N];

int memo[N][N][8];

int dp(int px, int r, int mk) {
    if (px < 0) return 0;

    int &ans = memo[px][r][mk];
    if (ans == -1) {
        ans = dp(px - 1, r, mk);
        int nmk = mk|(1<<T[px]);
        if (__builtin_popcount(nmk) < 3 && r >= Y[px]) {
            ans = max(ans, X[px] + dp(px - 1, r - Y[px], nmk));
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    int n,r;
    char c;

    cin >> n >> r;
    REP(i, n) {
        cin >> X[i] >> c >> Y[i];
        if (c == 'G') T[i] = 2;
        if (c == 'C') T[i] = 1;
    }

    clr(memo, -1);
    cout << dp(n-1, r, 0) << endl;
    
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
