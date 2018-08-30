/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int f(int k, int b) {
    int po = 0, pb = 1;
    while (pb <= k) {
        pb *= b;
        po++;
    }

    int ans = 0;
    int cnt = -1, pt = 1;
    while (k) {
        int d = k%b;
        k /= b;
        ans += d*pt;
        pt++;
    }

    return ans + cnt;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;

        for (int i = 2; i <= 10; i++) {
            cout << i << ": " << f(k, i) << endl;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
