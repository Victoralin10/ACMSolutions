/**
* Title:            7362 - Farey
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

#define N 10004

int phi[N], A[N];

void calc_phi() {
    for(int i = 1;i < N;i++) {
        phi[i] = i;
    }
    A[1] = 1;
    for(int i = 2;i < N;i++) {
        if(phi[i] == i){
            for(int j = i;j < N;j += i) {
                phi[j] /= i;
                phi[j] *= i-1;
            }
        }
        A[i] = phi[i] + A[i - 1];
    }
}



int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    calc_phi();

    int p, k, n;
    cin >> p;
    while (p--) {
        cin >> k >> n;
        cout << k << " " << 1 + A[n] << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
