/**
* Title:            D. Palindrome Degree
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000009
#define MAXN 5000006

using namespace std;

char s[MAXN];
int hash[MAXN], k[MAXN];

int getCode(char c) {
    if (c < 60) return c - 48;
    if (c < 93) return c - 65 + 10;
    return c - 97 + 36;
}

int fastpow(long long b, int e) {
    long long ans = 1;
    while (e) {
        if ((e&1)) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }

    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    scanf("%s", s);

    int l = strlen(s);
    long long pot = 1;
    long long inv = fastpow(62, MOD- 2);
    int rev = 0;
    long long ans = 1;

    k[0] = 1;
    hash[0] = getCode(s[0]);
    for (int i = 1; i < l; i++) {
        hash[i] = (hash[i-1]*62LL + getCode(s[i])) % MOD;

        if ((i&1) == 0) {
            rev = ((rev + MOD - getCode(s[i>>1]))*inv) % MOD;
        }
        rev = (rev + pot*getCode(s[i])) % MOD;
        if (rev == hash[(i-1)>>1]) {
            k[i] = k[(i-1)>>1] + 1;
            ans += k[i];
        } else {
            k[i] = 0;
        }

        if ((i&1) == 0) {
            pot = (pot*62LL) % MOD;
        }
    }

    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
