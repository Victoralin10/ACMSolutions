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

const int N = 1e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

struct BIT {
    Long B[N];
    int n;
    BIT(int n) {
        this->n = n + 1;
        CLR(B, 0);
    }

    void add(int px, Long val) {
        px++;
        while (px <= n) {
            B[px] += val;
            px += px&(-px);
        }
    }

    Long query(int px) {
        px++;
        if (px > n) px = n;
        Long ans = 0;
        while (px > 0) {
            ans += B[px];
            px -= px&(-px);
        }
        return ans;
    }

    Long query(int a, int b) {
        return query(b) - query(a - 1);
    }
};

int main() {
    int n, m, t, a, b, c, d, x, y;
    scanf("%d%d", &n, &m);
    Long ans;
    BIT bit(n + 1);
    while (m--) {
        sc(t);
        if (t == 1) {
            scanf("%d%d", &x, &y);
            bit.add(x, y);
        } else {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (a > c) {
                swap(a, c);
                swap(b, d);
            }
            if (b < c) {
                ans = bit.query(a, b) + bit.query(c, d);
            } else if (d <= b) {
                ans = bit.query(a, b);
            } else {
                ans = bit.query(a, d);
            }
            printf("%d\n", (int)ans);
        }
    }
    return 0 ;
}
