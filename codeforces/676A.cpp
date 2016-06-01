/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n, p1, p2;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            p1 = i;
        } else if (x == n) {
            p2 = i;
        }
    }

    if (p1 > p2) swap(p1, p2);

    cout << max(p2 - 1, n - p1) << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
