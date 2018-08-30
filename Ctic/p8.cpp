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
#define MAXN 10

using namespace std;

pii gcd(ll x, ll y) {
    if (y == 0) {
        return mp(1, 0);
    }

    pii g = gcd(y, x%y);
    return mp(g.se, g.fi - g.se*(x/y));
}

int main(int nargs, char **args) {
    int t;
    ll n1, f1, d1, n2, f2, d2;
    while (t--) {
        cin >> n1 >> f1 >> d1 >> n2 >> f2 >> d2;
        if (f1 < f2) {
            swap(n1, n2);
            swap(f1, f2);
            swap(d1, d2);
        }
        ll g = __gcd(d1, d2), f = f1 - f2, i, j, ans;
        if (f == 0) {
            i = d2/g;
            j = d1/g;
            if (i >= n1 || j >= n2) ans = 0;
            else ans = min((n1 - 1)/i, (n2 - 1)/j);
        } else {
            
        }
    }
    
    return 0;
}
