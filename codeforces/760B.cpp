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


using namespace std;

int n, m, k;

ll f(int l) {
    ll ans = n;
    ll b = min(l, n - k + 1);
    ans += (b*(b+1))/2;
    if (b < l) {
        ans += (l - b)*b;
    }

    b = min(l - 1, k - 1);
    ans += (b*(b+1))/2;
    if (b < l) {
        ans += (l - b - 1)*b;
    }

    return ans;
}

int main(int nargs, char **args) {
    cin >> n >> m >> k;

    // cout << f(3) << endl;
    int lo = 0, hi = (1<<30), mid;
    while (hi - lo > 1) {
        mid = (hi + lo)/2;
        if (f(mid) <= m) lo = mid;
        else hi = mid;
    }

    cout << hi << endl;

    return 0;
}
