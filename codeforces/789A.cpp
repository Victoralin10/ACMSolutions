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

int main(int nargs, char **args) {
    int n, k, w;
    cin >> n >> k;

    int cntc = 0, cnti = 0;
    while (n--) {
        cin >> w;
        cntc += w/k;
        w %= k;
        cnti += w>0;
    }

    int ans = cntc/2 + cnti/2 + (((cntc&1) + (cnti&1)) > 0);
    cout << ans << endl;

    return 0;
}
