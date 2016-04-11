/**
* Title:            D. Number of Parallelograms
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 2003

using namespace std;

int x[MAXN], y[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    map <long long, int > mp;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            long long cx = x[i] + x[j];
            long long cy = y[i] + y[j];
            mp[cx*2000000001 + cy]++;
        }
    }

    int ans = 0;
    map <long long, int >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        int cnt = it->second;
        ans += (cnt*(cnt - 1))/2;
    }

    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
