/**
* Title:            Match the Shoes
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MAXN 50004

using namespace std;

int N[MAXN];

pair <int, int> F[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int k, m, n;
    cin >> k >> m >> n;

    for (int i = 0;i < m;i++) {
        F[i].second = i;
    }

    for (int i = 0, id;i < n;i++) {
        cin >> id;
        F[id].first--;
    }

    sort(F, F + m);

    for (int i = 0;i < k; i++) {
        cout << F[i].second << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
