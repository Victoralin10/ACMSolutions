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
#define MAXN 1000006

using namespace std;

char a[MAXN], b[MAXN];
int l, fact[MAXN];
int inv[MAXN];

int fastpow(ll b, int e) {
    ll ans = 1;
    while (e) {
        if ((e&1)) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= l; i++) {
        fact[i] = ((long long)fact[i-1]*i) % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= l; i++) {
        inv[i] = fastpow(fact[i], MOD - 2);
    }
}

int c[26];
bool eq[MAXN];

int dp() {
    for (int i = 0; i < l && a[i] == b[i]; i++) {
        eq[i] = 1;
    }

    int ans = 0;
    for (int i = l-1; i >= 0; i--) {
        c[a[i] - 'a']++;
        int lm = 26;
        if (i == 0 || eq[i-1]) {
            lm = b[i] - 'a';
        }
        ll x = fact[l - i - 1];
        for (int k = 0; k < 26; k++) {
            if (!c[k]) continue;
            x = (x*inv[c[k]]) % MOD;
        }
        for (int j = a[i] - 'a' + 1; j < lm; j++) {
            if (c[j]) {
                ll nx = x*fact[c[j]] % MOD;
                nx = (nx*inv[c[j] - 1]) % MOD;
                ans = (ans + nx) % MOD;
            }
        }
    }

    for (int i = 1; i < l; i++) {
        if (!c[b[i-1] - 'a']) break;
        c[b[i-1] - 'a']--;
        if (eq[i-1]) continue;
        ll x = fact[l - i - 1];
        for (int k = 0; k < 26; k++) {
            if (!c[k]) continue;
            x = (x*inv[c[k]]) % MOD;
        }
        for (int j = b[i] - 'a' - 1; j >= 0; j--) {   
            if (c[j]) {
                ll nx = x*fact[c[j]] % MOD;
                nx = (nx*inv[c[j] - 1]) % MOD;
                ans = (ans + nx) % MOD;
            }
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    scanf("%s%s", &a, &b);
    l = strlen(a);

    pre();
    cout << dp() << endl;
    return 0;
}
