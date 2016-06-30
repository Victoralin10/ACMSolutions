/**
* Title:            Art
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

int N[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> N[i];
        }

        bool ok = false;
        for (int i = 2; i < n && !ok; i++) {
            ok = (N[i] == N[i-1] && N[i-1] == N[i-2]);
        }

        puts(ok?"Yes":"No");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
