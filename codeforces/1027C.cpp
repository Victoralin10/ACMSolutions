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

const int N = 1e4 + 4;

int main(int nargs, char **args) {
    int t, n, x, l1, l2;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        map <int, int> mp;
        REP(i, n) {
            scanf("%d", &x);
            mp[x]++;
        }

        bool ok = 0;
        for (auto &par: mp) {
            if (par.second >= 4) {
                ok = 1;
                l1 = par.first;
                break;
            }
        }

        if (ok) {
            printf("%d %d %d %d\n", l1, l1, l1, l1);
            continue;
        }

        long double ref = 1e10, a, b;
        int prev = -1;
        for (auto &par: mp) {
            if (par.second >= 2) {
                if (prev > 0) {
                    a = prev, b = par.first;
                    if (a/b + b/a < ref) {
                        ref = a/b + b/a;
                        l1 = prev;
                        l2 = par.first;
                    }
                }
                prev = par.first;
            }
        }
        printf("%d %d %d %d\n", l1, l1, l2, l2);
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
