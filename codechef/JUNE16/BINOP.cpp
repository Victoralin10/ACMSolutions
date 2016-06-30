/**
* Title:            Chef And Binary Operation
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int t;
    cin >> t;

    string a, b;
    while (t--) {
        cin >> a >> b;

        long long c1[] = {0, 0}, c2[] = {0, 0};
        for (int i = 0; i < a.size(); i++) {
            c1[a[i] - '0']++;
            c2[b[i] - '0']++;
        }

        if (c1[0]*c1[1] == 0 && ((c1[0] == 0 && c2[0] > 0) || (c1[1] == 0 && c2[1] > 0))) {
            cout << "Unlucky Chef" << endl;
        } else {
            int ans = 0, cnt[] = {0, 0};
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i]) continue;
                if (cnt[a[i] - '0'] > 0) {
                    cnt[a[i] - '0']--;
                } else {
                    ans++;
                    cnt[1 - (a[i] - '0')]++;
                }
            }

            cout << "Lucky Chef" << endl << ans << endl;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
