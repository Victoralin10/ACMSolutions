#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 10004

using namespace std;

pair <int, int> F[MAXN];
int A[MAXN];

int main(int nargs, char **args) {
    int t, m, n, c;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        memset(F, 0, sizeof F);
        scanf("%d%d%d", &m, &n, &c);

        for (int i = 1; i <= n; i++) {
            A[i] = (A[i-1] + 2*i - 1)%c;
            F[i] = make_pair(0, i);
        }

        for (int i = 0, x; i < m; i++) {
            cin >> x;
            F[x].first--;
        }

        sort(F + 1, F + n + 1);
        long long ans = 0;
        for (int i = 1, s = 0; i <= n; i++) {
            s += A[F[i].second];
            ans = max(ans, -(long long)s*F[i].first);
        }

        cout << "Case " << caso << ": " << ans << endl;
    }

    return 0;
}
