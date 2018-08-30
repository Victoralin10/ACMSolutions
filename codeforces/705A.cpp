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

    int n;
    cin >> n;

    for (int i = 1;i < n;i++) {
        cout << "I " << (i&1?"hate":"love") << " that ";
    }
    cout << "I " << (n&1?"hate":"love") << " it" << endl;
    

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
