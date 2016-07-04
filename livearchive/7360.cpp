/**
* Title:            7360 - Run Step
* Author:           Diego Mansilla
* Email:            dmansilla07@gmail.com
**/

#include <bits/stdc++.h>
#define kMod 1000000007
#define kMaxN 128

using namespace std;

typedef long long ll;

ll memo[kMaxN][kMaxN];

ll comb(int n, int k) {
    if (k == 0 || n == k) return 1;
    if (memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = comb(n-1, k-1) + comb(n-1, k);
}


int main(int nargs, char **args) {
    int T, K, S;
    cin>>T;
    memset(memo, -1, sizeof(memo));
    while (T--) {
        cin>>K>>S;
        ll ans = 0LL;
        S/=2;
        for(int S2 = 0; 2*S2<=S; ++S2) {
            int S1 =  S - 2*S2;
            if (S1 >= 0 && S1 <= S2) {
                ans += comb(S1+S2, S1)*comb(S1+S2, S2);
            }
        }
        cout << K << " " << ans << endl;
    }
    return 0;
}
