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


ll countOnes(ll n, ll c, int height) {
    ll ans = 0;

    while (height) {
        ll mid = (1LL<<(height - 1));
        if (c >= mid) {
            ans += n>>1;
            ans += (n&1);
            c -= mid;
        }
        n >>= 1;
        height--;
    }

    return ans;
}

int main(int nargs, char **args) {
    ll n, l, r, nc;
    cin >> n >> l >> r;

    nc = n; 
    int h = 0;
    while (nc) {
        nc >>= 1;
        h++;
    }

    cout << (countOnes(n, r, h) - countOnes(n, l - 1, h)) << endl;
    return 0;
}
