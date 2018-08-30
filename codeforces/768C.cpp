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
#define MAXN 1<<10

using namespace std;

int F[MAXN], XOR[MAXN], NF[MAXN];

int main(int nargs, char **args) {
    int n, k, x;
    cin >> n >> k >> x;

    for (int i = 0, y; i < n; i++) {
        cin >> y;
        F[y]++;
    }

    for (int i = 0; i < MAXN; i++) {
        XOR[i] = i^x;
    }

    while (k--) {
        memset(NF, 0, sizeof(NF));
        for (int i = 0, l = 0, tmp; i < MAXN; i++) {
            tmp = (F[i] - l + 1)>>1;
            NF[XOR[i]] += tmp;
            NF[i] += F[i] - tmp;
            l = (l + F[i])&1;
        }
        memcpy(F, NF, sizeof(F));
    }

    int mn = MAXN, mx = -1;
    for (int i = 0; i < MAXN; i++) {
        if (F[i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    cout << mx << " " << mn << endl;

    return 0;
}
