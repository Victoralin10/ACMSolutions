/**
* Title:            Problem C. Coin Jam
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,
                47,53,59,61,67,71,73,79,83,89,97};
bool e[40];
int A[11], n;

bool isTrib(int b, int c) {
    int ac = 0;
    int pot = 1;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (pot > c) {
            ok = true;
            pot %= c;
        }
        ac += pot*e[i];
        if (ac > c) {
            ok = true;
            ac %= c;
        }
        pot = pot*b;
    }
    ac %= c;

    return ok && ac == 0;
}

bool isValid() {
    /*for (int k = n-1; k >= 0; k--) {
        cout << e[k]?'1':'0';
    }
    cout << endl;*/
    for (int i = 2; i <= 10; i++) {
        bool ok = false;
        for (int j = 0; j < 25; j++) {
            if (isTrib(i, primes[j])) {
                ok = true;
                A[i] = primes[j];
                break;
            }
        }
        if (!ok) return false;
    }

    return true;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, j;
    cin >> t >> n >> j;
    e[n] = 0;

    cout << "Case #1:" << endl;
    for (int i = 0, au;j > 0; i++) {
        e[0] = 1;
        au = i;
        for (int k = 1; k < n; k++) {
            e[k] = au&1;
            au >>= 1;
        }
        e[n-1] = 1;

        if (isValid()) {
            for (int k = n-1; k >= 0; k--) {
                cout << e[k]?'1':'0';
            }
            for (int k = 2; k <= 10; k++) {
                cout << " " << A[k];
            }
            cout << endl;
            j--;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
