#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 10

using namespace std;

int main(int nargs, char **args) {
    int t, ch, cm, wh, wm;
    cin >> t;
    for (int caso = 1, ans; caso <= t; caso++) {
        cin >> ch >> cm >> wh >> wm;

        ans = wh*60 + wm - ch*60 - cm;
        
        if (ans < 0) {
            ans += 24*60;
        }

        printf("Case %d: %d\n", caso, ans);
    }
    return 0;
}
