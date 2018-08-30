#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define EPS 1e-9

using namespace std;

int main(int nargs, char **args) {
    long double n, r, l;

    ll ans = 0;
    cin >> n >> l >> r;
    set <pair <int, pair <int, int> > > st;

    if (n == 1) {
        ans = r - l + 1;
    } else if (n == 2) {
        ans = (r - l + 1)*(r - l);
    } else {
        int r1 = floor(pow(r, 1.0/(n - 1.0)) + EPS);
        for (int g = 1; g <= r1; g++) {
            // cout << g << " " << l2 << " " << r2 << endl;
            for (int k1 = g + 1; k1 <= r1; k1++) {
                if (__gcd(g, k1) != 1) continue;

                int l2 = ceil(l/pow(g, n - 1) - EPS);
                int r2 = floor(r/pow(k1, n -1) + EPS);

                ans += max(0, r2 - l2 + 1);
            }
        }

        ans *= 2;
    }

    cout << ans << endl;

    return 0;
}
