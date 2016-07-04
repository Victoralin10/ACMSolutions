/**
* Title:            Lazy Sorting
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    vector <int> v;

    cin >> n;
    bool ok = true;
    for (int i = 0, x;i < n;i++) {
        cin >> x;
        v.push_back(x);
        if (i > 0 && v[i] < v[i-1]) {
            ok = false;
        }
    }

    double ans;
    if (ok) {
        ans = 0;
    } else {
        double f[30];
        f[0] = 1;
        for (int i = 1; i < 30; i++) {
            f[i] = f[i-1]*i;
        }

        sort(v.begin(), v.end());

        double cnt = 1;
        for (int i = 0, j = 0;i < n;) {
            while (j < n && v[j] == v[i]) j++;
            cnt *= f[j-i];
            i = j;
        }

        ans = f[n]/cnt;
    }


    printf("%.6lf\n", ans);

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
