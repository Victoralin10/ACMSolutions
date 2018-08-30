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
#define MAXN 200005

using namespace std;

int n, A[MAXN], b = 0;
bool vis[MAXN];

void f(int px) {
    while (!vis[px]) {
        vis[px] = 1;
        px = A[px];
    }
}

int main(int nargs, char **args) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
    }

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b += x;
    }

    // memset(vis, 0, sizeof vis);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            f(i);
            cnt++;
        }
    }

    cout << (cnt>1?cnt:0) + (b%2 == 0) << endl;

    return 0;
}
