/**
* Title:            C. Hard Process
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300005

using namespace std;

int A[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n, k, ng = 0, b;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    A[n] = 1;

    int ans = 0, px;
    for (int i = 0, cnt = 0, j = 0; j <= n; j++) {
        cnt += !A[j];
        if (j - i > ans) {
            px = i;
            ans = j - i;
        }
        while (cnt > k) {
            cnt -= !A[i];
            i++;
        }
    }

    for (int i = 0; i < ans; i++) {
        A[px + i] = 1;
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
