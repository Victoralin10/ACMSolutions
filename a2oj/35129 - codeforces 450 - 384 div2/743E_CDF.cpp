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
#define MAXN 1003

using namespace std;

int M[MAXN][1<<8], n;
int V[MAXN], PX[8][MAXN], L[8];

int bs(int val, int card) {
    int lo = 0, hi = L[card], mid;
    while (hi - lo > 1) {
        mid = (lo + hi)>>1;
        if (PX[card][mid] > val) hi = mid;
        else lo = mid;
    }
    return lo;
}

int dp(int cnt, int px, int mask) {
    int &dx = M[px][mask];
    if (dx != -1) return dx;
    if (px == n) {
        if (mask == 0 || cnt == 1) return 0;
        return -(1<<30);
    }
    dx = dp(cnt, px + 1, mask);
    int c = V[px];
    if (((1<<c)&mask) > 0) {
        int ipx = bs(px, c);
        if (ipx + cnt <= L[c]) {
            dx = max(dx, cnt + dp(cnt, PX[c][ipx + cnt - 1] + 1, mask^(1<<c)));
        }
        if (cnt > 1 && ipx + cnt - 1 <= L[c]) {
            dx = max(dx, cnt - 1 + dp(cnt, PX[c][ipx + cnt - 2] + 1, mask^(1<<c)));
        }
    }
    return dx;
}

int main(int nargs, char **args) {
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        x--;
        V[i] = x;
        PX[x][L[x]++] = i;
    }
    int lo = 1, hi = n/8 + 2, mid;
    while (hi - lo > 1) {
        mid = (hi + lo)/2;
        memset(M, -1, sizeof M);
        if (dp(mid, 0, 255) <= 0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    memset(M, -1, sizeof M);
    cout << dp(lo, 0, 255) << endl;
    return 0;
}
