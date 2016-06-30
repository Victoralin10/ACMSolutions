/**
* Title:            Chef and Coins Game
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>

using namespace std;

int main(int nargs, char **args) {
    // clock_t _inicio = clock();   
    
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        puts(n%6==0?"Misha":"Chef");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
