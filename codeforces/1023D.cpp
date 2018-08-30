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

const int N = 2e5 + 5;
int A[N];

struct BIT {
    Long B[N];
    int n;
    BIT(int n) {
        this->n = n + 1;
        clr(B, 0);
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

set <int> Px[N], ceros;

int main(int nargs, char **args) {
    int n, q;
    cin >> n >> q;
    REP(i, n) scanf("%d", A + i);

    BIT bit(n);
    REP(i, n) {
        Px[A[i]].insert(i);
        if (A[i] == 0) {
            bit.add(i, 1);
            ceros.insert(i);
        }
    }

    bool ok = 1, ocu = false;
    for (int i = q; i > 0; i--) {
        if (SZ(Px[i]) == 0 && !ocu) {
            if (SZ(ceros)) {
                auto it = ceros.rbegin();
                A[*it] = i;
                ceros.erase(*it);
                ocu = true;
                continue;
            } else {
                ok = 0;
                break;
            }
        }
        if (SZ(Px[i]) == 0 && ocu) {
            continue;
        }

        int mn = *Px[i].begin(), mx = *Px[i].rbegin();
        if (mx - mn + 1 != bit.query(mn, mx) + SZ(Px[i])) {
            ok = 0;
            break;
        }
        ocu = true;

        for (int px: Px[i]) {
            bit.add(px, 1);
        }

        vector <int> dls;
        for (auto it = ceros.lower_bound(mn); it != ceros.end() && *it < mx; it++) {
            dls.push_back(*it);
        }

        for (int dl: dls) {
            ceros.erase(dl);
            A[dl] = i;
        }
    }
    ok = (n == bit.query(0, n - 1));
    puts(ok?"YES":"NO");

    if (ok) {
        for (auto id: ceros) A[id] = 1;
        REP(i, n) {
            printf("%d%c", A[i], i+1==n?'\n':' ');
        }
    }

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
