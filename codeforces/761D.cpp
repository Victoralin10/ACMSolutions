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

int A[MAXN], B[MAXN], C[MAXN];

int main(int nargs, char **args) {
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        C[x] = i;
    }

    ll mc = (1LL<<50);
    bool ok = 1;
    for (int i = n, b, ind; i > 0; i--) {
        ind = C[i];
        b = min(mc + A[ind], (ll)r);
        mc = b - A[ind] - 1;

        B[ind] = b;
        if (b < l) {
            ok = 0;
            break;
        }
    }

    if (ok) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", B[i], i+1==n?'\n':' ');
        }
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
