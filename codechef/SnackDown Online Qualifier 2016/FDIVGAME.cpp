/**
* Title:            Floor Division Game
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000

using namespace std;

int grundy(long long a) {    
    int mult = 6;
    long long lim = 1;

    while (true) {
        if (mult == 2) {
            if (lim > a - lim) return 0;
        } else {
            if (lim > a - lim) return 1;
            if (lim > a/4.0) return 2;
            if (lim > a/6.0) return 3;
        }
        lim *= mult;
        if (mult == 2) mult = 6;
        else mult = 2;
    }   
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long a;
        cin >> n;

        int ans = 0;
        while (n--) {
            cin >> a;

            ans ^= grundy(a);
        }
        printf("%s\n", ans?"Henry":"Derek");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
