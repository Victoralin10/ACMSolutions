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
#define MAXN 100005

using namespace std;

int A[MAXN];
ll AC[MAXN];

int main(int nargs, char **args) {
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        AC[i + 1] = AC[i] + A[i];
    }

    ll ans = 0;
    map <ll, int> mp;
    for (int i = 0; i <= n; i++) {
        if (abs(k) > 1) {
            for (ll pk = 1; abs(pk) <= 1e14; pk *= k) {
                if (mp.find(AC[i] - pk) != mp.end()) {
                    ans += mp[AC[i] - pk];
                }
            }
        } else {
            if (mp.find(AC[i] - 1) != mp.end()) {
                ans += mp[AC[i] - 1];
            }
            if (k == -1 && mp.find(AC[i] + 1) != mp.end()) {
                ans += mp[AC[i] + 1];
            }
        }
        mp[AC[i]]++;
    }
    cout << ans << endl;

    return 0;
}
