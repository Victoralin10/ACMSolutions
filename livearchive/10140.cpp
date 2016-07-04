/**
* Title:            10140 - Prime Distance
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define ui unsigned int
#define MAXN 1000006

using namespace std;
bool P[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    ui L, U;
    while (cin >> L >> U) {
        memset(P, true, sizeof P);

        if (L <= 1) P[0] = false;
        for (ui i = 2;i <= U/i;i++) {
            ui ini = i*((L + i - 1)/i);
            for (ui j = max(ini, 2*i);j <= U;j += i) {
                P[j - L] = false;
            }
        }

        ui ant = 0;
        ui mn = (1<<30), mx = 0;
        ui a1, a2, a3, a4;
        for (ui i = L; i <= U; i++) {
            if (!P[i - L]) continue;
            if (ant > 0) {
                if (i - ant < mn) {
                    mn = i - ant;
                    a1 = ant;
                    a2 = i;
                }
                if (i - ant > mx) {
                    mx = i - ant;
                    a3 = ant;
                    a4 = i;
                }
            }
            ant = i;
        }

        if (mx == 0) {
            cout << "There are no adjacent primes." << endl;
        } else {
            printf("%d,%d are closest, %d,%d are most distant.\n", a1, a2, a3, a4);
        }
    }


    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
