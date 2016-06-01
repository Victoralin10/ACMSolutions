/**
* Title:            (Voice Alerts)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    double V, T;
    int n;
    
    cin >> V >> T;
    cin >> n;

    int ians;
    double dans = (1LL<<50);
    for (int i = 1; i<= n; i++) {
        double x, t;
        cin >> x >> t;
        if (x + V*(T + t) < dans) {
            dans = x + V*(T + t);
            ians = i;
        }
    }

    printf("%.5f %d\n", dans, ians);


    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
