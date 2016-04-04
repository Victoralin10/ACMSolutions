/**
* Title:            D. MUH and Cube Walls
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 200005

using namespace std;

int A[MAXN], B[MAXN], K[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n, w;
    scanf("%d%d", &n, &w);

    n--; w--;
    int x, y;
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &y);
        A[i] = y - x;
        x = y;
    }

    scanf("%d", &x);
    for (int i = 0; i < w; i++) {
        scanf("%d", &y);
        B[i] = y - x;
        x = y;
    }

    if (w == 0) cout << n+1 << endl;
    else if (w > n) cout << 0 << endl;
    else {
        K[0] = -1;
        for (int i = 0, j = -1; i < w; ) {
            while (j != -1 && B[i] != B[j]) j = K[j];
            K[++i] = ++j;
        }

        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j != -1 && A[i] != B[j]) j = K[j];
            j++;
            if (j == w) {
                ans++;
                j = K[j];
            }
        }

        cout << ans << endl;
    }




    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
