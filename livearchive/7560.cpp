/**
* Title:            7560 - Chota Mouse and his Birthday Cake
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t;
    cin >> t;

    while (t--) {
        int f, h, w;
        cin >> f >> h >> w;

        vector <int> pi;
        for (int i = 0, x; i < f; i++) {
            cin >> x;
            pi.push_back(x);
        }
        pi.push_back(0);
        pi.push_back(w);
        sort(pi.begin(), pi.end());
        f += 2;

        int mn = (1<<30);
        for (int i = 1; i < f; i++) {
            mn = min(mn, pi[i] - pi[i-1]);
        }

        cout << mn*h << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
