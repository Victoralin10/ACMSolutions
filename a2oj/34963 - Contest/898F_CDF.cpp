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

char s[MAXN], sa[MAXN];
int l, H[MAXN], I[MAXN];

int fast_pow(ll b, int e) {
    ll ans = 1;
    for ( ; e; b=(b*b)%MOD, e>>=1) {
        if ((e&1)) ans = (ans*b)%MOD;
    }
    return ans;
}

int getNum(int i, int t) {
    int ans = (H[i] - H[i + t] + MOD)%MOD;
    ans = ((ll)ans*I[l - i - t]) % MOD;
    return ans;
}

int main(int nargs, char **args) {
    scanf("%s", s);
    l = strlen(s);

    for (int i = 0, p10 = 1; i <= l; i++) {
        I[i] = fast_pow(p10, MOD - 2);
        p10 = (p10*10LL) % MOD;
    }
    for (int i = l-1, p10 = 1; i >= 0; i--) {
        H[i] = (H[i+1] + (ll)(s[i] - '0')*p10)%MOD;
        p10 = (p10*10LL) % MOD;
    }
    int l1, l2;
    for (l1 = 1; l1 <= (l-1)>>1; l1++) {
        l2 = min((l - l1)/2, l - 2*l1);
        if ((l2 == 1 || (l2 > 1 && s[l1] != '0')) 
            && (getNum(0, l1) + getNum(l1, l2))%MOD == H[l1+l2]) {
            
            break;
        }
        if (l2 > 1) {
            l2--;
            if ((l2 == 1 || (l2 > 1 && s[l1] != '0')) 
                && (getNum(0, l1) + getNum(l1, l2))%MOD == H[l1+l2]) {
                
                break;
            }
        }
    }
    for (int i = 0, i2 = 0; i < l; i++) {
        if (i == l1) sa[i2++] = '+';
        if (i == l1 + l2) sa[i2++] = '=';
        sa[i2++] = s[i];
    }
    puts(sa);

    return 0;
}