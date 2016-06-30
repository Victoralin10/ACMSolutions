/**
* Title:            Sharing Candies
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
    long long a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        long long g = __gcd(c, d);
        long long di = abs(a-b);
        cout << min(di%g, g - di%g) << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
