/**
* Title:            A. Co-prime Array
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int primes[] = {999999937, 999999929, 999999893};

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    vector <int> ans;
    int n, a, b, k = 0;
    cin >> n >> a;
    n--;
    ans.push_back(a);
    while (n--) {
        cin >> b;
        if (__gcd(a, b) != 1) {
            k++;
            for (int i = 0; i < 3; i++) {
                if (__gcd(primes[i], a) == 1 && 1 == __gcd(primes[i], b)) {
                    ans.push_back(primes[i]);
                    break;
                }
            }
        }
        ans.push_back(b);
        a = b;
    }

    cout << k << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i+1==ans.size()?"\n":" ");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
