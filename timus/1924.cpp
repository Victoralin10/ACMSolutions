/**
* Title:            1924. Four Imps
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    cin >> n;
    n = (n*(n+1))/2;
    puts((n&1)?"grimy":"black");

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
