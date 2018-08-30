/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10000

using namespace std;

int main(int nargs, char **args) {
    clock_t _inicio = clock();
    
    int t, n, m;
    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &n, &m);

        int ans = 0;
        for (int i = 0, g; i < n; i++) {
            vector <int> V;
            for (int j = 0, x; j < m; j++) {
                scanf("%d", &x);
                V.push_back(x);
            }
            g = V[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                if (V[j] > g) g = V[j];
                else g = V[j] - 1;
            }

            ans ^= g;
        }
        
        puts(ans==0?"SECOND":"FIRST");
    }
    
    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
