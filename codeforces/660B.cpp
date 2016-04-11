/**
* Title:            B. Seating On Bus
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 101

using namespace std;

int ID[MAXN][4], A[4*MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ID[i][0] = 2*i + 1;
        ID[i][3] = 2*(i + 1);
        ID[i][1] = 2*(n + i) + 1;
        ID[i][2] = 2*(n + i + 1);
    }

    int ord[] = {1, 0, 2, 3};
    for (int i = 0; i < 4*n; i++) {
        A[i] = ID[i/4][ord[i%4]];
    }

    for (int i = 0, j = 0; i < 4*n; i++) {
        if (A[i] <= m) {
            A[j++] = A[i];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << A[i] << (i+1==m?"\n":" ");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
