/**
* Title:            Kitchen Timetable
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

        vector <int> A;
        for (int i = 0, a, prev = 0; i < n; i++) {
            cin >> a;
            A.push_back(a - prev);
            prev = a;
        }

        int ans = 0;
        for (int i = 0, b; i < n; i++) {
            cin >> b;
            ans += (b <= A[i]);
        }

        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
