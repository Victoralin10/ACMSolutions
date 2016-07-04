/**
* Title:            7363 - A Rational Sequence
* Author:           Josué Julcarima Calle
* Email:            josueajc@gmail.com
**/

#include <bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d", &x)
#define FN(i,x) for (int (i) = 0; (i) < (x) ; ++(i))

using namespace std;

int main() {
    int tc;
    sc(tc);
    FN (itc, tc) {
        int k;
        sc(k);
        cout << k << " ";
        int a, b;
        scanf("%d/%d", &a, &b);
        vector<bool> dec;
        while (a != 1 || b != 1) {
            bool isl = 1;
            if (a > b) {
                isl = 0;
            }
            dec.pb(isl);
            int p, q;
            if (isl) {
                p = a;
                q = b - a;
            } else {
                p = a - b;
                q = b;
            }
            a = p;
            b = q;
        }
        int ini = 1;
        reverse(dec.begin(), dec.end());
        FN (i, (int)dec.size()) {
            ini <<= 1;
            if (!dec[i]) {
                ini ++;
            }
        }
        cout << ini << endl;
    }
}
