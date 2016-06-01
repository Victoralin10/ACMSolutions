/**
* Title:            Better Maximal Sum
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

long long A[MAXN], D1[MAXN], D2[MAXN];
int t, n;

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
   
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &A[i]);
        }

        D1[0] = A[0];
        for (int i = 1; i <= n; i++) {
            D1[i] = max(D1[i-1] + A[i], A[i]);
        }

        D2[n-1] = A[n-1];
        for (int i = n-2; i >= 0; i--) {
            D2[i] = max(D2[i+1] + A[i], A[i]);
        }

        long long ans = -(1LL<<60);
        ans = max(D2[0], D1[n-1]);

        for (int i = 0; i < n; i++) {
            long long ml;
            if (i == 0) {
                ml = D2[i+1];
            } else if (i+1 == n) {
                ml = D1[i-1];
            } else {
                long long mi = (i>0?D1[i-1]:0);
                long long md = (i+1<n?D2[i+1]:0);
                ml = max(mi, md);
                ml = max(ml, mi + md);
            }

            ans = max(ans, ml);
            // ans = max(ans, D1[i]);
        }
        
        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
