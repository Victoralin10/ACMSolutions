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
#define MAXN 2003

using namespace std;

int n, m, k;
char M[MAXN][MAXN];


int main(int nargs, char **args) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", M[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, cnt = 0; j < m; j++) {
            if (M[i][j] == '.') {
                cnt++;
            } else cnt = 0;
            if (cnt >= k) ans++;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0, cnt = 0; i < n; i++) {
            if (M[i][j] == '.') {
                cnt++;
            } else cnt = 0;
            if (cnt >= k) ans++;
        }
    }
    if (k == 1) ans /= 2;

    cout << ans << endl;
    return 0;
}
