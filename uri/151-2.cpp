/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MAXN 1003

using namespace std;

int C[MAXN], A[MAXN];

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n, ncaso = 0;
    while (cin >> n) {
        if (n == 0) break;

        cout << "Turma " << ++ncaso << endl;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> C[i] >> A[i];
            mx = max(mx, A[i]);
        }

        for (int i = 0; i < n; i++) {
            if (mx == A[i]) {
                cout << C[i] << " ";
            }
        }
        
        cout << endl << endl;
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
