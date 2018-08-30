#include <bits/stdc++.h>

using namespace std;

#define MAXN 250005

int A[MAXN], pd[MAXN];

int main() {
    int n, q, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    pd[0] = -1;
    for (int i = 1; i < n; i++) {
        pd[i] = (A[i] > A[i-1]?i-1:pd[i-1]);
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--; r--;

        if (pd[r] < l) puts("0");
        else cout << r - pd[r] + 1 << endl;
    }
}