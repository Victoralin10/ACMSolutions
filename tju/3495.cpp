/**
* Title:            3495.   A Simple Game
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 30004

using namespace std;

int A[MAXN];

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    int n, t, caso = 1;
    while (scanf("%d%d", &n, &t) != EOF) {
        if (n + t == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);

        int num = 0, lo, hi, mid;
        for (int i = 0; i < n; i++) {
            lo = 0, hi = n-1;
            if (A[i] > 0) {
                if (A[i]*A[0] > t) {
                    num += n;
                } else if (A[i]*A[n-1] > t) {
                    while (hi - lo > 1) {
                        mid = (hi + lo) / 2;
                        if (A[i]*A[mid] > t) hi = mid;
                        else lo = mid;
                    }
                    num += n - hi;
                }
            } else if (A[i] < 0) {
                if (A[i]*A[n-1] > t) {
                    num += n;
                } else if (A[i]*A[0] > t) {
                    while (hi - lo > 1) {
                        mid = (hi + lo) / 2;
                        if (A[i]*A[mid] > t) lo = mid;
                        else hi = mid;
                    }
                    num += hi;
                }
            } else if (t < 0) {
                num += n;
            }
        }

        int g = __gcd(num, n*n);
        printf("Case %d: %d/%d\n", caso++, num/g, (n*n)/g);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
