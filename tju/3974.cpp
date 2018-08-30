#include <bits/stdc++.h>

using namespace std;

int fastpow(int b, int e){
    int ans = 1;
    while (e) {
        if ((e&1) > 0) ans = ans*b % 100;
        e >>= 1;
        b = b*b % 100;
    }

    return ans;
}

int A[101];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i < 100; i++) {
            A[i] = fastpow(i, m);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += A[i%100];
        }

        ans = ans%100;
        if (ans < 10) {
            printf("0%d\n", ans);
        } else {
            printf("%d\n", ans);
        }
    }
    
    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
