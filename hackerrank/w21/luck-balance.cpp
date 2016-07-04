/**
* Title:            Luck Balance
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
    vector <int> v;

    int ans = 0;
    while(n--) {
        int l, t;
        cin >> l >> t;
        if (t == 0) {
            ans += l;
        } else {
            v.push_back(l);
        }
    }
    sort(v.rbegin(), v.rend());
    for (int i = min(k, (int)v.size()) - 1; i >= 0; i--) {
        ans += v[i];
    }

    for (int i = min(k, (int)v.size()); i < v.size(); i++) {
        ans -= v[i];
    }
    
    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
