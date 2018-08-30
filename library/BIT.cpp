#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

const int N = 1e5 + 2;

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

struct BIT {
    Long B[N];
    int n;
    BIT(int n) {
        this->n = n + 1;
        memset(B, 0, sizeof B);
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

int main(int nargs, char **args) {
    BIT bit(100);
    bit.add(99, 10);

    TEST(bit.query(99));
    TEST(bit.query(0, 99));
    TEST(bit.query(98));
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
