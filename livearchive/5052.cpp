/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 3003

using namespace std;

int A[MAXN], B[MAXN];

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int t;
    while (scanf("%d", &t) == 1) {
        if (t == 0) break;
        
        for (int i = 0, x; i < t; i++) {
            scanf("%d", &x);
            A[x] = i;
        }

        for (int i = 0, x; i < t; i++) {
            scanf("%d", &x);
            B[i] = x;
        }

        int ans = 0;
        for (int i = 0; i < t; i++) {
            int mn = A[B[i]], mx = mn;
            for (int j = i + 1, id; j < t; j++) {
                id = A[B[j]];
                mn = min(mn, id);
                mx = max(mx, id);

                if (mx - mn + 1 == j - i + 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
