/**
* Title:            Points On a Line
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

    set <int> st1, st2;

    while (n--) {
        int x, y;
        cin >> x >> y;
        st1.insert(x);
        st2.insert(y);
    }

    puts(st1.size()==1||st2.size()==1?"YES":"NO");

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
