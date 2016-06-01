/**
* Title:            (Non-Divisible Subset)
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

    vector <int> rests(k, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rests[x%k]++;
    }
    
    int ans = 0;

    ans += (rests[0] > 0);
    if (k%2 == 0) {
        ans += (rests[k/2] > 0);
    }

    for (int i = ((k-1)/2); i > 0; i--) {
        ans += max(rests[i], rests[k - i]);
    }
    
    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
