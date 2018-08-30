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
    
    int n, x;
    cin >> n;
    long long ac = 0;
    for (int i = 0;i < n;i++) {
        cin >> x;
        ac += x - 1;
        cout << (ac&1?1:2) << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
