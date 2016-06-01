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
    int n, k;
    cin >> n >> k;

    string line;
    cin >> line;

    int ans = 0;
    for (int i = 0, pa = 0, ca = 0, pb = 0, cb = 0; i < n; i++) {
        while (pa < n && ca <= k) {
            ca += (line[pa] == 'a');
            pa++;
        }
        while (pb < n && cb <= k) {
            cb += (line[pb] == 'b');
            pb++;
        }
        ans = max(ans, pa - i - (ca > k));
        ans = max(ans, pb - i - (cb > k));
        ca -= line[i] == 'a';
        cb -= line[i] == 'b';
    }

    cout << ans << endl;
    
    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
