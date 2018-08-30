#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 100005

using namespace std;

int H[MAXN];

int main(int nargs, char **args) {
    int t, n, d, c;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d%d%d", &n, &d, &c);
        for (int i = 0; i < n; i++) {
            scanf("%d", &H[i]);
        }

        sort(H, H + n);
        long long ans = d*n;
        for (int i = 0; i < n; i++) {
            ans = min(ans, (long long)(n - i - 1)*d + (long long)(i+1)*(c*H[i]));
        }
        cout << "Case " << caso << ": " << ans << endl;
    }
    return 0;
}
