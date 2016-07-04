/**
* Title:            Kangaroo
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    int num = x1 - x2, den = v2 - v1;
    bool ok;
    if (den == 0) {
        ok = (num == 0);
    } else {
        ok = (num%den == 0) && (num/den > 0);
    }

    cout << (ok?"YES":"NO") << endl;


    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
