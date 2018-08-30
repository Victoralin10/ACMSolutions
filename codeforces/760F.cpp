#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 5003

using namespace std;

int l;
char A[MAXN];

int DP[MAXN][2];
int AC[MAXN][2];
int M[256];

int cmb[MAXN];

int fastpow(int b, int e) {
    int ans = 1;
    while (e) {
        if ((e&1)) ans = ((ll)ans*b) % MOD;
        e >>= 1;
        b = ((ll)b*b) % MOD;
    }

    return ans;
}

int main(int nargs, char **args) {
    cin >> l >> A;
    A[l++] = '$';

    cmb[0] = 1;
    for (int i = 1; i < l; i++) {
        cmb[i] = ((ll)cmb[i-1]*(l - i - 1) % MOD)*fastpow(i, MOD-2) % MOD;
    }

    for (int i = 1; i <= l; i++) {
        DP[i][1] = (M[A[i-1]] == 0);
        AC[i][1] = AC[i-1][1] + DP[i][1];

        M[A[i-1]] = i;
        
        // cout << DP[i][1] << " ";
    }
    // cout << endl;

    int ans = 0;
    for (int j = 2; j <= l; j++) {
        memset(M, 0, sizeof M);
        int ci = (j&1);
        for (int i = 1; i <= l; i++) {
            char c = A[i-1];

            DP[i][ci] = (AC[i-1][!ci] - AC[M[c]][!ci] + MOD) % MOD;
            AC[i][ci] = (AC[i-1][ci] + DP[i][ci]) % MOD;

            M[c] = i;

            // cout << DP[i][ci] << " ";
        }
        // cout << endl;

        ans = (ans + (ll)DP[l][ci]*cmb[j - 2]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
