/**
* Title:            7561 - Longest Palindrome
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

    while (t--) {
        int n, a = 0, b = 0, c = 0, d = 0;
        cin >> n;
        while (n--) {
            string par;
            cin >> par;
            if (par == "aa") a++;
            else if(par == "ab") b++;
            else if(par == "ba") c++;
            else d++;
        }

        string ans1 = "", ans2 = "";
        for (int i = a/2; i > 0; i--) {
            ans1 += "aa";
            ans2 += "aa";
        }
        a &= 1;

        b = min(b, c);
        while (b--) {
            ans1 += "ab";
            ans2 = "ba" + ans2;
        }

        for (int i = d/2; i > 0; i--) {
            ans1 += "bb";
            ans2 = "bb" + ans2;
        }
        d &= 1;

        if (a > 0) {
            ans1 += "aa";
        } else if (d > 0) {
            ans1 += "bb";
        }
        cout << ans1 << ans2 << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
