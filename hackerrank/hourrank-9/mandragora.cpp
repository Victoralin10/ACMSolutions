/**
* Title:            Mandragora Forest
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <int> H;
        for (int i = 0, h; i < n; i++) {
            cin >> h;
            H.push_back(h);
        }

        sort(H.begin(), H.end());

        vector <long long> A(n + 1, 0);
        for (int i = n-1; i >= 0; i--) {
            A[i] = A[i+1] + H[i];
        }

        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, (1+i)*A[i]);
        }

        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
