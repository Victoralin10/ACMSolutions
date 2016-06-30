/**
* Title:            Easy GCD
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n, k;
    cin >> n >> k;

    int gcd = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        gcd = __gcd(gcd, x);
    }

    int div = gcd;
    for (int i = 2; i*i <= gcd; i++) {
        if (gcd%i == 0) {
            div = i;
            break;
        }
    }

    cout << div*(k/div) << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
