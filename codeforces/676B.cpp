/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    int n, t;
    cin >> n >> t;

    double C[11][11];
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            C[i][j] = 0;
        }
    }

    C[0][0] = t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (C[i][j] > 1) {
                double sob = C[i][j] - 1;
                C[i][j] = 1;
                C[i + 1][j] += sob/2.0;
                C[i + 1][j + 1] += sob/2.0;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ans += (C[i][j] == 1);
        }
    }

    cout << ans << endl;
    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
