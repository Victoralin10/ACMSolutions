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

pair <int, int> extended_GCD(int a, int b) {
    if(a % b == 0) return make_pair(0, 1);
    else {
        pair <int, int> P = extended_GCD(b, a % b);
        int x = P.first;
        int y = P.second;
        return make_pair(y, x - y*(a/b));
	}
}

int R[MAXN];


int main(int nargs, char **args) {
    ll a, b, p, x, m;
    cin >> a >> b >> p >> x;
    R[0] = 1;
    for (int i = 1; i < p; i++) {
        R[i] = (R[i-1]*a) % p;
    }

    ll ans = 0;
    for (int i = 1; i < p; i++) {
        pii ax = extended_GCD(R[i], p);
        if (ax.fi < 0) ax.fi += p, ax.se -= R[i];
        m = ax.fi*b % p;
        m = (m*i)/__gcd(m, (ll)i);
        ans += x/m;
    }
    cout << ans << endl;

    return 0;
}
