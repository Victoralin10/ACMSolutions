/**
* Title:            10139 - Factovisors
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define ui unsigned int

using namespace std;

ui count(ui f, ui p) {
    ui ans = 0;
    while (f) {
        f /= p;
        ans += f;
    }
    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    ui n, m;
    while (cin >> n >> m) {
        bool ok = true;
        ui cm = m;
        for (ui i = 2; i <= cm/i; i++) {
            int cnt = 0;
            while (cm%i == 0) {
                cm /= i;
                cnt++;
            }
            if (cnt > 0 && cnt > count(n, i)) {
                ok = false;
                break;
            }
        }
        if (cm > 1 && count(n, cm) < 1) {
            ok = false;
        }
        if (ok) printf("%d divides %d!\n", m, n);
        else printf("%d does not divide %d!\n", m, n);
    }


    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
