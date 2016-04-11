/**
* Title:            Problem A. Counting Sheep
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n;
    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        cin >> n;

        set <int> st;
        long long i;
        for (i = 1; i <= 100; i++) {
            long long b = n*i;
            while (b) {
                st.insert(b%10);
                b /= 10;
            }
            if (st.size() == 10) break;
        }

        if (st.size() == 10) {
            cout << "Case #" << caso << ": " << n*i << endl;
        } else {
            cout << "Case #" << caso << ": INSOMNIA" << endl;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
