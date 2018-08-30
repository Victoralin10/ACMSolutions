/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

int A[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n, k, i = 1, p;
    cin >> n >> k >> p;

    A[0] = 1;
    for ( ;i <= k; i++)  {
        A[i] = 1;
    }
    
    for (int cur = 2, mn = k + 1; i < n; i++) {
        while (100*mn < i*p) cur++, mn = i;
        A[i] = cur;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    cout << sum << endl << A[0];
    for (int i = 1; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
