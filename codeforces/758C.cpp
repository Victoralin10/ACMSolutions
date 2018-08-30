#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define ll long long

using namespace std;


int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n, m, x, y;
    ll k, r1, r2, r3;
    cin >> n >> m >> k >> x >> y;

    ll tgr, gr;
    if (n == 1) {
        tgr = m;
        gr = k/tgr;
        k = k%tgr;

        r1 = r2 = r3 = gr;
        if (k > 0) r1++;
        if (k >= y) r3++;
    } else if (n == 2) {
        tgr = n*m;
        gr = k/tgr;

        k = k%tgr;

        r1 = gr;
        if (k > 0) r1++;

        r2 = gr;

        r3 = gr + (k >= (x - 1)*m + y);
    } else {
        tgr = (2*m*(n - 1));
        gr = k/tgr;

        r1 = 2*gr;
        r2 = gr;
        if (x == 1 || x == n) r3 = r2;
        else r3 = r1;

        k = k%tgr;

        if (gr > 0) {
            if (k > m) r1++;
            if (k > n*m) r1++;

            if (k >= n*m) r2++;

            if (k >= (x- 1)*m + y) r3++;
            if (x != n && k >= n*m + (n - x - 1)*m + y) r3++;
        } else {
            r1 = 1;
            if (k > n*m) r1++;

            r2 = 0;
            if (k >= n*m) r2++;

            r3 = (k >= (x - 1)*m  + y);
            if (x != n && k >= n*m + (n - x - 1)*m + y) r3++;
        }
    }


    cout << r1 << " " << r2 << " " << r3 << endl;

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
