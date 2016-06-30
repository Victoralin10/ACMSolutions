/**
* Title:            Devu and an Array
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();    

    int n, q, mn = (1<<30), mx = 0;
    cin >> n >> q;
    while (n--) {
        int ai;
        cin >> ai;
        mn = min(mn, ai);
        mx = max(mx, ai);
    }

    while (q--) {
        int t;
        cin >> t;
        puts((t >= mn && t <= mx)?"Yes":"No");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
