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
    clock_t _inicio = clock();

    int n, ncaso = 0;
    while (cin >> n) {
        if (n == 0) break;
        cout << "Teste " << ++ncaso << endl;

        int a, b, dif = 0;
        while (n--) {
            cin >> a >> b;
            dif += a - b;
            cout << dif << endl;
        }
        cout << endl;
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
